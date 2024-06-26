#include<stdio.h>
#define SIZE 6

int stack[SIZE];
int top = -1;
int push(int data){
	if(top == SIZE-1){		// stack이 overflow 인지 확인
		printf("stack is Full! \n");
		return -1; 
	}
	stack[++top] = data;
	return 0;
}

int pop(void){
	if(top == -1){
		printf("stack is Empty! \n");
		return -1;
	}
	return stack[top--];
}

int main(void){
	push(10); push(20); push(30);
	push(40); push(50); push(60); push(70);
	// push(70) stack is full, pop(60) 제일 늦게 들어감
	printf("%d\n",pop());
	printf("%d\n",pop());
	printf("%d\n",pop());
	printf("%d\n",pop());
	printf("%d\n",pop());
	printf("%d\n",pop());
	printf("%d\n",pop());
	//pop() = stack is empty! return -1
	return 0;
}
