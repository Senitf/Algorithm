#include <bits/stdc++.h>
using namespace std;
int N, ans;
bool chk[17][17];
bool check(int y, int x){
    int nxtY, nxtX;
    for(int i = 0; i < x; i++){
        if(chk[y][i])
            return false;
        if(i != y && chk[i][x])
            return false;
    }
    for(int i = 0; i < y; i++){
        if(chk[i][x])
            return false;
    }
    for(int i = 1; i < N; i++){
        nxtY = y + (1 * i);
        nxtX = x + (-1 * i);
        if(nxtY >= 0 && nxtY < N && nxtX >= 0 && nxtX < N){
            if(chk[nxtY][nxtX])
                return false;
        }
        nxtY = y + (-1 * i);
        nxtX = x + (-1 * i);
        if(nxtY >= 0 && nxtY < N && nxtX >= 0 && nxtX < N){
            if(chk[nxtY][nxtX])
                return false;
        }
    }
    return true;
}
void func(int n){
    if(n == N){
        ans++;
        return;
    }
    for(int i = 0; i < N; i++){
        if(check(i, n)){
            chk[i][n] = true;
            func(n + 1);
            chk[i][n] = false;
        }
    }
}
int main(){
    scanf("%d", &N);
    func(0);
    printf("%d\n", ans);
}