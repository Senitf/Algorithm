#include <bits/stdc++.h>
using namespace std;
int arr[3][3], zero, ans = -1;
bool check(int turn){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(arr[i][j] != turn)
                break;
            if(j == 2)
                return true; //가로줄이 같은 경우
        }
    }
    for(int j = 0; j < 3; j++){
        for(int i = 0; i < 3; i++){
            if(arr[i][j] != turn)
                break;
            if(i == 2)
                return true; //세로줄이 같은 경우
        }
    }
    for(int i = 0; i < 3; i++){
        if(arr[i][i] != turn)
            break;
        if(i == 2)
            return true; //대각선
    }
    for(int i = 0; i < 3; i++){
        if(arr[i][2 - i] != turn)
            break;
        if(i == 2)
            return true; //대각선
    }
    return false; //게임이 안끝난 경우
}
int func(int turn){
    if(turn == 1){ //턴에 맞춰서 체크를 하고, 만약 게임이 끝났을 경우 -1 을 반환, -1을 반환해야 min 함수에 걸려서 -1이 정상적으로 넘어감
        if(check(2)) return -1;
    }
    else{
        if(check(1))
            return -1;
    }
    int minval = 2;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(arr[i][j] == 0){
                arr[i][j] = turn;
                if(turn == 1)
                    minval = min(minval, func(2));
                else
                    minval = min(minval, func(1));
                arr[i][j] = 0;
            }
        }
    }
    if(minval == 2 || minval == 0) //승부가 나지 않은 경우
        return 0;
    return -minval; //-를 붙여줌으로써, 리턴값이 거슬로 올라오며 -1, 1 을 번갈아가며 반환하게 됨
}
int main(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            scanf("%d", &arr[i][j]);
            if(arr[i][j] == 0) //빈칸의 개수로 턴을 계산함
                zero++;
        }
    }
    if(zero % 2 == 1)
        ans = func(1);
    else
        ans = func(2);
    if(ans == 1) //승리
        printf("W\n");
    else if(ans == 0) //무승부
        printf("D\n");
    else //패배
        printf("L\n");
}