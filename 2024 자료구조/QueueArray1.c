#include <stdio.h>
#define SIZE 6

int queue[SIZE];
int rear = -1, front = 0;

int add(int data){
		if(rear == SIZE-1){
			printf("Queue is Full!\n");
			return -1;
		}
		queue[++rear] = data;
		return 0;
	}	
	
	int delete(void){
		if(rear < front){
			printf("Queue is Empty!\n");
			return -1;
		}
		return queue[front++];
	}
int main(){
	add(10); add(20); add(30);
//	printf("%d\n",delete());
//	printf("%d\n",delete());
//	printf("%d\n",delete());
//	printf("%d\n",delete());	// underflow!
	add(40); add(50); add(60);
	add(70);	// overflow! 
	
	return 0;

	
}
