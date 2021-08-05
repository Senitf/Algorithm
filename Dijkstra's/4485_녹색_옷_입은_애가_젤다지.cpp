#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;
struct move{
    int y, x;
};
struct move mv[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
queue<p> q;
int N, i, j, arr[127][127], dist[127][127], curY, curX, curVal, nxtVal, nxtY, nxtX, TC;
int main(){
    while(true){
        TC++;
        scanf("%d", &N);
        if(N == 0)
            break;
        for(i = 1; i <= N; i++){
            for(j = 1; j <= N; j++){
                scanf("%d", &arr[i][j]);
                dist[i][j] = INT_MAX;
            }
        }
        dist[1][1] = arr[1][1];
        q.push(make_pair(1, 1));
        while(!q.empty()){
            curY = q.front().first;
            curX = q.front().second;
            curVal = dist[curY][curX];
            q.pop();
            for(i = 0; i < 4; i++){
                nxtY = curY + mv[i].y;
                nxtX = curX + mv[i].x;
                nxtVal = dist[nxtY][nxtX];
                if(nxtY >= 1 && nxtY <= N && nxtX >= 1 && nxtX <= N){
                    if(curVal + arr[nxtY][nxtX] < nxtVal){
                        dist[nxtY][nxtX] = curVal + arr[nxtY][nxtX];
                        q.push(make_pair(nxtY, nxtX));
                    }
                }
            }
        }
        printf("Problem %d: %d\n", TC, dist[N][N]);
    }
}