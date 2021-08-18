#include <bits/stdc++.h>
using namespace std;
int N, dp[301], arr[301];
int main(){
    scanf("%d", &N);
    for(int i = 1; i <= N; i++){
        scanf("%d", &arr[i]);
    }
    dp[1] = arr[1];
    dp[2] = arr[1] + arr[2];
    for(int i = 3; i <= N; i++){
        dp[i] = max(dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i]);
    }
    printf("%d\n", dp[N]);
}