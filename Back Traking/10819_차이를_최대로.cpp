#include <bits/stdc++.h>
using namespace std;
int N, arr[8], calc[8], ans;
bool chk[8];
void func(int n){
    if(n == N){
        int tmp, tmpAns = 0;
        for(int i = 0; i < N - 1; i++){
            tmpAns += abs(calc[i] - calc[i + 1]);
        }
        if(tmpAns > ans)
            ans = tmpAns;
    }
    for(int i = 0; i < N; i++){
        if(chk[i] == false){
            chk[i] = true;
            calc[n] = arr[i];
            func(n + 1);
            chk[i] = false;
        }
    }
}
int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &arr[i]);
    }
    func(0);
    printf("%d\n", ans);
}