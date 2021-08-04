#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int TC, arr[101], ope[4];
long long maxAns = -1000000001, minAns = 1000000001;
void func(long long tmp, int idx){
    if (idx == TC - 1){
        if(tmp > maxAns){
            maxAns = tmp;
        }
        if(tmp < minAns){
            minAns = tmp;
        }
    }
    for(int i = 0; i < 4; i++){
        if(ope[i] > 0){
            if(i == 0){
                ope[i] -= 1;
                func(tmp + arr[idx + 1], idx + 1);
                ope[i] += 1;
            }
            else if(i == 1){
                ope[i] -= 1;
                func(tmp - arr[idx + 1], idx + 1);
                ope[i] += 1;
            }
            else if(i == 2){
                ope[i] -= 1;
                func(tmp * arr[idx + 1], idx + 1);
                ope[i] += 1;
            }
            else{
                ope[i] -= 1;
                func(tmp / arr[idx + 1], idx + 1);
                ope[i] += 1;
            }
        }
    }
    return;
}
int main(){
    scanf("%d", &TC);
    for(int i = 0; i < TC; i++){
        scanf("%d", &arr[i]);
    }
    for(int i = 0; i < 4; i++){
        scanf("%d", &ope[i]);
    }
    func(arr[0], 0);
    printf("%lld\n%lld\n", maxAns, minAns);
}

