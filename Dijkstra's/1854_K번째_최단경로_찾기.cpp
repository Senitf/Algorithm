#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <climits>
using namespace std;
priority_queue<int> dist[1001];
priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int, int> > pq;
vector<pair<int, int> > v[1001];
int n, m, k, a, b, c, i, cur, val;
int main(){
    scanf("%d %d %d", &n, &m, &k);
    for(i = 0; i < m; i++){
        scanf("%d %d %d", &a, &b, &c);
        v[a].push_back(make_pair(b, c));
    }
    pq.push(make_pair(1, 0));
    dist[1].push(0);
    while(!pq.empty()){
        cur = pq.top().first;
        val = pq.top().second;
        pq.pop();
        for(i = 0; i < v[cur].size(); i++){
            if(dist[v[cur][i].first].size() < k){
                dist[v[cur][i].first].push(val + v[cur][i].second);
                pq.push(make_pair(v[cur][i].first, val + v[cur][i].second));
            }
            else if(dist[v[cur][i].first].top() > val + v[cur][i].second){
                dist[v[cur][i].first].pop();
                dist[v[cur][i].first].push(val + v[cur][i].second);
                pq.push(make_pair(v[cur][i].first, val + v[cur][i].second));
            }
        }
    }
    for(i = 1; i <= n; i++){
        if(dist[i].size() == k){
            printf("%d\n", dist[i].top());
        }
        else{
            printf("-1\n");
        }
    }
}
