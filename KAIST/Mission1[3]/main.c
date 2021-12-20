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
int isFinish(int num, int poleNum); //원판이 모두 옮겨졌는지 확인하는 함수 원형
int solve(int n, int from, int to); //하노이의 탑을 푸는 함수 원형

int main()																									   //
{																											   //메인 함수
	int plateNum, toWhere, isAuto;																			   //입력받을 3개의 변수
	printf("판의 갯수를 입력하십시오 : ");																	   //입력 멘트(여기서부터 입력)
	scanf("%d", &plateNum);																					   //
	printf("옮길 기둥 번호를 입력하십시오 : ");																   //
	scanf("%d", &toWhere);																					   //
	printf("직접 실행하시려면 1번, 자동으로 실행하시려면 2번을 입력하세요 : ");								   //
	scanf("%d", &isAuto);																					   //여기까지 입력
	initialize();																							   //판 초기화
	for (int i = 0; i < plateNum; i++)																		   //
	{																										   //판의 갯수만큼
		pole[0].plate[i] = plateNum - i;																	   // 0~판의 갯수 에 판의갯수~1 저장
	}																										   //
	pole[0].plateNum = plateNum - 1;																		   //판의 갯수를 구조체에 저장
	if (isAuto == 2)																						   //
	{																										   //자동 실행 기능일경우
		printTower();																						   //타워 출력
		solve(plateNum, 0, toWhere);																		   //해답 구하기
		printf("총 이동횟수는 %d회 입니다.", count);														   //총 이동횟수 출력
		return 0;																							   //프로그램 정상종료
	}																										   //
	else																									   //
	{																										   //자동 모드가 아닐경우(수동 모드일경우)
		while (1)																							   //
		{																									   //무한루프
			printf("----------\n");																			   //다음(이전) 타워와 구별
			int input1, input2;																				   //출발지와 목적지 타워 입력
			printTower();																					   //타워 출력
			printf("출발지 기둥을 입력하세요 : ");															   //입력
			scanf("%d", &input1);																			   //
			printf("목적지 기둥을 입력하세요 : ");															   //
			scanf("%d", &input2);																			   //
			if (input1 < 0 || input1 > 2 || input2 < 0 || input2 > 2)										   //
			{																								   //타워 입력값이 범위 밖이면
				printf("0~2사이의 값을 입력해 주세요...\n");												   //수정 요정 메시지
				continue;																					   //무한루프 처음으로 되돌아감
			}																								   //
			if (move(input1, input2) == 1)																	   //
			{																								   //이동 함수를 실행 및 반환값이 1이면(정상적으로 옮겨지면)
				printf("%d번 기둥에서 판%d를 %d번 기둥으로 옮겼습니다.\n", input1, MAX_PLATE(input2), input2); //옮겨졌음을 알리는 메시지
				count++;																					   //이동횟수 증가
			}																								   //
			else																							   //
			{																								   //정상적으로 옮겨지지 않았으면(판은 변하지 않음)
				printf("기둥을 옮길 수 없습니다!\n");														   //오류 메시지 출력
				continue;																					   //무한루프 처음으로 되돌아감
			}																								   //
			if (isFinish(plateNum, toWhere))																   //
			{																								   //타워가 완전히 이동했으면
				printf("축하합니다.\n");																	   //
				printf("0번 기둥에서 %d번 기둥으로 모든 판을 옮기셨습니다!\n", toWhere);					   //
				printf("모두 이동하기까지 총 %d번 이동하였습니다.", count);									   //축하 메시지와 출발기둥(0이지만..), 그리고 목적지기둥, 이동횟수 츨력
				return 0;																					   //정상종료
			}
		}
	}
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
		return 0;														   //이동시킬 기둥에 아무것도 없으므로 규칙에 맞지 않아서 0반환(판의 값은 변하지 않음)
	if (MAX_PLATE(pole1) < MAX_PLATE(pole2) || pole[pole2].plateNum == -1) //
	{																	   //이동시킬 기둥의 맨위의 판보다 이동할 기둥의 판의 크기가 크거나, 이동할 기둥에 판이 없을경우(규칙에 맞을경우)
		pole[pole2].plateNum++;											   //이동할 기둥의 판의 갯수(맨 위의 판의 위치)는 늘어난다
		MAX_PLATE(pole2) = MAX_PLATE(pole1);							   //이동할 기둥으로 이동시킬 기둥의 판 복사
		MAX_PLATE(pole1) = 0;											   //이동시킬 판에 맨위는 없앰
		pole[pole1].plateNum--;											   //이동시킬 판은 판의 갯수가 하나 줄어듦
		return 1;														   //정상 이동
	}																	   //
	return 0;															   //저 위의 경우에 맞지 않으면 규칙에 맞지 않으므로 0반환(판의 값은 변하지 않음)
}

int isFinish(int num, int poleNum)		   //
{										   //원판 확인 함수
	if (pole[poleNum].plateNum + 1 == num) //
	{									   //확인할 기둥에 판의 갯수와 최대값이 같은경우(그 기둥에 모든 판이 있을경우)
		return 1;						   // 1 반환(true)
	}									   //
	else								   //
	{									   //아닐경우
		return 0;						   // 0 반환(false)
	}
}

int solve(int n, int from, int to)																	   //
{																									   //하노이의 탑 정답(?) 함수
	int mid = 3 - from - to;																		   //경유지 기둥[목적지 기둥도, 출발지 기둥도 아닌 기둥](0+1+2=3이기 때문에 3에서 두 기둥을 빼면 나머지 기중의 값이 나온다)
	if (n == 1)																						   //
	{																								   // 1개를 이동할경우
		printf("----------\n");																		   //자동도 위의(아래의)타워와 구별
		printf("%d 번 기둥에 있는 원판%d 를 %d 번 기둥으로 옮겼습니다.\n", from, MAX_PLATE(from), to); //어떤 기둥에서 어떤 판을 어떤 기둥으로 옮겼는지 츨력
		move(from, to);																				   //그냥 이동
		count++;																					   //이동횟수 증가
		printTower();																				   //타워 출력
		return 0;																					   //함수 종료
	}																								   //
	else																							   //
	{																								   // 1개가 아닐경우
		solve(n - 1, from, mid);																	   // 1개 적은 판들을 시작점에서 경유지 기둥으로 이동
		printf("----------\n");																		   // 108줄 참조
		printf("%d 번 기둥에 있는 원판%d 를 %d 번 기둥으로 옮겼습니다.\n", from, MAX_PLATE(from), to); //판 이동에 대한 설명(109번째 줄 참조)
		move(from, to);																				   //맨 및에판을 목적지 기둥으로 이동
		count++;																					   //이동횟수 증가
		printTower();																				   //타워 출력
		solve(n - 1, mid, to);																		   //경유지 기둥을 목적지 기둥으로 이동
	}
}
