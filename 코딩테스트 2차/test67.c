#include <stdio.h>
int main(){
	int a;
	scanf("%d",&a);
	printf("%d = ",a);
	if(a<0){
		printf("minus - ");
		if(a%2==0) printf("even");
		else printf("odd");
	}
	else{
		printf("plus - ");
		if(a%2==0) printf("even");
		else printf("odd");
	}
	
}
