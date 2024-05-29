#include <stdio.h>
#define SIZE 6

int queue[SIZE];
int rear = -1, front = 0;
int cnt = 0;

int add(int data){
		if(cnt == SIZE){
			printf("Queue is Full!\n");
			return -1;
		}
		queue[++rear %SIZE] = data;
		cnt++;
		return 0;
	}	
	
	int delete(void){
		if(cnt == 0){
			printf("Queue is Empty!\n");
			return -1;
		}
		cnt--;
		return queue[front++ %SIZE];
	}
int main(){
	add(10); add(20); add(30);
	printf("%d\n",delete());
	printf("%d\n",delete());
	printf("%d\n",delete());
	printf("%d\n",delete());	// underflow!
	add(40); add(50); add(60);
	add(70); add(80); add(90);	// overflow! 
	printf("%d\n",delete());
	add(100);
	
	return 0;

	
}
