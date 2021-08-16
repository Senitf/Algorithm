#include <bits/stdc++.h>
using namespace std;
int N, r, c, dp[501][501], tmp;
typedef pair<int, int> p;
vector<p> v;
int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d %d", &r, &c);
        v.push_back(make_pair(r, c));
    }
    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            if (i == j)
                dp[i][j] = 0;
            else if(i + 1 == j)
                dp[i][j] = v[i].first * v[i].second * v[j].second;
            else
                dp[i][j] = INT_MAX;
        }
    }
    for(int i = 2; i < N; i++){
        for(int j = 0; j + i < N; j++){
            for(int k = j; k < j + i; k++){
                tmp = v[j].first * v[k].second * v[j + i].second;
                dp[j][j + i] = min(dp[j][j + i], dp[j][k] + dp[k + 1][j + i] + tmp);
            }
        }
    }
    printf("%d\n", dp[0][N - 1]);
}