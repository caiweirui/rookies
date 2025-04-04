// 输入：调度算法

// 　　　进程号/到达时间/运行时间/优先级/时间片

// 输出：调度顺序/进程号/开始运行时间/结束运行时间/优先级

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;

struct process {
    int pid;        // 进程号
    int comeTime;   // 到达时间
    int runTime;    // 运行所需时间
    int beginTime;  // 开始运行的时间
    int endTime;    // 结束运行的时间
    int order;      // 调度顺序
    int priority;   // 优先级
    int slot;       // 时间片
    int finish;     // 结束标志
} que[1010];

void FCFS();  // 先来先服务
void SJF();   // 不可剥夺的短作业优先算法
void SRTF();  // 可剥夺式短作业优先算法
void RR();    // 时间片轮转
void DPSA();  // 动态优先级调度

bool cmp1(process, process); // FCFS、RR、DPSA 比较函数
bool cmp2(process, process); // SJF、SRTF 比较函数

int num;   // 进程总数
const int IsEnd = 1;  // 进程已结束
const int NoEnd = 0;  // 进程未结束

int main() {
    int sig = 0;
    cin >> sig;  // 选择算法

    num = 0;
    while (~scanf("%d/%d/%d/%d/%d", &que[num].pid, &que[num].comeTime, &que[num].runTime, &que[num].priority, &que[num].slot)) {
        que[num].beginTime = que[num].endTime = que[num].order = 0;
        que[num].finish = NoEnd;
        num++;
    }

    // 根据输入选择调度算法
    switch (sig) {
        case 1: FCFS(); break;
        case 2: SJF(); break;
        case 3: SRTF(); break;
        case 4: RR(); break;
        case 5: DPSA(); break;
    }

    return 0;
}

void FCFS() {
    sort(que, que + num, cmp1); // 按到达时间排序
    for (int i = 0; i < num; i++) {
        que[i].order = i + 1;
        que[i].beginTime = (i == 0) ? que[i].comeTime : max(que[i].comeTime, que[i - 1].endTime);
        que[i].endTime = que[i].beginTime + que[i].runTime;

        printf("%d/%d/%d/%d/%d\n", que[i].order, que[i].pid, que[i].beginTime, que[i].endTime, que[i].priority);
    }
}

void SJF() {
    sort(que, que + num, cmp2); // 按运行时间排序
    int lastTime = que[0].comeTime;
    int tmp = 0;
    for (int i = 0; i < num; i++) {
        bool isBool = false;
        while (1) {
            if (i == 0) break; // 第一个进程特判
            for (int j = 1; j < num; j++) {
                if (que[j].finish == IsEnd) continue;
                if (que[j].comeTime <= lastTime) {
                    if (!isBool) { isBool = true; tmp = j; }
                    else if (que[j].runTime < que[tmp].runTime || (que[j].runTime == que[tmp].runTime && que[j].pid < que[tmp].pid)) tmp = j;
                }
            }
            if (isBool) break;
            else lastTime++;
        }
        que[tmp].order = i + 1;
        que[tmp].beginTime = max(que[tmp].beginTime, lastTime);
        que[tmp].endTime = que[tmp].beginTime + que[tmp].runTime;
        printf("%d/%d/%d/%d/%d\n", que[tmp].order, que[tmp].pid, que[tmp].beginTime, que[tmp].endTime, que[tmp].priority);

        lastTime = que[tmp].endTime;
        que[tmp].finish = IsEnd;
    }
}

void SRTF()
{
	sort(que, que + num, cmp2);
	int lastTime = que[0].comeTime;
	int ID = 1;//输出顺序 
	int tmp = 0, counts = 0;//当前进程，输出次数 
	int isRun = -1, start = 0;//当前是否有进程运行,运行开始时间 
	while (counts < num)
	{
		while (que[tmp].comeTime <= lastTime && tmp < num)//当前时间内的进程 
		{
			tmp++;
		}
		int minx = 0x3f3f3f, minId = -1;//最短时间和下标 
		for (int i = 0; i < tmp; i++)//寻找当前进程中剩余运行时间最短的进程 
		{
			if (que[i].runTime < minx && que[i].finish == NoEnd)
			{
				minx = que[i].runTime;
				minId = i;
			}
		}
		if (minId == -1)//如果当前时间进程都结束了就等待下一个进程 
		{
			lastTime = que[tmp].comeTime;
			continue;
		}
		if (isRun == -1)//当前没有进程在运行 
		{
			isRun = minId;
			start = max(que[isRun].comeTime, lastTime);//运行刚找到的进程 
		}
		//如果找到进程的剩余运行时间小于当前进程的剩余运行时间 
		if (que[minId].runTime < que[isRun].runTime)
		{
			que[isRun].order = ID++;
			que[isRun].beginTime = start;
			que[isRun].endTime = lastTime;
			printf("%d/%d/%d/%d/%d\n", que[isRun].order, que[isRun].pid, que[isRun].beginTime, que[isRun].endTime, que[isRun].priority);
			isRun = minId;
			start = lastTime;
		}
		//运行进程 
		int run = que[tmp].comeTime - lastTime;
		//进程能运行完就运行完 
		if (run >= que[isRun].runTime || run <= 0)
		{
			lastTime += que[isRun].runTime;
			que[isRun].order = ID++;
			que[isRun].beginTime = start;
			que[isRun].endTime = lastTime;
			printf("%d/%d/%d/%d/%d\n", que[isRun].order, que[isRun].pid, que[isRun].beginTime, que[isRun].endTime, que[isRun].priority);

			que[isRun].runTime = 0;
			que[isRun].finish = IsEnd;
			counts++;
			isRun = -1;
			start = lastTime;
		}
		//进程不能运行完就运行一个时间片 
		else
		{
			lastTime += run;
			que[isRun].runTime -= run;
		}
	}
}

void RR() {
    sort(que, que + num, cmp1); // 按到达时间排序
    queue<process> q;
    int lastTime = 0, ID = 1, tmp = 0, counts = 0;
    while (counts < num) {
        if (q.empty()) {
            lastTime = que[tmp].comeTime;
            while (que[tmp].comeTime <= lastTime && tmp < num) {
                if (que[tmp].finish == NoEnd) q.push(que[tmp]);
                tmp++;
            }
        } else {
            process ans = q.front(); q.pop();
            if (ans.runTime <= ans.slot) {
                ans.order = ID++;
                ans.beginTime = lastTime;
                ans.endTime = ans.beginTime + ans.runTime;
                printf("%d/%d/%d/%d/%d\n", ans.order, ans.pid, ans.beginTime, ans.endTime, ans.priority);

                lastTime = ans.endTime;
                ans.finish = IsEnd;
                counts++;

                while (que[tmp].comeTime <= lastTime && tmp < num) {
                    if (que[tmp].finish == NoEnd) q.push(que[tmp]);
                    tmp++;
                }
            } else {
                ans.order = ID++;
                ans.beginTime = lastTime;
                ans.endTime = ans.beginTime + ans.slot;
                printf("%d/%d/%d/%d/%d\n", ans.order, ans.pid, ans.beginTime, ans.endTime, ans.priority);

                lastTime = ans.endTime;
                ans.runTime -= ans.slot;

                while (que[tmp].comeTime <= lastTime && tmp < num) {
                    if (que[tmp].finish == NoEnd) q.push(que[tmp]);
                    tmp++;
                }
                q.push(ans);
            }
        }
    }
}

void DPSA() {
    sort(que, que + num, cmp1); // 按到达时间排序
    int lastTime = que[0].comeTime, ID = 1, tmp = 0, counts = 0, start = lastTime, minId, Smin;
    while (counts < num) {
        while (que[tmp].comeTime <= lastTime && tmp < num) {
            if (que[tmp].comeTime > start && que[tmp].comeTime < lastTime)
                que[tmp].priority = max(que[tmp].priority - 1, 0);
            tmp++;
        }

        minId = -1; Smin = 0x3f3f3f;
        for (int i = 0; i < tmp; i++) {
            if (que[i].priority < Smin && que[i].finish == NoEnd) {
                Smin = que[i].priority;
                minId = i;
            }
        }

        if (minId == -1) { lastTime = que[tmp].comeTime; continue; }

        start = lastTime;
        if (que[minId].runTime <= que[minId].slot) {
            que[minId].order = ID++;
            que[minId].beginTime = lastTime;
            que[minId].endTime = lastTime + que[minId].runTime;
            printf("%d/%d/%d/%d/%d\n", que[minId].order, que[minId].pid, que[minId].beginTime, que[minId].endTime, que[minId].priority + 3);

            counts++;
            lastTime += que[minId].runTime;
            que[minId].finish = IsEnd;
        } else {
            que[minId].order = ID++;
            que[minId].beginTime = lastTime;
            que[minId].endTime = lastTime + que[minId].slot;
            printf("%d/%d/%d/%d/%d\n", que[minId].order, que[minId].pid, que[minId].beginTime, que[minId].endTime, que[minId].priority + 3);

            lastTime += que[minId].slot;
            que[minId].runTime -= que[minId].slot;
        }

        for (int i = 0; i < tmp; i++) {
            if (que[i].finish == NoEnd) {
                if (i == minId) que[i].priority += 3;
                else que[i].priority = max(que[i].priority - 1, 0);
            }
        }
    }
}

bool cmp1(process a, process b) {
    return a.comeTime != b.comeTime ? a.comeTime < b.comeTime : a.pid < b.pid;
}

bool cmp2(process a, process b) {
    if (a.comeTime != b.comeTime) return a.comeTime < b.comeTime;
    return a.runTime != b.runTime ? a.runTime > b.runTime : a.pid < b.pid;
}
