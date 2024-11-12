#include <stdio.h>
#define SIZE 8

int gueue[SIZE] = {0, };
int rear = -1, front = 0;

typedef enum { false, true } bool;

void add(int index){
	gueue[++rear] = index;
}

int delete(){
	if(rear < front) return -1;
	return gueue[front++];
}

void BreadthFirstSearch(char v[], bool a[][SIZE]){
	bool searchOK[SIZE] = {false, };
	int i, j;
	char vertex;

	printf("\n���� ����(A~H �� �Է�) : ");
	scanf_s("%c", & vertex, 1);

	for(i = 0; i < SIZE; i++) if( vertex == v[i]) break;

	printf("\n���̿켱Ž�� ���� : %c", v[i]);

	searchOK[i] = true;

	do{
		for(j = 0; j < SIZE; j++){
			if(a[i][j] == 1 && searchOK[j] == false){
				printf(" -> %c", v[j]);
				searchOK[j] = true;
				add(j);
			}

		}

		i = delete();

	} while(i >= 0);
}

int main(void){
	int i, j;
	char v[SIZE]={'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
	bool a[SIZE][SIZE] = { {0, 1, 1, 0, 0, 0, 0, 0},
			{1, 0, 0, 1, 1, 0, 0, 0},
			{1, 0, 0, 0, 0, 1, 1, 0},
			{0, 1, 0, 0, 0, 0, 0, 1},
			{0, 1, 0, 0, 0, 0, 0, 1},
			{0, 0, 1, 0, 0, 0, 0, 1},
			{0, 0, 1, 0, 0, 0, 0, 1},
			{0, 0, 0, 1, 1, 1, 1, 0} };

	/* ���� ������Ŀ� �ش��ϴ� �׷����� �׷����� ���̿켱Ž���� �����Ͻÿ�.
	bool a[SIZE][SIZE]={{0, 1, 1, 1, 0, 0, 0, 0},
			{1, 0, 0, 0, 1, 0, 0, 0},
			{1, 0, 0, 0, 0, 1, 0, 0},
			{1, 0, 0, 0, 0, 0, 1, 0},
			{0, 1, 0, 0, 0, 0, 0, 0},
			{0, 0, 1, 0, 0, 0, 1, 1},
			{0, 0, 0, 1, 0, 1, 0, 1},
			{0, 0, 0, 0, 0, 1, 1, 0}};
	*/

	printf("\n\t\t���� ����\n");
	for(i = 0; i < SIZE; i++){
		for(j = 0; j < SIZE; j++)
			printf("%5d", a[i][j]);
		printf("\n");
	}

	BreadthFirstSearch(v, a);

	return 0;
}
