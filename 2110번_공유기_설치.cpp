#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int N, C, arr[200001], minD, maxD, midD, preD, cnt, ans;
int main(){
    scanf("%d %d", &N, &C);
    for(int i = 0; i < N; i++){
        scanf("%d", &arr[i]);
    }
    sort(arr, arr + N);
    minD = 1;
    maxD = arr[N - 1] - arr[0];
    while(minD <= maxD){
        midD = (maxD + minD) / 2;
        cnt = 1;
        preD = arr[0];
        for(int i = 1; i < N; i++){
            if(arr[i] - preD >= midD){
                preD = arr[i];
                cnt++;
            }
        }
        if(cnt >= C){
            ans = midD;
            minD = midD + 1;
        }
        else{
            maxD = midD - 1;
        }
    }
    printf("%d\n", ans);
}
