#include <stdio.h>
int main(){
	int a,b,c;
	int sum = 0;
	float avg = 0;
	scanf("%d %d %d",&a,&b,&c);
	sum = a+b+c;
//	avg = (float)a+b+c/3;
	printf("%d\n",sum);
	printf("%.1f\n",sum/3.0);
	
}
