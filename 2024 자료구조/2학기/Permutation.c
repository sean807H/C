#include <stdio.h>
#define R 5
int b[R], cnt = 0;
//b 출력
void printPer(void){
	int i;
	for(i=0;i<R; i++){
		printf("%5d",b[i]);
	}

	printf("\n"); cnt++;
}
//데이터 교환
void exchange(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
} 
void Permutation(int a[], int n, int r){
	int i;
	if(r==R) printPer();
	else for(i=r; i<n; i++){
		exchange(a+r, a+i);
		b[r] = a[r];
		Permutation(a, n, r+1);
		exchange(a+r, a+i);
	}
}

int main(){
	int a[]={1,2,3,4,5};
	int n=sizeof(a)/sizeof(int);
	Permutation(a,n,0);
	
	printf("순열개수:%d\n",cnt);
	
	return 0;
}
