#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <climits>
using namespace std;
#define INF 123456789
int dist[501];
bool visit[501];
int N, M, S, D, U, V, P, cur, minDist, cnt;
queue<int> q;
int main(){
    while(true){
        scanf("%d %d", &N, &M);
        scanf("%d %d", &S, &D);
        if(N == 0 && M == 0)
            break;
        int v[501][501] = {0};
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                v[i][j] = INF;
            }
        }
        for(int i = 0; i < N; i++){
            dist[i] = INF;
            visit[i] = false;
        }
        for(int i = 0; i < M; i++){
            scanf("%d %d %d", &U, &V, &P);
            v[U][V] = P;
        }
        dist[S] = 0;
        cur = S;
        cnt = N;
        while(cnt--){
            visit[cur] = true;
            for(int i = 0; i < N; i++){
                if(dist[i] > dist[cur] + v[cur][i]){
                    dist[i] = dist[cur] + v[cur][i];
                }
            }
            minDist = INF;
            for(int i = 0; i < N; i++){
                if(visit[i] == false && minDist > dist[i]){
                    minDist = dist[i];
                    cur = i;
                }
            }
        }
        q.push(D);
        while(!q.empty()){
            cur = q.front();
            q.pop();
            for(int i = 0; i < N; i++){
                if(dist[i] + v[i][cur] == dist[cur]){
                    q.push(i);
                    v[i][cur] = INF;
                }
            }
        }
        for(int i = 0; i < N; i++){
            visit[i] = false;
            dist[i] = INF;
        }
        dist[S] = 0;
        cur = S;
        cnt = N;
        while(cnt--){
            visit[cur] = true;
            for(int i = 0; i < N; i++){
                if(dist[i] > dist[cur] + v[cur][i]){
                    dist[i] = dist[cur] + v[cur][i];
                }
            }
            minDist = INF;
            for(int i = 0; i < N; i++){
                if(visit[i] == false && minDist > dist[i]){
                    minDist = dist[i];
                    cur = i;
                }
            }
        }
        if(dist[D] == INF)
            printf("-1\n");
        else
            printf("%d\n", dist[D]);
    }
}
