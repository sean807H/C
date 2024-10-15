#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEN 21
#define SIZE 30

int main(void) {
	char fruit[LEN]; //���ϸ�
	char fList[SIZE][LEN]; //�ؽ� ���̺�(��Ŷ)
	char overflowArea[10][LEN]; //�����÷ο� ����. ������ 75%
	char next;
	int fInt = 0, cnt = 0, i = 0, index = 0, divider = SIZE;

	//�ؽ� ���̺�(��Ŷ) �ʱ�ȭ
	for (; i < SIZE; i++) strcpy_s(fList[i], LEN, "");

	//���� �����÷ο� ���� �ʱ�ȭ
	for (i = 0; i < 10; i++) strcpy_s(overflowArea[i], LEN, "");

	/*����(���� ��)�� ����. ��Ŷ ũ�⺸�� ũ��
	�Ҽ� �Ǵ� �Ҽ��� ����� ����(20���� ���� ���� ����� ���� �ʴ� ��)�� ����*/
	do {
		for (i = 2; i <= 19; i++)
			if (divider % i == 0) break;
		//20���� ���� ���� ����� ���� ������
		if (i == 20) break;
		//�׷��� ������
		else divider++;
	} while (1);
	
	//�����Լ��� ����Ͽ� �ؽ����̺� ���ϸ� ����
	do {
		printf("���� ���ϸ�(20���� �̳�): ");
		gets_s(fruit, LEN);
		
		//���ϸ� ASCII ���� ������
		i = 0;
		while (*(fruit + i)) fInt += (int)*(fruit + i++);

		//�ּ� ���
		fInt = (fInt % divider) * SIZE / divider;

		//�浹�� �߻��ϸ� �����÷ο� ������ ���������� ������
		if (strcmp(fList[fInt], "")) {
			printf("%dȸ �浹 �߻�!!\n", ++cnt);
			strcpy_s(overflowArea[index++], LEN, fruit);
		}
		//�׷��� ������ �ؽ� ���̺� ������
		else strcpy_s(fList[fInt], LEN, fruit);
		
		fInt = 0;
		printf("��� �Է�(y/n): ");
		scanf_s("%c", &next, 1);
		getchar();

	} while (next == 'y' || next == 'Y');

	printf("\n���� ����\n");
	for (i = 0; i < SIZE; i++) {
		printf("�ε��� %d: %s\n", i, fList[i]);
	}

	printf("\n\n���� �����÷ο� ����\n");
	for (i = 0; i < 10; i++) {
		printf("�ε��� %d: %s\n", i, overflowArea[i]);
	}
	printf("\n");

	do {
		printf("\n�˻��� ���ϸ�: ");
		gets_s(fruit, LEN);

		//���ϸ� ASCII ���� ������
		i = 0; fInt = 0;
		while (*(fruit + i)) fInt += (int)*(fruit + i++);

		//�ּ� ���
		fInt = (fInt % divider) * SIZE / divider;

		//�ؽ� ���̺��� �ѹ��� �˻���
		if (strcmp(fList[fInt], fruit)) {
			for (i = 0; i < 10; i++)
				if (!strcmp(overflowArea[i], fruit)) break;
			if (i < 10) printf("%s��(��) %dȸ ���Ͽ� ã��!!\n", fruit, i + 2);
			else printf("%s��(��) ���� ���ϸ���!!\n", fruit);
		}
		//�浹�̸� �����÷ο� �������� ���������� �˻���
		else printf("%s��(��) index%d���� �ѹ����� ã��!!\n", fruit, fInt);

		fInt = 0;
		printf("\n��� �Է�(y/n): ");
		scanf_s("%c", &next, 1);
		getchar();

	} while (next == 'y' || next == 'Y');

	return 0;
}

