#include <stdio.h>
#define R 3

int b[R], cnt = 0;

void printCom(void){
	int i;
	for(i=0; i<R; i++) printf("%5d",b[i]);
	printf("\n"); cnt++; 
	
}

void Recombination(int a[], int n, int r, int ii){
	int i;
	if(r==R) printCom();
	else for(i=ii; i<n; i++){
		b[r]=a[i];
		Recombination(a, n, r+1, i);
	}
}

int main(void){
	int a[] = {1,2,3,4,5};
	int n = sizeof(a)/sizeof(int);
	
	Recombination(a, n, 0, 0);
	printf("중복 조합 개수:%d\n",cnt);
	
	return 0;
}
