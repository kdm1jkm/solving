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

void printTower();					//출력 함수 원형
void initialize();					//초기화 함수 원형
int move(int pole1, int pole2);		//이동 함수 원형
int solve(int n, int from, int to); //하노이의 탑을 푸는 함수

int main()								 //
{										 //메인 함수
	initialize();						 //초기화
	int plateNum;						 //판의 갯수
	int toWhere;						 //옮길 막대
	scanf("%d", &plateNum);				 //입력
	scanf("%d", &toWhere);				 //
	if (toWhere > 2 || toWhere < 0)		 //
		return 0;						 //입력한 목적지 기둥이 0~2가 아닌경우 프로그램 종료
	for (int i = 0; i < plateNum; i++)	 //
	{									 //판 초기화
		pole[0].plate[i] = plateNum - i; // 0번 막대의 0~판의 갯수 에 판의 갯수~1 값 넣기
	}									 //
	pole[0].plateNum = plateNum - 1;	 //판의 갯수-1(시작이 0이므로)
	printTower();						 //출력
	solve(plateNum, 0, toWhere);		 //하노이의 탑 실행
	printTower();						 //출력
	printf("%d\n", count);				 //횟수 출력
	return 0;							 //정상종료
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
		pole[pole2].plateNum++;											   //이동할 기둥의 판의 갯수는 늘어난다6
		MAX_PLATE(pole2) = MAX_PLATE(pole1);							   //이동할 기둥으로 이동시킬 기둥의 판 복사
		MAX_PLATE(pole1) = 0;											   //이동시킬 판에 맨위는 없앰
		pole[pole1].plateNum--;											   //이동시킬 판은 판의 갯수가 하나 줄어듦
		return 1;														   //정상 이동
	}																	   //
	return 0;															   //저 위의 경우에 맞지 않으면 규칙에 맞지 않으므로 0반환
}
int solve(int n, int from, int to) //
{								   //하노이의 탑 정답(?) 함수
	int mid = 3 - from - to;	   //경유지 기둥[목적지 기둥도, 출발지 기둥도 아닌 기둥](0+1+2=3)
	if (n == 1)					   //
	{							   // 1개를 이동할경우
		move(from, to);			   //그냥 이동
		count++;				   //이동횟수 증가
		return 0;				   //함수 종료
	}							   //
	else						   //
	{							   // 1개가 아닐경우
		solve(n - 1, from, mid);   // 1개 적은 판들을 시작점에서 경유지 기둥으로 이동
		move(from, to);			   //맨 및에판을 목적지 기둥으로 이동
		count++;				   //이동횟수 증가
		solve(n - 1, mid, to);	   //경유지 기둥을 목적지 기둥으로 이동
	}
}
