#include <bits/stdc++.h>
using namespace std;
int N, dp[1010];
int main(){
    scanf("%d", &N);
    dp[1] = 1;
    dp[2] = -1;
    dp[3] = 1;
    dp[4] = -1;
    dp[5] = 1;
    for(int i = 6; i <= N; i++){
        dp[i] = -1;
        if(dp[i - 3] == -1 || dp[i - 1] == -1)
            dp[i] = 1;
    }
    if(dp[N] == 1)
        printf("SK\n");
    else
        printf("CY\n");
}