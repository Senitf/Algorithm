#include <bits/stdc++.h>
using namespace std;
priority_queue<int> pq[100001];
vector<string> name;
string tmp;
int flag, Q, k, C, b, idx, i, j;
long long ans;
int main(){
    scanf("%d", &Q);
    while(Q--){
        scanf("%d", &flag);
        if(flag == 1){
            cin >> tmp;
            idx = -1;
            for(i = 0; i < name.size(); i++){
                if(!tmp.compare(name[i])){
                    idx = i;
                }
            }
            if(idx == -1){
                name.push_back(tmp);
                idx = name.size() - 1;
            }
            scanf("%d", &k);
            while(k--){
                scanf("%d", &C);
                pq[idx].push(C);
            }
        }
        else{
            cin >> tmp;
            idx = -1;
            for(i = 0; i < name.size(); i++){
                if(!tmp.compare(name[i])){
                    idx = i;
                }
            }
            scanf("%d", &b);
            if(idx == -1)
                continue;
            while(!pq[idx].empty() && b--){
                ans += pq[idx].top();
                pq[idx].pop();
            }
        }
    }
    printf("%lld\n", ans);
}
