#include<stdio.h>   // ������ ����
int euclid(int m, int n){   // ������ �ٸ��� ���� �̸��� ���Ƶ� ��
    int r;
    while((r = m%n)!=0){
        m = n;
        n = r;
    }

    return n;

}
int main(void){
    int m,n,t;
    printf("���� ���� : ");
    scanf_s("%d",&m);
    printf("���� ���� : ");
    scanf_s("%d",&n);
    if(m<n){
        t = m;
        m = n;
        n = t;
    }
    printf("%d�� %d�� �ִ����� : %d\n",m,n,euclid(m,n));

    return 0;
}