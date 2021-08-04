#include <bits/stdc++.h>
using namespace std;
int N, E, a, b, c, i, j, N1, N2, curIdx, curVal, nxtIdx, nxtVal, dir1, dir2;
typedef pair<int, int> p;
priority_queue<int> pq;
vector<p> v[801];
int dist[801][3];
int main(){
    scanf("%d %d", &N, &E);
    for(i = 0; i < E; i++){
        scanf("%d %d %d", &a, &b, &c);
        v[a].push_back(make_pair(b, c));
        v[b].push_back(make_pair(a, c));
    }
    scanf("%d %d", &N1, &N2);
    for(i = 1; i < 801; i++){
        dist[i][0] = INT_MAX;
        dist[i][1] = INT_MAX;
        dist[i][2] = INT_MAX;
    }
    pq.push(1);
    dist[1][0] = 0;
    while(!pq.empty()){
        curIdx = pq.top();
        curVal = dist[curIdx][0];
        pq.pop();
        for(i = 0; i < v[curIdx].size(); i++){
            nxtIdx = v[curIdx][i].first;
            nxtVal = v[curIdx][i].second;
            if(curVal + nxtVal < dist[nxtIdx][0]){
                dist[nxtIdx][0] = curVal + nxtVal;
                pq.push(nxtIdx);
            }
        }
    }
    pq.push(N1);
    dist[N1][1] = 0;
    while(!pq.empty()){
        curIdx = pq.top();
        curVal = dist[curIdx][1];
        pq.pop();
        for(i = 0; i < v[curIdx].size(); i++){
            nxtIdx = v[curIdx][i].first;
            nxtVal = v[curIdx][i].second;
            if(curVal + nxtVal < dist[nxtIdx][1]){
                dist[nxtIdx][1] = curVal + nxtVal;
                pq.push(nxtIdx);
            }
        }
    }
    pq.push(N2);
    dist[N2][2] = 0;
    while(!pq.empty()){
        curIdx = pq.top();
        curVal = dist[curIdx][2];
        pq.pop();
        for(i = 0; i < v[curIdx].size(); i++){
            nxtIdx = v[curIdx][i].first;
            nxtVal = v[curIdx][i].second;
            if(curVal + nxtVal < dist[nxtIdx][2]){
                dist[nxtIdx][2] = curVal + nxtVal;
                pq.push(nxtIdx);
            }
        }
    }
    if(dist[N1][0] == INT_MAX || dist[N2][1] == INT_MAX || dist[N][2] == INT_MAX){
        dir1 = INT_MAX;
    }
    else{
        dir1 = dist[N1][0] + dist[N2][1] + dist[N][2];
    }
    if(dist[N2][0] == INT_MAX || dist[N2][1] == INT_MAX || dist[N][1] == INT_MAX){
        dir2 = INT_MAX;
    }
    else{
        dir2 = dist[N2][0] + dist[N2][1] + dist[N][1];
    }
    if(dir1 == INT_MAX && dir2 == INT_MAX){
        printf("-1\n");
    }
    else{
        printf("%d\n", min(dir1, dir2));
    }
}
