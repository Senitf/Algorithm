#include <bits/stdc++.h>
#define INF 2e9
using namespace std;
int N, arr[1201], dist[1201], i, j;
int main(){
    scanf("%d", &N);
    for(i = 1; i <= N; i++){
        scanf("%d", &arr[i]);
        dist[i] = INF;
    }
    dist[1] = 0;
    for(i = 1; i <= N; i++){
        for(j = 1; j <= arr[i]; j++){
            if(dist[i + j] > dist[i] + 1){
                dist[i + j] = dist[i] + 1;
            }
        }
    }
    if(dist[N] == INF)
        printf("-1\n");
    else
        printf("%d\n", dist[N]);
}