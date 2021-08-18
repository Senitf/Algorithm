#include <bits/stdc++.h>
using namespace std;
int chk[2001][2001], dp[2001], prev;
string s;
int main(){
    cin >> s;
    for(int i = 0; i < s.length(); i++){
        chk[i][i] = 1;
    }
    for(int i = 2; i <= s.length(); i++){
        for(int j = 0; j + i <= s.length(); j++){
            if(i == 2 || chk[j + 1][j + i - 2] == 1){
                if(s[j] == s[j + i - 1]){
                    chk[j][j + i - 1] = 1;
                    chk[j + i - 1][j] = 1;
                }
            }
        }
    }
    for(int i = 0; i < s.length(); i++){
        for(int j = 0; j <= i; j++){
            if(chk[i][j]){
                if(dp[i] == 0 || dp[i] > dp[j - 1] + 1)
                    dp[i] = dp[j - 1] + 1;
            }
        }
    }
    printf("%d\n", dp[int(s.length() - 1)]);
}