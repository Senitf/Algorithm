#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;
int N, K, W, V, dp[100001], i, j;
vector<p> v;
int main(){
    scanf("%d %d", &N, &K);
    for(i = 0; i < N; i++){
        scanf("%d %d", &W, &V);
        v.push_back(make_pair(W, V));
    }
    for(j = 0; j < N; j++){
        for(i = K; i >= 1; i--){
            if(v[j].first <= i)
                dp[i] = max(dp[i], dp[i - v[j].first] + v[j].second);
        }
    }
    printf("%d\n", dp[K]);
}