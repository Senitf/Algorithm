#include <bits/stdc++.h>
using namespace std;
priority_queue<char, vector<char>, greater<char> > pq, tmppq;
stack<char> st;
int arr[26], idx, flag;
string s;
int main(){
    cin >> s;
    for(int i = 0; i < s.length(); i++){
        idx = int(s[i] - 'A');
        arr[idx]++;
        if(arr[idx] == 2){
            pq.push(char(s[i]));
            arr[idx] -= 2;
        }
    }
    for(int i = 0; i < 26; i++){
        if(arr[i] > 0){
            flag++;
            tmppq.push(char('A' + i));
        }
    }
    if(flag > 1)
        printf("I'm Sorry Hansoo\n");
    else{
        while(!pq.empty()){
            printf("%c", pq.top());
            st.push(pq.top());
            pq.pop();
        }
        while(!tmppq.empty()){
            printf("%c", tmppq.top());
            tmppq.pop();
        }
        while(!st.empty()){
            printf("%c", st.top());
            st.pop();
        }
        printf("\n");
    }
}