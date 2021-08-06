#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;
queue<int> q;
vector<int> v[300001];
int N, M, K, X, curIdx, nxtIdx, dist[300001], A, B, cnt, i;
bool chk[300001];
int main(){
    scanf("%d %d %d %d", &N, &M, &K, &X);
    while(M--){
        scanf("%d %d", &A, &B);
        v[A].push_back(B);
    }
    for(i = 1; i <= N; i++){
        dist[i] = INT_MAX;
        chk[i] = false;
    }
    dist[X] = 0;
    chk[X] = true;
    q.push(X);
    while(!q.empty()){
        curIdx = q.front();
        q.pop();
        for(i = 0; i < v[curIdx].size(); i++){
            nxtIdx = v[curIdx][i];
            if(chk[nxtIdx] == false){
                chk[nxtIdx] = true;
                dist[nxtIdx] = dist[curIdx] + 1;
                if(dist[nxtIdx] == K)
                    cnt++;
                q.push(nxtIdx);
            }
        }
    }
    if(cnt == 0)
        printf("-1\n");
    else{
        for(i = 1; i <= N; i++){
            if(dist[i] == K)
                printf("%d\n", i);
        }
    }
}
