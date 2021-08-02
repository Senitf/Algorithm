#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;
struct move{
    int mvX;
    int mvY;
};
struct move mv[4] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
priority_queue<p> pq;
int N, M, arr[22][22], i, j, delx, dely, tmpScore, tmpX, tmpY, tmpScan, score, grav, tmpRain, ansRain = -1;
bool chk(int x, int y){
    bool tmp = false;
    int nxtX, nxtY, k;
    for(k = 0; k < 4; k++){
        nxtX = x + mv[k].mvX;
        nxtY = y + mv[k].mvY;
        if(nxtX > 0 && nxtX <= N && nxtY > 0 && nxtY <= N){
            if(arr[nxtY][nxtX] == 0 || arr[nxtY][nxtX] == arr[y][x]){
                tmp = true;
            }
        }
    }
    return tmp;
}
int scan(int x, int y){
    int curX, curY, nxtX, nxtY, returnScore = 1, k;
    int visit[22][22] = {0};
    pq.push(make_pair(x, y));
    visit[y][x] = 1;
    while(!pq.empty()){
        curX = pq.top().first;
        curY = pq.top().second;
        pq.pop();
        for(k = 0; k < 4; k++){
            nxtX = curX + mv[k].mvX;
            nxtY = curY + mv[k].mvY;
            if(nxtX > 0 && nxtX <= N && nxtY > 0 && nxtY <= N){
                if(visit[nxtY][nxtX] == 0){
                    if(arr[nxtY][nxtX] == 0 || arr[nxtY][nxtX] == arr[y][x]){
                        if(arr[nxtY][nxtX] == 0)
                            tmpRain++;
                        visit[nxtY][nxtX] = 1;
                        pq.push(make_pair(nxtX, nxtY));
                        returnScore++;
                    }
                }
            }
        }
    }
    return returnScore;
}
void scan_del(int x, int y){
    int curX, curY, nxtX, nxtY, returnScore = 0, k, target;
    int visit[22][22] = {0};
    target = arr[y][x];
    pq.push(make_pair(x, y));
    visit[y][x] = 1;
    arr[y][x] = -2;
    while(!pq.empty()){
        curX = pq.top().first;
        curY = pq.top().second;
        pq.pop();
        for(k = 0; k < 4; k++){
            nxtX = curX + mv[k].mvX;
            nxtY = curY + mv[k].mvY;
            if(nxtX > 0 && nxtX <= N && nxtY > 0 && nxtY <= N){
                if(visit[nxtY][nxtX] == 0){
                    if(arr[nxtY][nxtX] == 0 || arr[nxtY][nxtX] == target){
                        visit[nxtY][nxtX] = 1;
                        pq.push(make_pair(nxtX, nxtY));
                        arr[nxtY][nxtX] = -2;
                    }
                }
            }
        }
    }
}
void spin(){
    int copy[22][22] = {0};
    for(j = N; j >= 1; j--){
        for(i = 1; i <= N; i++){
            copy[abs(j - N - 1)][i] = arr[i][j];
        }
    }
    for(i = 1; i <= N; i++){
        for(j = 1; j <= N; j++){
            arr[i][j] = copy[i][j];
        }
    }
}
void gravity(){
    int nxtX, nxtY, curX, curY, tmp;
    for(i = N - 1; i >= 1; i--){
        for(j = 1; j <= N; j++){
            if(arr[i][j] >= 0){
                curY = i;
                nxtY = i + 1;
                while(nxtY <= N && arr[nxtY][j] == -2){
                    curY += 1;
                    nxtY += 1;
                }
                tmp = arr[i][j];
                arr[i][j] = arr[curY][j];
                arr[curY][j] = tmp;
            }
        }
    }
}
int main(){
    scanf("%d %d", &N, &M);
    for(i = 1; i <= N; i++){
        for(j = 1; j <= N; j++)
            scanf("%d", &arr[i][j]);
    }
    while(true){
        tmpScore = -1;
        ansRain = -1;
        for(i = 1; i <= N; i++){
            for(j = 1; j <= N; j++){
                if(arr[i][j] > 0 && chk(j, i)){
                    tmpRain = 0;
                    tmpScan = scan(j, i);
                    if(tmpScan >= tmpScore){
                        if(tmpScan == tmpScore){
                            if(ansRain > tmpRain)
                                continue;
                        }
                        tmpScore = tmpScan;
                        ansRain = tmpRain;
                        tmpX = j;
                        tmpY = i;
                    }
                }
            }
        }
        if(tmpScore == -1)
            break;
        score += (tmpScore * tmpScore);
        scan_del(tmpX, tmpY);
        gravity();
        spin();
        gravity();
    }
    printf("%d\n", score);
}