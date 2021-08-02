#include <bits/stdc++.h>
using namespace std;
double ans1, ans2 = 0;
int N, M, K, i, j;
double func(int x){
    double tmp = 1;
    for(i = 1; i <= x; i++){
        tmp *= i;
    }
    return tmp;
}
double cfunc(int x, int y){
    return func(x) / (func(x - y) * func(y));
}
int main(){
    scanf("%d %d %d", &N, &M, &K);
    ans1 = cfunc(N, M);
    for(j = K; j <= M; j++){
        if(M - j < N - M)
            ans2 += cfunc(M, j) * cfunc(N-M, M-j);
    }
    printf("%0.16lf\n", ans2 / ans1);
}
