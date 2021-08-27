#include <bits/stdc++.h>
using namespace std;
struct move{
    int mvx, mvy;
};
struct move mv[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int ans, tmpans, ttmpans;
char chk[5][5];
bool seven[5][5], visited[5][5];
queue<pair<int, int>> q;
string s;
bool check(){
    bool flag;
    int nxtX, nxtY, curX, curY, cnt;
    for(int y = 0; y < 5; y++){
        for(int x = 0; x < 5; x++){
            if(seven[y][x] == true){
                memset(visited, 0, sizeof(visited));
                cnt = 1;
                q.push(make_pair(y, x));
                visited[y][x] = true;
                while(!q.empty()){
                    curY = q.front().first;
                    curX = q.front().second;
                    q.pop();
                    for(int i = 0; i < 4; i++){
                        nxtY = curY + mv[i].mvy;
                        nxtX = curX + mv[i].mvx;
                        if(nxtY >= 0 && nxtY < 5 && nxtX >= 0 && nxtX < 5){
                            if(!visited[nxtY][nxtX] && seven[nxtY][nxtX]){
                                q.push(make_pair(nxtY, nxtX));
                                visited[nxtY][nxtX] = true;
                                cnt++;
                            }
                        }
                    }
                }
                if(cnt == 7)
                    return true;
                else
                    return false;
            }
        }
    }
    return false;
}
void func(int n, int lim, int y, int x){
    if(lim > 3){
        return;
    }
    if(n == 7){
        if(check()){ 
            ans++;
        }
        return;
    }
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(((i * 10) + j) > ((y * 10) + x) && seven[i][j] == false){
                seven[i][j] = true;
                if(chk[i][j] == 'Y')
                    func(n + 1, lim + 1, i, j);
                else
                    func(n + 1, lim, i, j);
                seven[i][j] = false;
            }
        }
    }
}
int main(){
    for(int i = 0; i < 5; i++){
        cin >> s;
        for(int j = 0; j < 5; j++){
            chk[i][j] = s[j];
        }
    }
    func(0, 0, -1, -1);
    printf("%d\n", ans);
}