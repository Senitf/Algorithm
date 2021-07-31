#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <climits>
using namespace std;
priority_queue<int, vector<int>, greater<int>> dist[1001];
queue<int> q;
int n, m, k, arr[1001][1001], a, b, c, cur, minDist, cnt, ans, top;
bool visit[1001];
int main(){
    for(int i = 1; i <= n; i++){
        visit[i] = false;
        for(int j = 1; j <= n; j++){
            arr[i][j] = INT_MAX;
        }
    }
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 0; i < m; i++){
        scanf("%d %d %d", &a, &b, &c);
        arr[a][b] = c;
    }
    q.push(1);
    dist[1]  = 0;
    while(!q.empty()){
        cur = q.front();
        q.pop();
        visit[cur] = true;
        for(int i = 1; i <= n; i++){
            if(arr[cur][i] != INT_MAX)
                pq[i].push(dist[cur] + arr[cur][i]);
            if(dist[cur] + arr[cur][i] < dist[i]){
                dist[i] = dist[cur] + arr[cur][i];
            }
        }
        minDist = INT_MAX;
        cur = -1;
        for(int i = 1; i <= n; i++){
            if(visit[i] == false && minDist > dist[i]){
                minDist = dist[i];
                cur = i;
            }
        }
        if(cur != -1)
            q.push(cur);
    }
    pq[0].push(1);
    pq[0].push(1);
    pq[0].push(1);
    for(int i = 1; i <= n; i++){
        while(!pq[i].empty()){
            top = pq[i].top();
            pq[i].pop();
            printf("%d ", top);
        }
        printf("\n");
    }
    return 0;
    for(int i = 1; i <= n; i++){
        cnt = k;
        cur = -1;
        while(!pq[i].empty()){
            top = pq[i].top();
            pq[i].pop();
            if(cur != top){
                cnt--;
                cur = top;
            }
            if(cnt == 0){
                ans = cur;
            }
        }
        if(cnt > 0)
            cur = -1;
        printf("%d\n", ans);
    }
}
