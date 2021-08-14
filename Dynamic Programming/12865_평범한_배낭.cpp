#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;
int N, K, W, V, dp[100001], i, j;
vector<p> v;
int main(){
    scanf("%d %d", &N, &K);
    for(i = 0; i < N; i++){
        scanf("%d %d", &W, &V);
        v.push_back(make_pair(W, V));
    }
    for(j = 0; j < N; j++){ //물건들을 차례로 순회
        for(i = K; i >= 1; i--){ //가용한 무게를 최대에서 최소까지 순회
            if(v[j].first <= i) //가용한 무게가 물건의 무게를 감당 가능할 때만 진행
                dp[i] = max(dp[i], dp[i - v[j].first] + v[j].second);
                /*
                기존의 가용한 무게가 i 일 때, 가치의 최대 값과,
                현재 물건을 담을 만큼 여유공간이 있는 상태에서의 최대값을 
                비교하여 더 큰 값으로 수정
                */
        }
    }
    printf("%d\n", dp[K]); //가용한 무게가 K 일때의 최대 가치를 출력
}