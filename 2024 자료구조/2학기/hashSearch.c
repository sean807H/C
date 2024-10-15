#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEN 21
#define SIZE 30

int main(void) {
	char fruit[LEN]; //과일명
	char fList[SIZE][LEN]; //해시 테이블(버킷)
	char overflowArea[10][LEN]; //오버플로우 구역. 적재율 75%
	char next;
	int fInt = 0, cnt = 0, i = 0, index = 0, divider = SIZE;

	//해시 테이블(버킷) 초기화
	for (; i < SIZE; i++) strcpy_s(fList[i], LEN, "");

	//독립 오버플로우 구역 초기화
	for (i = 0; i < 10; i++) strcpy_s(overflowArea[i], LEN, "");

	/*제수(나눌 값)를 구함. 버킷 크기보다 크고
	소수 또는 소수에 가까운 숫자(20보다 작은 값을 약수로 갖지 않는 수)를 구함*/
	do {
		for (i = 2; i <= 19; i++)
			if (divider % i == 0) break;
		//20보다 작은 수를 약수로 갖지 않으면
		if (i == 20) break;
		//그렇지 않으면
		else divider++;
	} while (1);
	
	//제산함수를 사용하여 해시테이블에 과일명 저장
	do {
		printf("영문 과일명(20글자 이내): ");
		gets_s(fruit, LEN);
		
		//과일명 ASCII 값을 누적함
		i = 0;
		while (*(fruit + i)) fInt += (int)*(fruit + i++);

		//주소 계산
		fInt = (fInt % divider) * SIZE / divider;

		//충돌이 발생하면 오버플로우 구역에 순차적으로 저장함
		if (strcmp(fList[fInt], "")) {
			printf("%d회 충돌 발생!!\n", ++cnt);
			strcpy_s(overflowArea[index++], LEN, fruit);
		}
		//그렇지 않으면 해시 테이블에 저장함
		else strcpy_s(fList[fInt], LEN, fruit);
		
		fInt = 0;
		printf("계속 입력(y/n): ");
		scanf_s("%c", &next, 1);
		getchar();

	} while (next == 'y' || next == 'Y');

	printf("\n저장 공간\n");
	for (i = 0; i < SIZE; i++) {
		printf("인덱스 %d: %s\n", i, fList[i]);
	}

	printf("\n\n독립 오버플로우 구역\n");
	for (i = 0; i < 10; i++) {
		printf("인덱스 %d: %s\n", i, overflowArea[i]);
	}
	printf("\n");

	do {
		printf("\n검색할 과일명: ");
		gets_s(fruit, LEN);

		//과일명 ASCII 값을 누적함
		i = 0; fInt = 0;
		while (*(fruit + i)) fInt += (int)*(fruit + i++);

		//주소 계산
		fInt = (fInt % divider) * SIZE / divider;

		//해시 테이블에서 한번에 검색함
		if (strcmp(fList[fInt], fruit)) {
			for (i = 0; i < 10; i++)
				if (!strcmp(overflowArea[i], fruit)) break;
			if (i < 10) printf("%s을(를) %d회 비교하여 찾음!!\n", fruit, i + 2);
			else printf("%s은(는) 없는 과일명임!!\n", fruit);
		}
		//충돌이면 오버플로우 구역에서 순차적으로 검색함
		else printf("%s을(를) index%d에서 한번만에 찾음!!\n", fruit, fInt);

		fInt = 0;
		printf("\n계속 입력(y/n): ");
		scanf_s("%c", &next, 1);
		getchar();

	} while (next == 'y' || next == 'Y');

	return 0;
}

