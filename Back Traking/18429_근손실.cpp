#include <bits/stdc++.h>
using namespace std;
int N, K, tmp, arr[51], ans;
bool chk[51];
void func(int day, int weight){
    if(day == N){
        if(weight >= 500)
            ans++;
        return;
    }
    for(int i = 0; i < N; i++){
        if(chk[i] == false && weight - K + arr[i] >= 500){
            chk[i] = true;
            func(day + 1, weight - K + arr[i]);
            chk[i] = false;
        }
    }
}
int main(){
    scanf("%d %d", &N, &K);
    for(int i = 0; i < N; i++){
        scanf("%d", &arr[i]);
    }
    func(0, 500);
    printf("%d\n", ans);
}