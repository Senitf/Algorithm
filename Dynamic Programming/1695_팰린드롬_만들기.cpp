#include <bits/stdc++.h>
using namespace std;
int N, arr[5001], dp[5001][5001];
int func(int a, int b){
    if(a == b || a > b)
        return 0;
    if(dp[a][b] != -1)
        return dp[a][b];
    if(arr[a] == arr[b]){
        return dp[a][b] = func(a + 1, b - 1);
    }
    else{
        return dp[a][b] = min(func(a + 1, b), func(a, b - 1)) + 1;
    }
    return dp[a][b];
}
int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &arr[i]);
    }
    memset(dp, -1, sizeof(dp));
    printf("%d\n", func(0, N - 1));
}