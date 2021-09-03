#include <bits/stdc++.h>
using namespace std;
bool check(string s, int a, int b, int c){
    for(int i = a, j = b; i < a + c; i++, j++){
        if(s[i] != s[j])
            return false;
    }
    return true;
}
int solution(string s) {
    int answer = 1001, jStart, jEnd, cmpStart, cmpEnd, tmpAns;
    bool flag;
    for(int i = 1; i <= s.length() / 2; i++){
        tmpAns = 0;
        for(int j = 0; j < s.length(); j += i){
            jStart = j;
            jEnd = j + i - 1;
            cmpStart = jEnd + 1;
            cmpEnd = cmpStart + i - 1;
            flag = false;
            if(jEnd >= s.length()){
                tmpAns += s.length() - jStart;
                break;
            }
            while(true){
                if(cmpEnd >= s.length()){
                    cmpStart -= i;
                    break;
                }
                if(!check(s, jStart, cmpStart, i)){
                    break;
                }
                flag = true;
                cmpStart += i;
                cmpEnd += i;
            }
            if(flag == true){
                j = cmpStart - i;
                tmpAns += 1 + i;
            }
            else{
                tmpAns += i;
            }
        }
        
        if(tmpAns < answer){
            printf("%d\n", i);
            answer = tmpAns;
        }
    }
    return answer;
}
int main(){
    string s = "abcabc";
    printf("%d\n", solution(s));
}