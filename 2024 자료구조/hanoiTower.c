#include<stdio.h>
void HanoiTower(int n,char a,char b, char c){		//n�� ������ ����, a~c�� ���� 
	if(n==1) printf("���� %d, %c -> %c\n",n,a,c);	//n�� ���ǹ�ȣ
	else{
		HanoiTower(n-1,a,c,b);		//(4-1)3���� b�� �ű�, C�� ������ ������ �ű� 
		printf("���� %d, %c -> %c\n",n,a,c);
		HanoiTower(n-1,b,a,c);		//3���� �ٽ� C�� 
	}
}
int main(){
	int n = 8;		//������ ���� 
	HanoiTower(n,'A','B','C');		//'A'�� �����, 'B'�� ������, 'C'�� ������
	
	return 0;
}
