#include<stdio.h>   // 재귀요청&호출
int factorid(int n){
    if(n==1) return 1;
    else
        return n*factorid(n-1);
}

int main(void){
    int n = 5;
    printf("%d! = %d \n",n,factorid(n));

    return 0;
}