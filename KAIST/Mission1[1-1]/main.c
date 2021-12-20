#include <stdio.h> //헤더파일 포함

#define PLATE_MAX 50 //판의 최대 갯수

typedef struct			  // 구조체
{						  //
	int plate[PLATE_MAX]; // 구조체 멤버 판
} hanoi;				  // 하노이

hanoi pole[3]; // 막대 3개

void printTower(); // 출력 함수 원형

int main()									// 메인 함수
{											//
	for (int i = 0; i < 3; i++)				// 3번(막대의 갯수)번 반복(여기부터 초기화)
	{										//
		for (int j = 0; j < PLATE_MAX; j++) //
		{									// 판의 최대 갯수번 반복
			pole[i].plate[j] = 0;			// 쓰레기값대신 0으로 초기화
		}									//
	}										// 여기까지 초기화
	int count;								// 입력 변수
	scanf("%d", &count);					// 입력
	for (int i = 0; i < count; i++)			//
	{										// 입력된 만큼 반복
		pole[0].plate[i] = count - i;		// 0~입력 의 판은 입력~1의 값이 들어감
	}										//
	printTower();							// 출력
	return 0;								// 정상종료
}

void printTower()								 // 출력 함수
{												 //
	for (int i = 0; i < 3; i++)					 //
	{											 // 3번반복
		printf("%d:", i);						 // 막대의 번호 출력
		if (pole[i].plate[0] == 0)				 //
			printf(" x");						 // 판이 없을경우 x출력
		else									 //
		{										 // 판이 있을경우
			int j = 0;							 // 반복을 위한 변수
			while (1)							 //
			{									 // 무한루프(중간에 break존재)
				if (pole[i].plate[j] == 0)		 //
					break;						 // 현재 조사하는 값이 0이면 루프 나감
				printf(" %d", pole[i].plate[j]); // 현재 조사하는 값을 출력
				j++;							 // 현재 조사하는 값을 다음 값으로
			}									 //
		}										 //
		printf("\n");							 // 그 다음 기둥이므로 줄바꿈
	}
}
