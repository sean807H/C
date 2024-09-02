#include<stdio.h>
int main(){
	int i;
	int a[]={25,11,7,20,30,6,5,38,17,15,1};
	int n = sizeof(a)/sizeof(int);
	shellSort(a,n);
	for(i=0; i<n; i++){
		printf("%5d",a[i]);
	}
	
}
void shellSort(int a[], int n){
	int i,j,t,key;
	for(t=n/2; t>=1; t/=2){
		for(i=t; i<n; i++){
			key = a[i];
			for(j=i-t; j>=0; j-=t){
				if(key>=a[j]) break;
				else a[j+t] = a[j];
			}
			a[j+t] = key;
		}
	}
}
