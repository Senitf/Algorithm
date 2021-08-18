#include <bits/stdc++.h>
using namespace std;
string s1, s2;
int dp[1001][1001];
char c1[1001], c2[1001];
int main(){
    cin >> s1 >> s2;
    for(int i = 0; i < s1.length(); i++){
        c1[i + 1] = s1[i];
    }
    for(int i = 0; i < s2.length(); i++){
        c2[i + 1] = s2[i];
    }
    for(int i = 0; i <= s1.length(); i++){
        for(int j = 0; j <= s2.length(); j++){
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else if(c1[i] == c2[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    printf("%d\n", dp[s1.length()][s2.length()]);
}