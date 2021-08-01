#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <climits>
using namespace std;
typedef pair<int,int> p;
vector<pair<int,int>> v[1001];
vector<int> ans1;
priority_queue<p, vector<p>, greater<>> pq;
int N, M, X, i, j, a, b, c, ans = -1, tmpans, curidx, curval, nxtidx, nxtval, dist[1001];
int main(){
    scanf("%d %d %d", &N, &M, &X);
    for(i = 0; i < M; i++){
        scanf("%d %d %d", &a, &b, &c);
        v[a].push_back(make_pair(b, c));
    }
    for(i = 1; i <= N; i++){
        for(j = 1; j <= N; j++){
            dist[j] = INT_MAX;
        }
        dist[i] = 0;
        pq.push(make_pair(0, i));
        while(!pq.empty()){
            curval = pq.top().first;
            curidx = pq.top().second;
            pq.pop();
            for(j = 0; j < v[curidx].size(); j++){
                nxtidx = v[curidx][j].first;
                nxtval = v[curidx][j].second;
                if(dist[nxtidx] > dist[curidx] + nxtval){
                    dist[nxtidx] = dist[curidx] + nxtval;
                    pq.push(make_pair(nxtval, nxtidx));
                }
            }
        }
        ans1.push_back(dist[X]);
    }
    for(i = 1; i <= N; i++){
        dist[i] = INT_MAX;
    }
    dist[X] = 0;
    pq.push(make_pair(0, X));
    while(!pq.empty()){
        curval = pq.top().first;
        curidx = pq.top().second;
        pq.pop();
        for(i = 0; i < v[curidx].size(); i++){
            nxtidx = v[curidx][i].first;
            nxtval = v[curidx][i].second;
            if(dist[nxtidx] > dist[curidx] + nxtval){
                dist[nxtidx] = dist[curidx] + nxtval;
                pq.push(make_pair(nxtval, nxtidx));
            }
        }
    }
    for(i = 1; i <= N; i++){
        if(ans < ans1[i - 1] + dist[i])
            ans = ans1[i - 1] + dist[i];
    }
    printf("%d\n", ans);
}
