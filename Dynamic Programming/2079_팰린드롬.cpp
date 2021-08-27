#include <bits/stdc++.h>
using namespace std;
int chk[2001][2001], dp[2001], prev;
string s;
int main(){
    cin >> s;
    /*
    1. 한글자 팰린드롬 초기화
    2. 부분 팰린드롬 모두 찾기
    3. 최적의 팰린드롬 찾기
    */
    for(int i = 0; i < s.length(); i++){ // 한글자 팰린드롬 초기화
        chk[i][i] = 1;
    }
    for(int i = 2; i <= s.length(); i++){ // 파악할 범위
        for(int j = 0; j + i <= s.length(); j++){ // 시작점
            if(i == 2 || chk[j + 1][j + i - 2] == 1){ // 양 끝 문자를 제외한 범위의 문자열이 팰린드롬인 경우
                if(s[j] == s[j + i - 1]){ // 양 끝 문자 두개가 같아서 파악할 범위 전체가 팰린드롬인 경우
                    chk[j][j + i - 1] = 1; // 팰린드롬 처리
                    chk[j + i - 1][j] = 1;
                }
            }
        }
    }
    for(int i = 0; i < s.length(); i++){ // 끝 점 i
        for(int j = 0; j <= i; j++){ // 시작점 j
            if(chk[i][j]){ // 선택한 범위가 팰린드롬인 경우
                if(dp[i] == 0 || dp[i] > dp[j - 1] + 1) // 값을 수정한 적이 없거나, 선택한 범위 이전의 DP 값 + 선택한 범위의 DP + 1 이 더 최적의 경우인 경우 수정
                    dp[i] = dp[j - 1] + 1;
            }
        }
    }
    printf("%d\n", dp[int(s.length() - 1)]);
}