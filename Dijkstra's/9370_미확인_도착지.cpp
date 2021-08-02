#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;
priority_queue<int> pq;
int T, n, m, t, s, g, h, a, b, c, dist[2001], i, j, curidx, curval, nxtidx, nxtval, tmp;
bool chk[2001];
int main(){
    scanf("%d", &T);
    while(T--){
        vector<p> v[2001];
        vector<int> ans;
        scanf("%d %d %d", &n, &m, &t);
        scanf("%d %d %d", &s, &g, &h);
        while(m--){
            scanf("%d %d %d", &a, &b, &c);
            tmp = c * 2;
            if((a == g && b == h) || (a == h && b == g)){
                tmp = tmp - 1;
            }
            v[a].push_back(make_pair(b, tmp));
            v[b].push_back(make_pair(a, tmp));
        }
        for(i = 1; i <= n; i++){
            dist[i] = INT_MAX / 2 * 2;
            chk[i] = false;
        }
        dist[s] = 0;
        pq.push(s);
        while(!pq.empty()){
            curidx = pq.top();
            curval = dist[curidx];
            pq.pop();
            for(i = 0; i < v[curidx].size(); i++){
                nxtidx = v[curidx][i].first;
                nxtval = v[curidx][i].second;
                if(dist[nxtidx] > curval + nxtval){
                    dist[nxtidx] = curval + nxtval;
                    pq.push(nxtidx);
                }
            }
        }
        for(i = 1; i <= n; i++){
            if(dist[i] % 2 == 1){
                chk[i] = true;
            }
        }
        while(t--){
            scanf("%d", &tmp);
            ans.push_back(tmp);
        }
        sort(ans.begin(), ans.end());
        for(i = 0; i < ans.size(); i++){
            if(chk[ans[i]] == true)
                printf("%d ", ans[i]);
        }
        printf("\n");
    }
}