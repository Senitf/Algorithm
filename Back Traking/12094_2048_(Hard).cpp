#include <bits/stdc++.h>
using namespace std;
int N, arr[22][22], maxAns, arrAns[11];
int moveRight(){
    int flag = 0;
    bool chk[22][22] = {0};
    for(int i = 1; i <= N; i++){
        for(int k = N - 1; k >= 1; k--){
            if(arr[i][k] == 0) continue;
            int j = k;
            while(j != N){
                if(arr[i][j + 1] == 0){
                    arr[i][j + 1] = arr[i][j];
                    arr[i][j] = 0;
                    flag = 1;
                }
                else if(arr[i][j] == arr[i][j + 1] && chk[i][j + 1] == false && chk[i][j] == false){
                    arr[i][j + 1] *= 2;
                    arr[i][j] = 0;
                    flag = 1;
                    chk[i][j + 1] = true;
                }
                else{
                    break;
                }
                j++;
            }
        }
    }
    if(flag == 0)
        return -1;
    else
        return 1;
}
int moveLeft(){
    int flag = 0;
    bool chk[22][22] = {0};
    for(int i = 1; i <= N; i++){
        for(int k = 2; k <= N; k++){
            if(arr[i][k] == 0) continue;
            int j = k;
            while(j != 1){
                if(arr[i][j - 1] == 0){
                    arr[i][j - 1] = arr[i][j];
                    arr[i][j] = 0;
                    flag = 1;
                }
                else if(arr[i][j] == arr[i][j - 1] && chk[i][j - 1] == false && chk[i][j] == false){
                    arr[i][j - 1] *= 2;
                    arr[i][j] = 0;
                    flag = 1;
                    chk[i][j - 1] = true;
                }
                else{
                    break;
                }
                j--;
            }
        }
    }
    if(flag == 0)
        return -1;
    else
        return 1;
}
int moveUpper(){
    int flag = 0;
    bool chk[22][22] = {0};
    for(int k = 2; k <= N; k++){
        for(int j = 1; j <= N; j++){
            if(arr[k][j] == 0) continue;
            int i = k;
            while(i != 1){
                if(arr[i - 1][j] == 0){
                    arr[i - 1][j] = arr[i][j];
                    arr[i][j] = 0;
                    flag = 1;
                }
                else if(arr[i][j] == arr[i - 1][j] && chk[i - 1][j] == false && chk[i][j] == false){
                    arr[i - 1][j] *= 2;
                    arr[i][j] = 0;
                    flag = 1;
                    chk[i - 1][j] = true;
                }
                else{
                    break;
                }
                i--;
            }
        }
    }
    if(flag == 0)
        return -1;
    else
        return 1;
}
int moveLower(){
    int flag = 0;
    bool chk[22][22] = {0};
    for(int k = N - 1; k >= 1; k--){
        for(int j = 1; j <= N; j++){
            if(arr[k][j] == 0) continue;
            int i = k;
            while(i != N){
                if(arr[i + 1][j] == 0){
                    arr[i + 1][j] = arr[i][j];
                    arr[i][j] = 0;
                    flag = 1;
                }
                else if(arr[i][j] == arr[i + 1][j] && chk[i + 1][j] == false && chk[i][j] == false){
                    arr[i + 1][j] *= 2;
                    arr[i][j] = 0;
                    flag = 1;
                    chk[i + 1][j] = true;
                }
                else
                    break;
                i++;
            }
        }
    }
    if(flag == 0)
        return -1;
    else
        return 1;
}
void func(int cnt){
    int tmpArr[22][22] = {0}, tmpAns = 0;
    for(int i = 1; i <= N; i++){ //움직이고 나서 나중에 다시 돌아오기 위한 배열 기록
        for(int j = 1; j <= N; j++){
            tmpArr[i][j] = arr[i][j];
            if(tmpAns < arr[i][j])
                tmpAns = arr[i][j];
        }
    }
    if(maxAns < tmpAns) //최댓값 갱신
            maxAns = tmpAns;
    if(cnt == 10){
        return;
    }
    if(tmpAns * pow(2, 10 - cnt) <= maxAns) //아주 운좋게 계속 커지더라도 주어진 횟수 안에 최댓값 갱신을 할 수 없는 경우
        return;
    for(int i = 0; i < 4; i++){
        for(int k = 1; k <= N; k++){
            for(int j = 1; j <= N; j++){
                arr[k][j] = tmpArr[k][j];
            }
        }
        switch (i)
        {
        case 0:
            tmpAns = moveRight();
            break;
        case 1:
            tmpAns = moveLeft();
            break;
        case 2:
            tmpAns = moveUpper();
            break;
        case 3:
            tmpAns = moveLower();
            break;
        default:
            break;
        }
        if(tmpAns == -1){ //어떤 블럭도 움직이지 않은 경우
            continue;
        }
        func(cnt + 1);
    }
}
int main(){
    scanf("%d", &N);
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    func(0);
    printf("%d\n", maxAns);
}