#include <bits/stdc++.h>
#define INF 2e9 //INT_MAX 로 하면 오버플로우 때문에 오답처리됨
using namespace std;
double arr[16][16], v[65536][16];
int N, pointX, pointY;
typedef pair<int, int> p;
vector<p> vec;
double func(int visited, int cur){
    if(visited == (1 << N) - 1){ //모두 방문한 경우
        if(arr[cur][0] > 0) //처음으로 이어져 있는 경우
            return arr[cur][0];
        else //처음으로 이어져 있지 않은 경우
            return INF;
    }
    if(v[visited][cur] != -1) //이전에 이미 계산을 마쳐서 그대로 값만 가져와도 되는 경우
        return v[visited][cur];
    v[visited][cur] = INF; //처음 계산하는 것이므로 최대값으로 초기화 후에 진행
    for(int i = 0; i < N; i++){
        if(visited & (1 << i)) continue; //방문했던 곳이면 뛰어넘음
        if(arr[cur][i] == 0) continue; //연결되지 않았거나, 자기 자신인 경우 뛰어넘음
        v[visited][cur] = min(v[visited][cur], func(visited | (1 << i), i) + arr[cur][i]); //i번째 노드를 다음 목적지로 하는 경로와 이전에 계산한 v 값을 비교하여 더 작은 값으로 초기화
    }
    return v[visited][cur]; //모든 계산을 마친 후 main 으로 반환되는 값
}
int main(){
    scanf("%d", &N);
    for(int k = 0; k < N; k++){
        scanf("%d %d", &pointX, &pointY);
        vec.push_back(make_pair(pointX, pointY));
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            arr[i][j] = sqrt(pow(abs(vec[i].first - vec[j].first), 2) + pow(abs(vec[i].second - vec[j].second), 2));
        }
    }
    for(int i = 0; i < 65536; i++){
        for(int j = 0; j < 16; j++){
            v[i][j] = -1;
        }
    }
    //memset(v, -1, 1048576 * sizeof(double)); //값을 수정했는지 파악하기 위한 초기화
    printf("%.13lf\n", func(1, 0));
}