#include <stdio.h> //헤더파일

#define PLATE_MAX 50												   //판 최대 갯수
#define MAX_PLATE(poleNum) pole[poleNum].plate[pole[poleNum].plateNum] //맨 위의 판을 구하는 전처리기(함수로 하니 구현 불가능한 부분이 존재해서..)

typedef struct
{						  //구조체
	int plate[PLATE_MAX]; //판
	int plateNum;		  //맨 위의 판의 번호(-1은 판 없음)
} hanoi;				  //하노이

hanoi pole[3]; //막대기 구조체 3개
int count = 0; //이동 횟수 변수

void printTower();				//출력 함수 원형
void initialize();				//초기화 함수 원형
int move(int pole1, int pole2); //이동 함수 원형
int isFinish();					//원판이 모두 옮겨졌는지 확인하는 함수

int main()													  // 메인 함수
{															  //
	initialize();											  //초기화
	int plateCount;											  //판의 갯수 변수
	scanf("%d", &plateCount);								  //판의 갯수 입력
	for (int i = 0; i < plateCount; i++)					  //
	{														  //판의 갯수 만큼
		pole[0].plate[i] = plateCount - i;					  //판의 갯수-(0~판의 갯수)->판의 갯수~1
	}														  //
	pole[0].plateNum = plateCount - 1;						  // 0번째 기둥의 맨 위의 판의 번호는 갯수-1(시작이 0)
	printTower();											  //맨 처음 출력
	while (1)												  //
	{														  //무한 루프
		int pole1, pole2;									  //입력 변수
		scanf("%d %d", &pole1, &pole2);						  //두 수 입력
		count++;											  //입력받을때마다 이동횟수 증가
		if (pole1 < 0 || pole1 > 2 || pole2 < 0 || pole2 > 2) //
			return 0;										  //둘중 하나라도 범위(0~2)밖이면 프로그램 종료
		move(pole1, pole2);									  //이동 함수
		printTower();										  //출력
		if (isFinish())										  //
		{													  //만약 모든 원판이 옮겨졌다면
			printf("%d", count);							  //아동횟수 출력
			return 0;										  //종료
		}													  //
	}														  //
	return 0;												  //정상종료
}

void printTower()										   //
{														   //출력 함수
	for (int i = 0; i < 3; i++)							   //
	{													   // 3번(기둥의 갯수) 반복
		printf("%d:", i);								   //기둥 번호 출력
		if (pole[i].plateNum == -1)						   //
			printf(" x");								   //판이 없을경우(-1) x출력
		else											   //
		{												   //판이 있을경우
			for (int j = 0; j < pole[i].plateNum + 1; j++) //
			{											   //맨 위 판의 번호+1번 반복
				printf(" %d", pole[i].plate[j]);		   //출력
			}											   //
		}												   //
		printf("\n");									   //다음 기둥이므로 줄바꿈
	}
}
void initialize()							//
{											//초기화 함수
	for (int i = 0; i < 3; i++)				//
	{										// 3번(기둥 갯수)반복
		pole[i].plateNum = -1;				//기둥에는 아무것도 없음
		for (int j = 0; j < PLATE_MAX; j++) //
		{									//판의 최대치 반복
			pole[i].plate[j] = 0;			//쓰레기값 대신 0을 넣음
		}
	}
}

int move(int pole1, int pole2)											   //
{																		   //이동 함수
	if (pole[pole1].plateNum == -1)										   //
		return 0;														   //이동시킬 기둥에 아무것도 없으므로 규칙에 맞지 않아서 0반환
	if (MAX_PLATE(pole1) < MAX_PLATE(pole2) || pole[pole2].plateNum == -1) //
	{																	   //이동시킬 기둥의 맨위의 판보다 이동할 기둥의 판의 크기가 크거나, 이동할 기둥에 판이 없을경우
		pole[pole2].plateNum++;											   //이동할 기둥의 판의 갯수는 늘어난다
		MAX_PLATE(pole2) = MAX_PLATE(pole1);							   //이동할 기둥으로 이동시킬 기둥의 판 복사
		MAX_PLATE(pole1) = 0;											   //이동시킬 판에 맨위는 없앰
		pole[pole1].plateNum--;											   //이동시킬 판은 판의 갯수가 하나 줄어듦
		return 1;														   //정상 이동
	}																	   //
	return 0;															   //저 위의 경우에 맞지 않으면 규칙에 맞지 않으므로 0반환
}

int isFinish()											  //
{														  //원판 확인 함수
	if (pole[0].plateNum == -1 && pole[1].plateNum == -1) //
	{													  // 0번 기둥과 1번 기둥에 원판이 없을경우
		return 1;										  // 1 반환(true)
	}													  //
	else												  //
	{													  //아닐경우
		return 0;										  // 0 반환(false)
	}													  //
}
