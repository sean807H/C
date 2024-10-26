#include<stdio.h>
int cnt = 0;
int fibonacciSearch(int a[], int n, int key){
	int fibo[]={0,1,1,2,3,5,8,13,21,34,55};
	int index=0, k=0, pos;
	while(fibo[k<n]) k++;
	while(k>0){
		cnt++;
		pos = index+fibo[--k];
		if(pos<n){
			if(key==a[pos]) return pos;
			if(key>a[pos]){
				index = pos;
				k--;
			}
		}
	}
	return -1; // k==0
}

int main(){
	int a[]={3,5,8,11,22,23,27,39,40,42,45,49,51,57,60,62,66,67,73,87,99};
	int n = sizeof(a)/sizeof(int);
	int index, key;
	printf("찾을값 : ");
	scanf("%d",&key);
	index = fibonacciSearch(a,n,key);
	if(index >= 0) printf("%d위치에서 %d회 비교하여 찾음!\n",index,cnt);
	else printf("없는 Data임!\n");
	
	return 0;
}
