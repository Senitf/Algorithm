#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;
struct move{
    int y, x;
};
struct move mv[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
queue<p> q;
int N, i, j, arr[52][52], dist[52][52], curY, curX, curVal, nxtVal, nxtY, nxtX;
string s;
int main(){
    scanf("%d", &N);
    for(i = 1; i <= N; i++){
        cin >> s;
        for(j = 1; j <= N; j++){
            if(s[j - 1] == '1')
                arr[i][j] = 1;
            else
                arr[i][j] = 0;
            dist[i][j] = INT_MAX;
        }
    }
    dist[1][1] = 0;
    q.push(make_pair(1, 1));
    while(!q.empty()){
        curY = q.front().first;
        curX = q.front().second;
        curVal = dist[curY][curX];
        q.pop();
        for(i = 0; i < 4; i++){
            nxtY = curY + mv[i].y;
            nxtX = curX + mv[i].x;
            if(nxtY >= 1 && nxtY <= N && nxtX >= 1 && nxtX <= N){
                if(arr[nxtY][nxtX] == 1)
                    nxtVal = 0;
                else
                    nxtVal = 1;
                if(curVal + nxtVal < dist[nxtY][nxtX]){
                    dist[nxtY][nxtX] = curVal + nxtVal;
                    q.push(make_pair(nxtY, nxtX));
                }
            }
        }
    }
    printf("%d\n", dist[N][N]);
}
