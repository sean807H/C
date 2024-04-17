#include<stdio.h>
void HanoiTower(int n,char a,char b, char c){		//n은 원판의 갯수, a~c는 변수 
	if(n==1) printf("원판 %d, %c -> %c\n",n,a,c);	//n은 원판번호
	else{
		HanoiTower(n-1,a,c,b);		//(4-1)3개를 b로 옮김, C는 마지막 원판이 옮김 
		printf("원판 %d, %c -> %c\n",n,a,c);
		HanoiTower(n-1,b,a,c);		//3개를 다시 C로 
	}
}
int main(){
	int n = 8;		//원판의 갯수 
	HanoiTower(n,'A','B','C');		//'A'는 출발지, 'B'는 경유지, 'C'는 도착지
	
	return 0;
}
