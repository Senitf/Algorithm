#include <bits/stdc++.h>
using namespace std;
int dp[100001][2], arr[100001], n, i, ans = 0;
int main(){
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    dp[0][0] = arr[0];
    dp[0][1] = arr[0];
    ans = arr[0];
    for(i = 1; i < n; i++){
        dp[i][0] = max(dp[i - 1][0] + arr[i], arr[i]);
        dp[i][1] = max(dp[i - 1][1] + arr[i], dp[i - 1][0]);
        ans = max(ans, max(dp[i][0], dp[i][1]));
    }
    printf("%d\n", ans);
}