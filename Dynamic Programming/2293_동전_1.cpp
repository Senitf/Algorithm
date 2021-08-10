#include <bits/stdc++.h>
using namespace std;
int dp[100001], n, k, i, j, tmp;
vector<int> v;
int main(){
    scanf("%d %d", &n, &k);
    for(i = 0; i < n; i++){
        scanf("%d", &tmp);
        v.push_back(tmp);
    }
    for(i = 0; i < v.size(); i++){
        dp[v[i]]++;
        for(j = 1; j <= k; j++){
            if(j - v[i] > 0)    
                dp[j] += dp[j - v[i]];
        }
    }
    printf("%d\n", dp[k]);
}