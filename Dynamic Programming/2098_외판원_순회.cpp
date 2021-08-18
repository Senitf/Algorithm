#include <bits/stdc++.h>
#define INF 1e9
using namespace std;
int arr[16][16], N, v[65536][16];
int func(int visited, int cur){
    if(visited == (1 << N) - 1){ //모두 방문했고 다시 처음으로 돌아갈 수 있는 경우
        if(arr[cur][0] > 0) //처음으로 이어져 있는 경우
            return arr[cur][0];
        else //처음으로 이어져 있지 않은 경우
            return INF;
    }
    if(v[visited][cur] != -1) //이전에 이미 계산을 마쳐서 그대로 값만 가져와도 되는 경우
        return v[visited][cur];
    v[visited][cur] = INF;
    for(int i = 0; i < N; i++){
        if(visited & (1 << i)) continue; //방문했던 곳이면 뛰어넘음
        if(arr[cur][i] == 0) continue; //연결되지 않으면 뛰어넘음
        v[visited][cur] = min(v[visited][cur], func(visited | (1 << i), i) + arr[cur][i]);
        //i번째 노드를 다음 목적지로 하는 경로와 이전에 계산한 v 값을 비교하여 더 작은 값으로 초기화
    }
    return v[visited][cur]; //모든 계산을 마친 후 main 으로 반환되는 값
}
int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    memset(v, -1, sizeof(v)); //값을 수정했는지 파악하기 위한 초기화
    printf("%d\n", func(1, 0));
}