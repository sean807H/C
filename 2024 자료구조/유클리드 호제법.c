#include<stdio.h>   // 책 버전
int euclidean(int num1, int num2){
    while(1){
        int temp = num2;
        num2 = num1 % num2;
        num1 = temp;
        if(num2 == 0) break;
    }
    return num1;
}
void main(){
    int answer = euclidean(78, 66);
    printf("%d \n", answer);
    return 0;
}