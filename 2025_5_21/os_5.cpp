#include<cstdio>
#include<cstdlib>
#include<algorithm>

#define MAX_SIZE 65535

using namespace std;

enum diskScheduleAlg {_FCFS = 1, _SSTF, _SCAN, _CSCAN};     
enum taskState {UNFINISHED, FINISHED};                      

struct dSeekTask {                                          
    int track;                                             
    int distance;                                           
    taskState state;                                        
} tasks[MAX_SIZE];                                          
int sTable[MAX_SIZE];                                       
int taskNum;                                                
int totalTracks;                                            

void FCFS();                                                
void SSTF();                                                
void SCAN(int mvDirection);                                 
void CSCAN(int mvDirection);                                
int getDistance(int x, int y);                              
void output();                                             

int main() {
    int algNum;
    int position;
    int direction;
    taskNum = 0;
    totalTracks = 0;
    scanf("%d %d %d", &algNum, &position, &direction);
    sTable[0] = position;
    char tmpChar;
    while (scanf("%d", &tasks[taskNum].track)) {
        tasks[taskNum].distance = MAX_SIZE;
        tasks[taskNum].state = UNFINISHED;
        taskNum++;
        tmpChar = getchar();
        if (tmpChar == ',') continue;
        else if (tmpChar == '\n') break;
    }
    switch (algNum) {
        case _FCFS: FCFS(); break;
        case _SSTF: SSTF(); break;
        case _SCAN: SCAN(direction); break;
        case _CSCAN: CSCAN(direction); break;
    }
    output();
    return 0;
}
int getDistance(int x, int y) {
    return abs(x-y);
}
void FCFS() {
    for (int i = 0; i < taskNum; i++) {
        sTable[i+1] = tasks[i].track;
        tasks[i].state = FINISHED;
        totalTracks += getDistance(sTable[i], tasks[i].track);
    }
}
void SSTF() {
    for (int i = 1; i <= taskNum; i++) {
        int minDis = MAX_SIZE;
        int tmpDis = MAX_SIZE;
        int tag = 0;
        for (int j = 0; j < taskNum; j++) {
            if (tasks[j].state == UNFINISHED) {
                tmpDis = getDistance(sTable[i-1], tasks[j].track);
                if (tmpDis < minDis) {
                    minDis = tmpDis;
                    tag = j;
                }
            }
        }
        sTable[i] = tasks[tag].track;
        tasks[tag].state = FINISHED;
        totalTracks += minDis;
    }
}
void SCAN(int mvDirection) {
    if (mvDirection == 0) {
        sort(tasks, tasks + taskNum, [] (dSeekTask a, dSeekTask b) { return a.track < b.track; });
    } else if (mvDirection == 1) {
        sort(tasks, tasks + taskNum, [] (dSeekTask a, dSeekTask b) { return a.track > b.track; });
    }
    int tag = 0;
    for (int i = 0; i < taskNum; i++) {
        if (mvDirection==0 && tasks[i].track > sTable[0]) {
            tag = i;
            break;
        } else if (mvDirection==1 && tasks[i].track < sTable[0]) {
            tag = i;
            break;
        }
    }
    int sTag = 0;
    for (int i = tag - 1; i >= 0; i--) {
        sTable[sTag+1] = tasks[i].track;
        tasks[i].state = FINISHED;
        totalTracks += getDistance(sTable[sTag], tasks[i].track);
        sTag++;
    }
    for (int i = tag; i < taskNum; i++) {
        sTable[sTag+1] = tasks[i].track;
        tasks[i].state = FINISHED;
        totalTracks += getDistance(sTable[sTag], tasks[i].track);
        sTag++;
    }
}
void CSCAN(int mvDirection) {
    if (mvDirection == 0) {
        sort(tasks, tasks + taskNum, [] (dSeekTask a, dSeekTask b) { return a.track < b.track; });
    } else if (mvDirection == 1) {
        sort(tasks, tasks + taskNum, [] (dSeekTask a, dSeekTask b) { return a.track > b.track; });
    }
    int tag = 0;
    for (int i = 0; i < taskNum; i++) {
        if (mvDirection==0 && tasks[i].track > sTable[0]) {
            tag = i;
            break;
        } else if (mvDirection==1 && tasks[i].track < sTable[0]) {
            tag = i;
            break;
        }
    }
    int sTag = 0;
    for (int i = tag - 1; i >= 0; i--) {
        sTable[sTag+1] = tasks[i].track;
        tasks[i].state = FINISHED;
        totalTracks += getDistance(sTable[sTag], tasks[i].track);
        sTag++;
    }
    for (int i = taskNum - 1; i >= tag; i--) {
        sTable[sTag+1] = tasks[i].track;
        tasks[i].state = FINISHED;
        totalTracks += getDistance(sTable[sTag], tasks[i].track);
        sTag++;
    }
}
void output() {
    for (int i = 0; i < taskNum; i++) {
        printf("%d,", sTable[i]);
    }
    printf("%d\n", sTable[taskNum]);
    printf("%d\n", totalTracks);
}