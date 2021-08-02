#include <iostream>
#include <vector>
using namespace std;
vector<int> v[101];
int N, M, tmp1, tmp2, ans;
bool visit[101];
void dfs(int x){
    ans++;
    visit[x] = true;
    for(int i = 0; i < v[x].size(); i++){
        if(visit[v[x][i]] == false)
            dfs(v[x][i]);
    }
}
int main(){
    cin >> N >> M;
    while(M--){
        cin >> tmp1 >> tmp2;
        v[tmp1].push_back(tmp2);
        v[tmp2].push_back(tmp1);
    }
    dfs(1);
    cout << ans - 1 << '\n';
}
