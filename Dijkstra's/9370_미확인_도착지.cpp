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
        while(m--){ //간선 정보 입력
            scanf("%d %d %d", &a, &b, &c);
            tmp = c * 2; //모든 간선의 가중치를 짝수로 수정
            if((a == g && b == h) || (a == h && b == g)){ //문제에서 주어진 특정 경로만 홀수로 수정
                tmp = tmp - 1;
            }
            v[a].push_back(make_pair(b, tmp));
            v[b].push_back(make_pair(a, tmp));
        }
        for(i = 1; i <= n; i++){
            dist[i] = INT_MAX / 2 * 2; //INT_MAX 는 홀수 이므로 짝수로 바꿔 저장
            chk[i] = false; //모든 노드를 방문하지 않은 것으로 체크
        }
        dist[s] = 0;
        pq.push(s); //시작점 초기화
        while(!pq.empty()){ //다익스트라 시작
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
        for(i = 1; i <= n; i++){ //측정된 거리가 홀수면 중간에 "그 경로"가 섞인 것이므로 체크, 미방문 노드도 INT_MAX 이므로 짝수임
            if(dist[i] % 2 == 1){
                chk[i] = true;
            }
        }
        while(t--){
            scanf("%d", &tmp);
            ans.push_back(tmp);
        }
        sort(ans.begin(), ans.end());
        for(i = 0; i < ans.size(); i++){ //결과 출력
            if(chk[ans[i]] == true)
                printf("%d ", ans[i]);
        }
        printf("\n");
    }
}