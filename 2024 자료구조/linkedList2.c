#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
	char hakbun[5];
	char name[11];
	int age;
	char tel[14];
	struct student *link;
};

void input(struct student *p) {
	printf("\n�й�(4�ڸ�): ");
	gets(p->hakbun);

	printf("����(5���̳�): ");
	gets(p->name);

	printf("����: ");
	scanf("%d", &p->age);
	getchar();

	printf("��ȭ��ȣ: ");
	gets(p->tel);
}

void createLinkedList(struct student *p) {
	char yn = 'y';

	while (yn == 'y' || yn == 'Y') {
		p->link = (struct student *)malloc(sizeof(struct student));
		p = p->link;
		input(p);
		p->link = NULL;
		printf("\n��� �Է��̸� y ������, �׸� �Է��̸� n ����: ");
		scanf("%c", &yn);
		getchar();
	}
}

void printLinkedList(struct student *p) {
	printf("\n\t- �л� ���� ��� -\n\n");
	printf("�й�\t����\t����\t��ȭ��ȣ\n");
	while (p != NULL) {
		printf("%s\t%s\t%d\t%s\n", p->hakbun, p->name, p->age, p->tel);
		p = p->link;
	}
	printf("\n");
}

void deleteNode(struct student *p, int n) {
	int pos = 1;
	struct student *del;

	while (pos < n && p->link != NULL) {
		p = p->link;
		pos++;
	}

	del = p->link;
	p->link = del->link;

	free(del);

}

void insertNode(struct student *p, int n) {
	int pos = 1;
	struct student *ins;

	while (pos < n && p->link != NULL) {
		p = p->link;
		pos++;
	}

	ins = (struct student *)malloc(sizeof(struct student));
	input(ins);
	ins->link = p->link;
	p->link = ins;
}

void allDestruction(struct student *p) {
	struct student *del = p;

	while (p != NULL) {
		p = p->link;
		free(del);
		del = p;
	}
}

int main(void) {
	int n;
	struct student *head;

	head = (struct student *)malloc(sizeof(struct student));
	strcpy(head->hakbun, "");
	strcpy(head->name, "");
	head->age = 0;
	strcpy(head->tel, "");
	head->link = NULL;

	printf("\n\t#���� �۾�#\n");
	createLinkedList(head);
	printLinkedList(head->link);

	printf("\n\t#���� �۾�#\n");
	printf("\n�� ��°�� �����ұ��. ���ڷ� �Է�: ");
	scanf("%d", &n);
	getchar();
	insertNode(head, n);
	printLinkedList(head->link);

	printf("\n\t#���� �۾�#\n\n");
	printf("�� ��°�� �����ұ��. ���ڷ� �Է�: ");
	scanf("%d", &n);
	getchar();
	deleteNode(head, n);
	printLinkedList(head->link);

	allDestruction(head);

	return 0;
}
