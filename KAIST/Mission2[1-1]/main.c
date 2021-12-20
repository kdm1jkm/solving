// 이 프로그램은 일정이 들어있는 파일을 입력받아서 표에 맞게 출력하는 프로그램이다.
// 제목과 내용의 길이에 따라 표의 길이가 달라지게 만들었으며, 그룹의 이름은 변수로 따로 저장하였다
// 출력하는 부분은 따로 함수로 만들었다.
// 입력도 함수로 만들어 메인 함수를 깔끔하게 만들었으며, 그룹의 이름은 전역변수로 선언하였다.
// 그룹의 번호에 따른 이름:
// 0:공부
// 1:상담
// 2:약속
// 3:휴식
// 4:기타

#include <conio.h> //헤더파일
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TITLE_MAX 127	//제목 최대 글자수
#define CONTENT_MAX 127 //내용 최대 글자수

typedef struct
{						  // Schedule형 구조체 선언
	int year, month, day; //년, 월, 일
	int hour, min;		  //시간, 분
	int important;		  //중요도
	char *title;		  //제목
	char *content;		  //내용
} Schedule;

typedef struct
{						//그룹 구조체
	int max;			//일정 최대 갯수
	int num;			//일정 갯수
	Schedule *schedule; //스케쥴형 포인터
} Group;

const char *groupName[5] = {"공부", "상담", "약속", "휴식", "기타"}; //그룹에 번호에 대응하는 그룹 이룸 저장
Group group[5];														 //전역변수로 그룹배열 선언

void printSchedule(int titleLenth, int contentLenth); //일정 출력
void scanSchedule();								  //일정 입력

//--------------------------------------------------------------------

int main()																																//
{																																		//메인함수
	for (int i = 0; i < 5; i++)																											//
	{																																	// 5번(그룹갯수)반복
		group[i].schedule = (Schedule *)malloc(sizeof(Schedule) * 8);																	//기본적으로 8개의일정을 저장
		group[i].max = 8;																												//최대 갯수는 8개
		group[i].num = 0;																												//저장된 일정은 0개
	}																																	//
	scanSchedule();																														//일정 입력
	int titleLenth = 0, contentLenth = 0;																								// 0으로 선언(값이 없으면 비교가 불가능 하므로)
	for (int i = 0; i < 5; i++)																											//
	{																																	// 5번(그룹갯수)반복
		for (int j = 0; j < group[i].num; j++)																							//
		{																																// i번째 그룹의 일정 갯수만큼 반복
			titleLenth = (strlen(group[i].schedule[j].title) > titleLenth) ? strlen(group[i].schedule[j].title) : titleLenth;			//제목의 길이와 현재 저장된 값 중 더 큰 겂을 저장
			contentLenth = (strlen(group[i].schedule[j].content) > contentLenth) ? strlen(group[i].schedule[j].content) : contentLenth; //위와 같음
		}																																//
	}																																	//
	titleLenth = titleLenth / 2 + 1;																									//전각문자 기준으로(나머지를 버리므로 1을 더함)
	contentLenth = contentLenth / 2 + 1;																								//
	printSchedule(titleLenth, contentLenth);																							//일정 출력
	for (int i = 0; i < 5; i++)																											//
	{																																	// 5번(그룹갯수)반복
		for (int j = 0; j < group[i].num; j++)																							//
		{																																// i번째 그룹의 일정 갯수만큼 반복
			free(group[i].schedule[j].title);																							// i번째 그룹의 j번째 일정의 제목 메모리 할당해제
			free(group[i].schedule[j].content);																							//
		}																																//
		free(group[i].schedule);																										// i번째 일정 자체 메모리 할당 해제
	}																																	//
	puts("종료하려면 아무 키나 누르십시오 . . .");																						//종료 안내 메시지
	system("pause>nul");																												//아무키나 누를때까지 대기
	return 0;																															//정상종료
}

void printSchedule(int titleLenth, int contentLenth)												//
{																									//일정 출력 함수
	printf("┌─────┬───┬───┬──┬");																	//출력 틀(표)
	for (int i = 1; i <= titleLenth; i++)															//
	{																								//제목 글자수만큼(전각문자 기준)
		printf("─");																				//전각문자 한 글자당 선 하나(좀더 nice한 방법을 찾았네요)
	}																								//
	printf("┬");																					//구분선
	for (int i = 1; i <= contentLenth; i++)															//
	{																								//위와 같음
		printf("─");																				//위와 같음
	}																								//
	printf("┐\n");																					//내용이 끝났으므로 개행
	printf("│   날짜   │ 시간 │중요도│그룹│");														//틀
	for (int i = 1; i <= titleLenth * 2; i++)														//
	{																								//글자수 *2를 한 이유는 전각문자 하나의 공간에 스페이스바가 2개 들어가기 때문/nice한 방법의 거의 핵심
		if (titleLenth == i)																		//
		{																							//가운데에
			printf("제목");																			//
			i += 3;																					//제목 을 입력하고 3칸 앞으로 감
		}																							//
		else																						//
			printf(" ");																			//가운데가 아니므로 공백
	}																								//
	printf("│");																					//다음
	for (int i = 1; i <= contentLenth * 2; i++)														//
	{																								//위와 같음
		if (contentLenth == i)																		//
		{																							//위와 같음
			printf("내용");																			//
			i += 3;																					//위와 같음
		}																							//
		else																						//
			printf(" ");																			//위와 같음
	}																								//
	printf("│\n");																					//다음 줄
	for (int i = 0; i < 5; i++)																		//
	{																								//일정을 출력하는 부분(그룹이 5개이므로 5번반복)
		printf("├─────┼───┼───┼──┼");																//틀(그룹과 그룹을 구별)
		for (int j = 1; j <= titleLenth; j++)														//
		{																							//가장 큰 제목길이에 맞게 그림
			printf("─");																			//
		}																							//
		printf("┼");																				//구분선
		for (int j = 1; j <= contentLenth; j++)														//
		{																							//위와 같음
			printf("─");																			//
		}																							//
		printf("┤\n");																				//
		for (int j = 0; j < group[i].num; j++)														//
		{																							//일정의 갯수만큼 반복
			printf("│%04d.%02d.%02d│%02d:%02d │%d     │%s│",										//틀
				   group[i].schedule[j].year, group[i].schedule[j].month, group[i].schedule[j].day, //
				   group[i].schedule[j].hour, group[i].schedule[j].min,								//
				   group[i].schedule[j].important,													//
				   groupName[i]);																	// i번째 그룹이름
			for (int k = 1; k <= titleLenth * 2; k++)												//
			{																						//제목의 출력(스페이스바를 쓰므로 2를곱함
				if (titleLenth * 2 - k == strlen(group[i].schedule[j].title))						//
				{																					//앞으로 남은 공간이 제복의 길이와 같으면
					printf(" %s", group[i].schedule[j].title);										//제목을 입력
					break;																			// for문 나감
				}																					//
				else																				//
					printf(" ");																	//아니므로 공백
			}																						//
			printf("│");																			//
			for (int k = 1; k <= contentLenth * 2; k++)												//
			{																						//
				if (contentLenth * 2 - k == strlen(group[i].schedule[j].content))					//
				{																					//
					printf(" %s", group[i].schedule[j].content);									//
					break;																			//
				}																					//
				else																				//
					printf(" ");																	//
			}																						//
			printf("│\n");																			//
		}																							//
	}																								//
	printf("└─────┴───┴───┴──┴");																	//틀
	for (int i = 1; i <= titleLenth; i++)															//
	{																								//
		printf("─");																				//
	}																								//
	printf("┴");																					//
	for (int i = 1; i <= contentLenth; i++)															//
	{																								//
		printf("─");																				//
	}																								//
	printf("┘\n");																					//
	return;																							//함수 종료
}

void scanSchedule()																									  //
{																													  //
	FILE *file = fopen("data.txt", "r");																			  //파일 열기
	if (file == NULL)																								  //
	{																												  //파일이 존재하지 않을경우
		puts("파일이 존재하지 않습니다!");																			  //
		puts("data.txt 파일이 존재하는지 확인하시고 다시 프로그램을 시작해 주십시오!");								  //
		puts("종료하려면 아무 키나 누르십시오 . . .");																  //경고 메시지
		system("pause>nul");																						  //아무키나 누를때까지 대기
		return 1;																									  // 1을 반환하며 종료(파일 없음 오류)
	}																												  //
	while (!feof(file))																								  //
	{																												  //
		int ymd, hm, tmp1, tmp2;																					  // ymd : year month day//hm : hour min
		char title[TITLE_MAX + 1], content[CONTENT_MAX + 1];														  //길이를 구해서 구조체에 저장(+1을 한 이유는 널문자'\0'까지 넣어야 하기 위해)
		fscanf(file, "%d %d %d %d %s %s",																			  //
			   &ymd, &hm, &tmp1, &tmp2, title, content);															  //입력 형식에 맞게 입력
		if (group[tmp2].num == group[tmp2].max)																		  //
		{																											  //현재 저장된 일정이 최대치이면
			group[tmp2].schedule = (Schedule *)realloc(group[tmp2].schedule, sizeof(Schedule) * group[tmp2].max * 2); //최대의 2배로 재할당
			group[tmp2].max *= 2;																					  //최대를 2배로
		}																											  //
		group[tmp2].schedule[group[tmp2].num].year = ymd / 10000;													  // 20170302->2017
		group[tmp2].schedule[group[tmp2].num].month = (ymd % 10000) / 100;											  // 20170302->0302->03
		group[tmp2].schedule[group[tmp2].num].day = ymd % 100;														  // 20170302->02
		group[tmp2].schedule[group[tmp2].num].hour = hm / 100;														  // 0900->09
		group[tmp2].schedule[group[tmp2].num].min = hm % 100;														  // 0900->00
		group[tmp2].schedule[group[tmp2].num].important = tmp1;														  //중요도
		group[tmp2].schedule[group[tmp2].num].title = (char *)malloc(strlen(title) + 1);							  //동적할당
		strcpy(group[tmp2].schedule[group[tmp2].num].title, title);													  //복사
		group[tmp2].schedule[group[tmp2].num].content = (char *)malloc(strlen(content) + 1);						  //
		strcpy(group[tmp2].schedule[group[tmp2].num].content, content);												  //
		group[tmp2].num++;																							  //
	}																												  //
	fclose(file);																									  //파일닫기
	return;																											  //함수종료
}
