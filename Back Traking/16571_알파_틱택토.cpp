#include <bits/stdc++.h>
using namespace std;
int arr[3][3], zero, ans = -1;
bool check(int turn){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(arr[i][j] != turn)
                break;
            if(j == 2)
                return true;
        }
    }
    for(int j = 0; j < 3; j++){
        for(int i = 0; i < 3; i++){
            if(arr[i][j] != turn)
                break;
            if(i == 2)
                return true;
        }
    }
    for(int i = 0; i < 3; i++){
        if(arr[i][i] != turn)
            break;
        if(i == 2)
            return true;
    }
    for(int i = 0; i < 3; i++){
        if(arr[i][2 - i] != turn)
            break;
        if(i == 2)
            return true;
    }
    return false;
}
int func(int turn){
    if(turn == 1){
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
    if(minval == 2 || minval == 0)
        return 0;
    return -minval;
}
int main(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            scanf("%d", &arr[i][j]);
            if(arr[i][j] == 0)
                zero++;
        }
    }
    if(zero % 2 == 1)
        ans = func(1);
    else
        ans = func(2);
    if(ans == 1)
        printf("W\n");
    else if(ans == 0)
        printf("D\n");
    else
        printf("L\n");
}