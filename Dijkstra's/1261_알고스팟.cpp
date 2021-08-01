#include <iostream>
#include <algorithm> //sort
#include <string> //string
#include <vector> //vector
#include <stack> //stack
#include <queue> //queue
#include <cmath> //abs
#include <climits> //MAX_INT
#include <tuple> //tuple
using namespace std;
typedef pair<int, int> p;
priority_queue<p, vector<p>, greater<>> pq;
struct mv{
    int mvX;
    int mvY;
};
const mv mov[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int arr[102][102], N, M, dist[102][102], i, j, curi, curj, nxti, nxtj, curval, nxtval;
char tmp;
int main(){
    scanf("%d %d", &M, &N);
    for(i = 1; i <= N; i++){
        for(j = 1; j <= M; j++){
            scanf("%c", &tmp);
            if(tmp == '\n')
                scanf("%c", &tmp);
            if(tmp == '0')
                arr[i][j] = 0;
            else
                arr[i][j] = 1;
            dist[i][j] = INT_MAX;
        }
    }
    dist[1][1] = 0;
    pq.push(make_pair(1, 1));
    while(!pq.empty()){
        curi = pq.top().first;
        curj = pq.top().second;
        curval = dist[curi][curj];
        pq.pop();
        for(i = 0; i < 4; i++){
            nxti = curi + mov[i].mvY;
            nxtj = curj + mov[i].mvX;
            nxtval = dist[nxti][nxtj];
            if(nxti > 0 && nxti <= N && nxtj <= M && nxtj > 0){
                if(dist[nxti][nxtj] > dist[curi][curj] + arr[nxti][nxtj]){
                    dist[nxti][nxtj] = dist[curi][curj] + arr[nxti][nxtj];
                    pq.push(make_pair(nxti, nxtj));
                }
            }
        }
    }
    printf("%d\n", dist[N][M]);
}
