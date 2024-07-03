#include <stdio.h>
#include <stdlib.h>

struct node{
	struct node *llink;
	char data;
	struct node *rlink;
};

struct node *createNode(char data){
	struct node *p = (struct node *)malloc(sizeof(struct node));

	p->llink = NULL;
	p->data = data;
	p->rlink = NULL;
	return p;
}

//����Ʈ�� �Ҹ�
void deleteAll(struct node *p){
	if(p!=NULL){
		deleteAll(p->llink);		// L
		deleteAll(p->rlink);		// R
		printf("%c, ",p->data);
		free(p);					// ���Ҹ� 
	}
}


//��������
void preOrder(struct node *p){
	if(p!=NULL){
		printf("%c, ",p->data);		// Date
		preOrder(p->llink);			// left
		preOrder(p->rlink);			// right
	}
}

//��������
void inOrder(struct node *p){
	if(p!=NULL){
		inOrder(p->llink);			// left
		printf("%c, ",p->data);		// Date
		inOrder(p->rlink);			// right
	}
}

//��������
void postOrder(struct node *p){
	if(p!=NULL){
		postOrder(p->llink);			// left
		postOrder(p->rlink);			// right
		printf("%c, ",p->data);		// Date
	}
}



int main(void){
	struct node *root = createNode('A');
	root->llink = createNode('B');
	root->rlink = createNode('C');
	root->llink->llink = createNode('D');
	root->llink->rlink = createNode('E');
	root->rlink->rlink = createNode('F');
	root->llink->rlink->llink = createNode('G');
	root->rlink->rlink->llink = createNode('H');
	root->rlink->rlink->rlink = createNode('I');
	root->llink->rlink->llink->rlink = createNode('J');

	printf("���� ����(preOrder)  : ");
	preOrder(root);printf("\n");

	printf("���� ����(inOrder)   : ");
	inOrder(root);printf("\n");

	printf("���� ����(postOrder) : ");
	postOrder(root);printf("\n");

	deleteAll(root);

	return 0;
}
