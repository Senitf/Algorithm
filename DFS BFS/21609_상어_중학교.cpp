#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>
using namespace std;
typedef pair<int, int> p;
struct move{
    int x, y;
};
struct move mv[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
queue<p> q;
int N, M, arr[22][22], delX, delY;
bool rain[22][22];
int scan(){
    int i, j, k, target, tmpAns, ans = 1, curX, curY, nxtX, nxtY, tmpRain, rain = 0;
    bool visit[22][22] = {0};
    for(i = 1; i <= N; i++){
        for(j = 1; j <= N; j++){
            for(int k = 1; k <= N; k++){
                for(int l = 1; l <= N; l++){
                    if(arr[k][l] == 0)
                        visit[k][l] = false;
                }
            }
            if(arr[i][j] > 0 && !visit[i][j]){
                target = arr[i][j];
                q.push(make_pair(i, j));
                visit[i][j] = true;
                tmpAns = 1;
                tmpRain = 0;
                while(!q.empty()){
                    curY = q.front().first;
                    curX = q.front().second;
                    q.pop();
                    for(k = 0; k < 4; k++){
                        nxtY = curY + mv[k].y;
                        nxtX = curX + mv[k].x;
                        if(nxtX >= 1 && nxtX <= N && nxtY >= 1 && nxtY <= N){
                            if(visit[nxtY][nxtX] == false){
                                if(arr[nxtY][nxtX] == 0 || arr[nxtY][nxtX] == target){
                                    q.push(make_pair(nxtY, nxtX));
                                    visit[nxtY][nxtX] = true;
                                    tmpAns++;
                                    if(arr[nxtY][nxtX] == 0)
                                        tmpRain++;
                                }
                            }
                        }
                    }
                }
                if(ans < tmpAns){
                    ans = tmpAns;
                    delY = i;
                    delX = j;
                    rain = tmpRain;
                }
                else if(ans == tmpAns){
                    if(rain <= tmpRain){
                        ans = tmpAns;
                        delY = i;
                        delX = j;
                        rain = tmpRain;
                    }
                }
            }
        }
    }
    return ans;
}
void scanDel(){
    int curX, curY, nxtX, nxtY, target, i;
    bool visit[22][22] = {0};
    target = arr[delY][delX];
    q.push(make_pair(delY, delX));
    visit[delY][delX] = true;
    arr[delY][delX] = -2;
    while(!q.empty()){
        curY = q.front().first;
        curX = q.front().second;
        q.pop();
        for(i = 0; i < 4; i++){
            nxtY = curY + mv[i].y;
            nxtX = curX + mv[i].x;
            if(nxtX >= 1 && nxtX <= N && nxtY >= 1 && nxtY <= N){
                if(visit[nxtY][nxtX] == false){
                    if(arr[nxtY][nxtX] == 0 || arr[nxtY][nxtX] == target){
                        q.push(make_pair(nxtY, nxtX));
                        visit[nxtY][nxtX] = true;
                        arr[nxtY][nxtX] = -2;
                    }
                }
            }
        }
    }
}
void spin(){
    int i, j, copy[22][22];
    for(i = 1 ; i <= N; i++){
        for(j = 1; j <= N; j++){
            copy[i][j] = arr[i][j];
        }
    }
    for(i = 1 ; i <= N; i++){
        for(j = 1; j <= N; j++){
            arr[N - j + 1][i] = copy[i][j];
        }
    }
}
void gravity(){
    int i, j, swapY, tmp;
    for(i = N; i >= 1; i--){
        for(j = 1; j <= N; j++){
            if(arr[i][j] >= 0){
                swapY = i + 1;
                while(arr[swapY][j] == -2){
                    swapY++;
                }
                swapY -= 1;
                tmp = arr[swapY][j];
                arr[swapY][j] = arr[i][j];
                arr[i][j] = tmp;
            }
        }
    }

}
int main(){
    int i, j, ans = 0, tmpAns;
    scanf("%d %d", &N, &M);
    for(i = 1; i <= N; i++){
        for(j = 1; j <= N; j++){
            scanf("%d", &arr[i][j]);
            if(arr[i][j] == 0){
                rain[i][j] = true;
            }
        }
    }
    while(true){
        tmpAns = -1;
        tmpAns = scan();
        if(tmpAns == 1)
            break;
        scanDel();
        ans += (tmpAns * tmpAns);
        gravity();
        spin();
        gravity();
    }
    printf("%d\n", ans);
}
