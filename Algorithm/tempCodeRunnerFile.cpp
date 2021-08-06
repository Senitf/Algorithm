#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;
priority_queue<p> pq;
vector<p> v[300001];
int N, M, K, X, curIdx, curVal, nxtIdx, nxtVal, dist[300001], A, B, cnt, i;
bool chk[300001];
int main(){
    scanf("%d %d %d %d", &N, &M, &K, &X);
    while(M--){
        scanf("%d %d", &A, &B);
        v[A].push_back(make_pair(B, 1));
    }
    for(i = 1; i <= N; i++){
        dist[i] = INT_MAX;
    }
    dist[1] = 0;
    pq.push(make_pair(0, 1));
    while(!pq.empty()){
        curIdx = pq.top().second;
        curVal = pq.top().first;
        pq.pop();
        if(curVal != dist[curIdx])
            continue;
        for(i = 0; i < v[curIdx].size(); i++){
            nxtIdx = v[curIdx][i].first;
            nxtVal = v[curIdx][i].second;
            if(chk[nxtIdx] == false){
                chk[nxtIdx] = true;
                dist[nxtIdx] = curVal + nxtVal;
                pq.push(make_pair(dist[nxtIdx], nxtIdx));
            }
        }
    }
    for(i = 1; i <= N; i++){
        if(dist[i] == K){
            cnt++;
            printf("%d\n", i);
        }
    }
    if(cnt == 0)
        printf("-1\n");
}
