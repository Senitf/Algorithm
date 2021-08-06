#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;
priority_queue<p> pq;
queue<int> q;
vector<p> v[1001], vBack[1001];
vector<int> ans;
int n, m, dist[1001], root[1001], i, j, a, b, c, s, d, curIdx, nxtIdx, curVal, nxtVal;
int main(){
    scanf("%d %d", &n, &m);
    for(i = 0; i < m; i++){
        scanf("%d %d %d", &a, &b, &c);
        v[a].push_back(make_pair(b, c));
        vBack[b].push_back(make_pair(a, c));
    }
    scanf("%d %d", &s, &d);
    for(i = 1; i <= n; i++){
        dist[i] = INT_MAX;
    }
    dist[s] = 0;
    pq.push(make_pair(0, s));
    while(!pq.empty()){
        curIdx = pq.top().second;
        curVal = pq.top().first;
        pq.pop();
        if(curVal != dist[curIdx])
            continue;
        for(i = 0; i < v[curIdx].size(); i++){
            nxtIdx = v[curIdx][i].first;
            nxtVal = v[curIdx][i].second;
            if(curVal + nxtVal < dist[nxtIdx]){
                dist[nxtIdx] = curVal + nxtVal;
                root[nxtIdx] = curIdx;
                pq.push(make_pair(dist[nxtIdx], nxtIdx));
            }
        }
    }
    printf("%d\n", dist[d]);
    curIdx = d;
    ans.push_back(curIdx);
    while(curIdx != s){
        nxtIdx = root[curIdx];
        ans.push_back(nxtIdx);
        curIdx = nxtIdx;
    }
    reverse(ans.begin(), ans.end());
    printf("%d\n", int(ans.size()));
    for(i = 0; i < ans.size(); i++){
        printf("%d ", ans[i]);
    }
    printf("\n");
}
