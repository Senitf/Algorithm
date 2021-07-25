#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int TC, li[10001], tmp;
    long long ans = 0;
    scanf("%d", &TC);
    for(int i = 0; i < TC; i++){
        scanf("%d", &li[i]);
    }
    sort(li, li + TC);
    for(int i = 0; i < TC - 2; i++){
        for(int j = i + 1; j < TC - 1; j++){
            tmp = -1 * (li[i] + li[j]);
            ans += (upper_bound(li + j + 1, li + TC, tmp)) - (lower_bound(li + j + 1, li + TC, tmp));
        }
    }
    printf("%lld\n", ans);
}

