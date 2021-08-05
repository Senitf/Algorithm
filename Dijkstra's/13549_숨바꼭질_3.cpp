#include <bits/stdc++.h>
using namespace std;
int N, K, ansTime = 100001, curIdx, curTime;
typedef pair<int, int> p;
priority_queue<p, vector<p>, greater<p> > pq;
bool visit[100001];
int main(){
    scanf("%d %d", &N, &K);
    pq.push(make_pair(0, N));
    visit[N] = true;
    while(!pq.empty()){
        curIdx = pq.top().second;
        curTime = pq.top().first;
        pq.pop();
        if(curIdx == K && curTime < ansTime)
            ansTime = curTime;
        if(curIdx * 2 < 100001 && visit[curIdx * 2] == false){
            pq.push(make_pair(curTime, curIdx * 2));
            visit[curIdx * 2] = true;
        }
        if(curIdx + 1 < 100001 && visit[curIdx + 1] == false){
            pq.push(make_pair(curTime + 1, curIdx + 1));
            visit[curIdx + 1] = true;
        }
        if(curIdx - 1 >= 0 && visit[curIdx - 1] == false){
            pq.push(make_pair(curTime + 1, curIdx - 1));
            visit[curIdx - 1] = true;
        }
    }
    printf("%d\n", ansTime);
}