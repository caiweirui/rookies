#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_BLOCKS 100
#define MAX_PAGES 1000
#define MAX_LEN 32

typedef struct {
    int empty;            // 1 if empty, 0 otherwise
    int id;               // insertion or update timestamp
    char idx[MAX_LEN];    // page identifier
    int next;             // next use index
} Page;

typedef struct {
    Page pages[MAX_BLOCKS];
    int blockCount;
    int currentCount;
    int nextId;
} Memory;

// 初始化内存结构
void initMemory(Memory *m, int blocks) {
    m->blockCount = blocks;
    m->currentCount = 0;
    m->nextId = 0;
    for (int i = 0; i < blocks; i++) {
        m->pages[i].empty = 1;
        m->pages[i].id = 0;
        strcpy(m->pages[i].idx, "-");
        m->pages[i].next = INT_MAX;
    }
}

int isFull(Memory *m) {
    return m->currentCount == m->blockCount;
}

// 检查是否命中
int contains(Memory *m, const char *val) {
    for (int i = 0; i < m->blockCount; i++) {
        if (!m->pages[i].empty && strcmp(m->pages[i].idx, val) == 0)
            return 1;
    }
    return 0;
}

// 添加到空闲块（按块号从小到大）
void addPage(Memory *m, const char *val) {
    m->currentCount++;
    for (int i = 0; i < m->blockCount; i++) {
        if (m->pages[i].empty) {
            m->pages[i].empty = 0;
            m->pages[i].id = m->nextId++;
            strncpy(m->pages[i].idx, val, MAX_LEN-1);
            m->pages[i].idx[MAX_LEN-1] = '\0';
            break;
        }
    }
}

// FIFO 替换
void fifoReplace(Memory *m, const char *val) {
    int minId = INT_MAX, idx = 0;
    for (int i = 0; i < m->blockCount; i++) {
        if (m->pages[i].id < minId) {
            minId = m->pages[i].id;
            idx = i;
        }
    }
    m->pages[idx].id = m->nextId++;
    strncpy(m->pages[idx].idx, val, MAX_LEN-1);
    m->pages[idx].idx[MAX_LEN-1] = '\0';
    m->pages[idx].empty = 0;
}

// 计算 OPT 替换前向最近使用
void searchNext(Memory *m, char seq[][MAX_LEN], int seqLen, int start) {
    for (int i = 0; i < m->blockCount; i++) {
        m->pages[i].next = INT_MAX;
    }
    for (int i = 0; i < m->blockCount; i++) {
        for (int j = start + 1; j < seqLen; j++) {
            if (strcmp(m->pages[i].idx, seq[j]) == 0) {
                m->pages[i].next = j;
                break;
            }
        }
    }
}

// OPT 替换
void optReplace(Memory *m, const char *val) {
    int farIdx = 0;
    int farthest = INT_MIN;
    for (int i = 0; i < m->blockCount; i++) {
        if (m->pages[i].next > farthest) {
            farthest = m->pages[i].next;
            farIdx = i;
        }
    }
    if (farthest == INT_MAX) {
        int minId = INT_MAX;
        for (int i = 0; i < m->blockCount; i++) {
            if (m->pages[i].next == INT_MAX && m->pages[i].id < minId) {
                minId = m->pages[i].id;
                farIdx = i;
            }
        }
    }
    m->pages[farIdx].id = m->nextId++;
    strncpy(m->pages[farIdx].idx, val, MAX_LEN-1);
    m->pages[farIdx].idx[MAX_LEN-1] = '\0';
    m->pages[farIdx].empty = 0;
}

// LRU 替换: 满时移除第一个有效页，末尾插入新页
void lruReplace(Memory *m, const char *val) {
    // 因为满，所以 currentCount == blockCount
    for (int i = 0; i < m->blockCount - 1; i++) {
        m->pages[i] = m->pages[i + 1];
    }
    // 插入到最后
    m->pages[m->blockCount - 1].empty = 0;
    m->pages[m->blockCount - 1].id = m->nextId++;
    strncpy(m->pages[m->blockCount - 1].idx, val, MAX_LEN-1);
    m->pages[m->blockCount - 1].idx[MAX_LEN-1] = '\0';
}

// LRU 命中后移到最后一个有效页位置
void toLast(Memory *m, const char *val) {
    int pos = -1;
    for (int i = 0; i < m->blockCount; i++) {
        if (!m->pages[i].empty && strcmp(m->pages[i].idx, val) == 0) {
            pos = i;
            break;
        }
    }
    if (pos < 0) return;
    Page temp = m->pages[pos];
    int cnt = m->currentCount;
    for (int i = pos; i < cnt - 1; i++) {
        m->pages[i] = m->pages[i + 1];
    }
    m->pages[cnt - 1] = temp;
}

// 打印当前内存及命中标志
void printStep(Memory *m, int hit) {
    for (int i = 0; i < m->blockCount; i++) {
        printf("%s", m->pages[i].empty ? "-" : m->pages[i].idx);
        if (i + 1 < m->blockCount) printf(",");
    }
    printf(",%d", hit);
}

int main() {
    int method, blocks;
    scanf("%d %d", &method, &blocks);
    getchar(); // 吃掉换行

    char line[4096];
    fgets(line, sizeof(line), stdin);
    int seqLen = 0;
    char seq[MAX_PAGES][MAX_LEN];
    char *token = strtok(line, ",\n");
    while (token && seqLen < MAX_PAGES) {
        strncpy(seq[seqLen], token, MAX_LEN-1);
        seq[seqLen][MAX_LEN-1] = '\0';
        seqLen++;
        token = strtok(NULL, ",\n");
    }

    Memory mem;
    initMemory(&mem, blocks);
    int misses = 0;

    for (int i = 0; i < seqLen; i++) {
        int hit = contains(&mem, seq[i]);
        if (hit) {
            if (method == 3)
                toLast(&mem, seq[i]);
        } else {
            misses++;
            if (!isFull(&mem)) {
                addPage(&mem, seq[i]);
            } else {
                if (method == 1) {
                    searchNext(&mem, seq, seqLen, i);
                    optReplace(&mem, seq[i]);
                } else if (method == 2) {
                    fifoReplace(&mem, seq[i]);
                } else {
                    lruReplace(&mem, seq[i]);
                }
            }
        }
        printStep(&mem, hit);
        if (i + 1 < seqLen) printf("/");
    }
    printf("\n%d\n", misses);
    return 0;
}
