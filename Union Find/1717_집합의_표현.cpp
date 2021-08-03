#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, op, a, b;
int parent[1000001];
int DSrank[1000001];
int DSfind(int u) {
    if(parent[u] == u)
        return u;
    return parent[u] = DSfind(parent[u]);
}
void DSunion(int u, int v) {
    u = DSfind(u);
    v = DSfind(v);
    if(u == v)
        return;
    if(DSrank[u] > DSrank[v])
        swap(u, v);
    parent[u] = v;
    if(DSrank[u] == DSrank[v]) DSrank[v]++;
}
int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i <= n; i++){
        parent[i] = i;
        DSrank[i] = 1;
    }
    while(m--){
        scanf("%d %d %d", &op, &a, &b);
        if(op == 0){
            DSunion(a, b);
        }
        else{
            if(DSfind(a) == DSfind(b))
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
}
