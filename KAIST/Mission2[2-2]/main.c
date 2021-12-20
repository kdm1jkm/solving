// 이 프로그램은 일정이 들어있는 파일을 입력받아서 표에 맞게 출력하는 프로그램이다.
// 제목과 내용의 길이에 따라 표의 길이가 달라지게 만들었으며, 그룹의 이름은 변수로 따로 저장하였다
// 출력하는 부분은 따로 함수로 만들었다.
// 입력도 함수로 만들어 메인 함수를 깔끔하게 만들었으며, 그룹의 이름은 전역변수로 선언하였다.
// 일정을 자세히 보는 함수와 일정을 추가하는 함수도 추가하였다.
// 일정을 수정하는 함수를 추가하였다.
// 그룹의 번호에 따른 이름:
// 0:공부
// 1:상담
// 2:약속
// 3:휴식
// 4:기타
// 그리고 화살표키를 이용하여 커서를 이동할 수 있게 만들었다

#include <conio.h> //헤더파일
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TITLE_MAX 127	//제목 최대 글자수
#define CONTENT_MAX 127 //내용 최대 글자수
#define UP 72			// getch위쪽 화살표
#define DOWN 80			// getch아래쪽 화살표
#define ARROW 224		//화살표인지 아닌지 구별
#define SPACE 32

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

void printSchedule(int cursorPlace);		//일정 출력
void printInformation(int num);				//자세한 정보 출력
int scanSchedule();							//일정 입력
void newSchedule();							//일정 추가
void changeSchedule(int num);				//일정 변경 함수
void printScheduleFile();					//현재까지 저장된 일정을 파일로 출력하는 함수
void initializeGroup();						//파일로부터 그룹파일을 재할당하고 다시 불러오는 함수
void deleteSchedule(int num);				//일정 삭제
void blankToUnderBar(char *from, char *to); //공백을 언더바(_)로 마꾸는 함수

//--------------------------------------------------------------------

int main()															  //
{																	  //메인함수
	for (int i = 0; i < 5; i++)										  //
	{																  // 5번(그룹갯수)반복
		group[i].schedule = (Schedule *)malloc(sizeof(Schedule) * 8); //기본적으로 8개의일정을 저장
		group[i].max = 8;											  //최대 갯수는 8개
		group[i].num = 0;											  //저장된 일정은 0개
	}																  //
	if (scanSchedule())												  //
		return 1;													  //일정 입력(일정이 없을경우 -1을 리턴)
	int count = 0;													  //일정의 갯수
	for (int i = 0; i < 5; i++)										  //
	{																  //
		count += group[i].num;										  // 5개 그룹의 일정을 모두 더한다
	}																  //
	int cursorPlace = 0;											  //현재 커서의 위치
	int input;														  //입력받을 값
	while (1)														  //
	{																  //무한루프
		printSchedule(cursorPlace);									  //그리기
		input = getch();											  //입력
		if (input == ARROW)											  //
		{															  //화살표일경우
			input = getch();										  //한번더 입력
			if (input == UP && cursorPlace != 0)					  //
				cursorPlace--;										  //위쪽 화살표를 입력받고 커서가 맨 위가 아닐경우 커서를 한칸 위로
			else if (input == DOWN && cursorPlace != count - 1)		  //
				cursorPlace++;										  //위와 동일
		}															  //
		else if (input == SPACE)									  //
		{															  //스페이스바일경우
			printInformation(cursorPlace);							  //자세한 정보 출력
			while (1)												  //
			{														  //
				input = getch();									  //자세한 화면에서의 시퀸스
				if (input == 'q')									  //
					break;											  // q를 누르면 빠져나감
				else if (input == 'e')								  //
				{													  // e를 누르면 일정 수정
					changeSchedule(cursorPlace);					  //일정 수정
					break;											  // while문 깨기
				}													  //
			}														  //
		}															  //
		else if (input == 'i')										  //
		{															  // i일경우
			newSchedule();											  //일정추가
			count++;												  //일정갯수+1
		}															  //
		else if (input == 'e')										  //
		{															  // e일경우
			changeSchedule(cursorPlace);							  //현재 커서의 위치에 있는 일정을 변경
		}															  //
		else if (input == 'd')										  //
		{															  // d일경우
			deleteSchedule(cursorPlace);							  //일정 삭제
			count--;												  //전체 일정의 갯수가 줄어듬(그 그룹의 일정 갯수는 저 함수에서 알아서 줄임)
			if (count == cursorPlace)								  //
			{														  //갯수와 번호가 같으면(갯수->1,2,3...번호->0,1,2...)이므로 삭제된 일정이 마지막이었으면
				cursorPlace--;										  //커서를 한 칸 위로
			}														  //
		}															  //
	}																  //
	for (int i = 0; i < 5; i++)										  //
	{																  // 5번(그룹갯수)반복
		for (int j = 0; j < group[i].num; j++)						  //
		{															  // i번째 그룹의 일정 갯수만큼 반복
			free(group[i].schedule[j].title);						  // i번째 그룹의 j번째 일정의 제목 메모리 할당해제
			free(group[i].schedule[j].content);						  //
		}															  //
		free(group[i].schedule);									  // i번째 일정 자체 메모리 할당 해제
	}																  //
	puts("종료하려면 아무 키나 누르십시오 . . .");					  //종료 안내 메시지
	system("pause>nul");											  //아무키나 누를때까지 대기
	return 0;														  //정상종료
}

void printSchedule(int cursorPlace)																										//
{																																		//일정 출력 함수
	int titleLenth = 0, contentLenth = 0;																								// 0으로 선언(값이 없으면 비교가 불가능 하므로)
	for (int i = 0; i < 5; i++)																											//
	{																																	// 5번(그룹갯수)반복
		for (int j = 0; j < group[i].num; j++)																							//
		{																																//																						// i번째 그룹의 일정 갯수만큼 반복
			titleLenth = (strlen(group[i].schedule[j].title) > titleLenth) ? strlen(group[i].schedule[j].title) : titleLenth;			//제목의 길이와 현재 저장된 값 중 더 큰 겂을 저장
			contentLenth = (strlen(group[i].schedule[j].content) > contentLenth) ? strlen(group[i].schedule[j].content) : contentLenth; //위와 같음
		}																																//
	}																																	//
	titleLenth = titleLenth / 2 + 1;																									//전각문자 기준으로(나머지를 버리므로 1을 더함)
	contentLenth = contentLenth / 2 + 1;																								//
	system("cls");																														//화면지우기
	int count = 0;																														//이때까지 출력한 일정의 갯수(아래의 커서 출력에 필요)
	printf("  ┌─────┬───┬───┬──┬");																										//출력 틀(표)
	for (int i = 1; i <= titleLenth; i++)																								//
	{																																	//제목 글자수만큼(전각문자 기준)
		printf("─");																													//전각문자 한 글자당 선 하나(좀더 nice한 방법을 찾았네요)
	}																																	//
	printf("┬");																														//구분선
	for (int i = 1; i <= contentLenth; i++)																								//
	{																																	//위와 같음
		printf("─");																													//위와 같음
	}																																	//
	printf("┐\n");																														//내용이 끝났으므로 개행
	printf("  │   날짜   │ 시간 │중요도│그룹│");																						//틀
	for (int i = 1; i <= titleLenth * 2; i++)																							//
	{																																	//글자수 *2를 한 이유는 전각문자 하나의 공간에 스페이스바가 2개 들어가기 때문/nice한 방법의 거의 핵심
		if (titleLenth == i)																											//
		{																																//가운데에
			printf("제목");																												//
			i += 3;																														//제목 을 입력하고 3칸 앞으로 감
		}																																//
		else																															//
			printf(" ");																												//가운데가 아니므로 공백
	}																																	//
	printf("│");																														//다음
	for (int i = 1; i <= contentLenth * 2; i++)																							//
	{																																	//위와 같음
		if (contentLenth == i)																											//
		{																																//위와 같음
			printf("내용");																												//
			i += 3;																														//위와 같음
		}																																//
		else																															//
			printf(" ");																												//위와 같음
	}																																	//
	printf("│\n");																														//다음 줄
	for (int i = 0; i < 5; i++)																											//
	{																																	//일정을 출력하는 부분(그룹이 5개이므로 5번반복)
		if (group[i].num == 0)																											//
		{																																//만약 i그룹에 일정이 없으면
			continue;																													// for문 처음으로
		}																																//
		printf("  ├─────┼───┼───┼──┼");																									//틀(그룹과 그룹을 구별)
		for (int j = 1; j <= titleLenth; j++)																							//
		{																																//가장 큰 제목길이에 맞게 그림
			printf("─");																												//
		}																																//
		printf("┼");																													//구분선
		for (int j = 1; j <= contentLenth; j++)																							//
		{																																//위와 같음
			printf("─");																												//
		}																																//
		printf("┤\n");																													//
		for (int j = 0; j < group[i].num; j++)																							//
		{																																//일정의 갯수만큼 반복
			printf("%s│%04d.%02d.%02d│%02d:%02d │%d     │%s│",																			//틀
				   (count == cursorPlace) ? "▶" : "  ",																					//현재 가리키는 위치면 삼각형 화살표 출력, 아니면 공백 출력(삼항연산자가 정말로 좋군요)
				   group[i].schedule[j].year, group[i].schedule[j].month, group[i].schedule[j].day,										//
				   group[i].schedule[j].hour, group[i].schedule[j].min,																	//
				   group[i].schedule[j].important,																						//
				   groupName[i]);																										// i번째 그룹이름
			for (int k = 1; k <= titleLenth * 2; k++)																					//
			{																															//제목의 출력(스페이스바를 쓰므로 2를곱함
				if (titleLenth * 2 - k == strlen(group[i].schedule[j].title))															//
				{																														//앞으로 남은 공간이 제복의 길이와 같으면
					printf(" %s", group[i].schedule[j].title);																			//제목을 입력
					break;																												// for문 나감
				}																														//
				else																													//
					printf(" ");																										//아니므로 공백
			}																															//
			printf("│");																												//
			for (int k = 1; k <= contentLenth * 2; k++)																					//
			{																															//
				if (contentLenth * 2 - k == strlen(group[i].schedule[j].content))														//
				{																														//
					printf(" %s", group[i].schedule[j].content);																		//
					break;																												//
				}																														//
				else																													//
					printf(" ");																										//
			}																															//
			printf("│\n");																												//
			count++;																													//
		}																																//
	}																																	//
	printf("  └─────┴───┴───┴──┴");																										//틀
	for (int i = 1; i <= titleLenth; i++)																								//
	{																																	//
		printf("─");																													//
	}																																	//
	printf("┴");																														//
	for (int i = 1; i <= contentLenth; i++)																								//
	{																																	//
		printf("─");																													//
	}																																	//
	printf("┘\n");																														//
	return;																																//함수 종료
}

int scanSchedule()																								   //
{																												   //
	FILE *file = fopen("data.txt", "r");																		   //파일 열기
	if (file == NULL)																							   //
	{																											   //파일이 존재하지 않을경우
		puts("파일이 존재하지 않습니다!");																		   //
		puts("data.txt 파일이 존재하는지 확인하시고 다시 프로그램을 시작해 주십시오!");							   //
		puts("종료하려면 아무 키나 누르십시오 . . .");															   //경고
		system("pause>nul");																					   //아무키나 누를때까지 대기
		return 1;																								   //
	}																											   //
	while (!feof(file))																							   //
	{																											   //파일의 끝이 아닐경우
		int ymd, hm, imptnt, grp;																				   // ymd : year month day//hm : hour min
		char title[TITLE_MAX + 1], content[CONTENT_MAX + 1];													   //길이를 구해서 구조체에 저장(+1을 한 이유는 널문자'\0'까지 넣어야 하기 위해)
		fscanf(file, "%d %d %d %d %s %s",																		   //
			   &ymd, &hm, &imptnt, &grp, title, content);														   //입력 형식에 맞게 입력
		if (group[grp].num == group[grp].max)																	   //
		{																										   //현재 저장된 일정이 최대치이면
			group[grp].schedule = (Schedule *)realloc(group[grp].schedule, sizeof(Schedule) * group[grp].max * 2); //최대의 2배로 재할당
			group[grp].max *= 2;																				   //최대를 2배로
		}																										   //
		group[grp].schedule[group[grp].num].year = ymd / 10000;													   // 20170302->2017
		group[grp].schedule[group[grp].num].month = (ymd % 10000) / 100;										   // 20170302->0302->03
		group[grp].schedule[group[grp].num].day = ymd % 100;													   // 20170302->02
		group[grp].schedule[group[grp].num].hour = hm / 100;													   // 0900->09
		group[grp].schedule[group[grp].num].min = hm % 100;														   // 0900->00
		group[grp].schedule[group[grp].num].important = imptnt;													   //중요도
		group[grp].schedule[group[grp].num].title = (char *)malloc(strlen(title) + 1);							   //동적할당
		strcpy(group[grp].schedule[group[grp].num].title, title);												   //복사
		group[grp].schedule[group[grp].num].content = (char *)malloc(strlen(content) + 1);						   //
		strcpy(group[grp].schedule[group[grp].num].content, content);											   //
		group[grp].num++;																						   //
	}																											   //
	fclose(file);																								   //파일닫기
	return 0;																									   //함수종료
}

void printInformation(int num)																		  //
{																									  //자세한 정보 함수
	system("cls");																					  //화면 지우기
	int temp = 0;																					  //현재까지 지나친 일정의 수
	for (int i = 0; i < 5; i++)																		  //
	{																								  //그룹의 수
		for (int j = 0; j < group[i].num; j++)														  //
		{																							  // i번재 그룹의 일정 갯수
			if (temp == num)																		  //
			{																						  //지나친갯수와 출력할게 같으면
				printf("일시 : %04d년 %02d월 %02d일\n", group[i].schedule[j].year,					  //
					   group[i].schedule[j].month,													  //
					   group[i].schedule[j].day);													  //날짜 출력
				printf("시간 : %02d시%02d분\n", group[i].schedule[j].hour, group[i].schedule[j].min); //
				printf("중요도 : ");																  //중요도 출력
				for (int k = 0; k < 9; k++)															  //
				{																					  //
					printf("%s", (group[i].schedule[j].important > k) ? "★" : "☆");					  //꽉찬 별의 갯수가 중요도
				}																					  //
				printf("\n그룹 : %s\n", groupName[i]);												  //
				printf("제목 : %s\n", group[i].schedule[j].title);									  //
				printf("내용 : %s\n", group[i].schedule[j].content);								  //
				return;																				  //더 검색할 필요가 없으므로
			}																						  //
			temp++;																					  //지나친 일정 1개 추가
		}
	}
}

void newSchedule()																													//
{																																	//일정 추가
	system("cls");																													//화면 지우기
	int ymd, hm, imptnt, grp;																										// ymd : year month day//hm : hour min
	char title[TITLE_MAX + 1], content[CONTENT_MAX + 1];																			//길이를 구해서 구조체에 저장(+1을 한 이유는 널문자'\0'까지 넣어야 하기 위해)
	char temp[(TITLE_MAX > CONTENT_MAX) ? TITLE_MAX + 1 : CONTENT_MAX + 1];															//공백을 언더바로 바꾸기 위해서
	puts("일정을 추가합니다.");																										//입력
	printf("날짜를 입력하세요 : ");																									//
	scanf("%d", &ymd);																												//
	printf("시간을 입력하세요 : ");																									//
	scanf("%d", &hm);																												//
	printf("중요도를 입력하세요 : ");																								//
	scanf("%d", &imptnt);																											//
	printf("그룹을 입력하세요(0:%s/1:%s/2:%s/3:%s/4:%s) : ", groupName[0], groupName[1], groupName[2], groupName[3], groupName[4]); //
	scanf("%d", &grp);																												//
	printf("제목을 입력하세요(%d자 이내) : ", TITLE_MAX);																			//
	getchar();																														//앞에서의 버퍼 비우기
	gets(temp);																														//공백까지 입력
	blankToUnderBar(temp, title);																									//종백을 언더바로
	printf("내용을 입력하세요(%d자 이내) : ", CONTENT_MAX);																			//
	gets(temp);																														//
	blankToUnderBar(temp, content);																									//
	if (group[grp].num == group[grp].max)																							//
	{																																//현재 저장된 일정이 최대치이면
		group[grp].schedule = (Schedule *)realloc(group[grp].schedule, sizeof(Schedule) * group[grp].max * 2);						//최대의 2배로 재할당
		group[grp].max *= 2;																										//최대를 2배로
	}																																//
	group[grp].schedule[group[grp].num].year = ymd / 10000;																			// 20170302->2017
	group[grp].schedule[group[grp].num].month = (ymd % 10000) / 100;																// 20170302->0302->03
	group[grp].schedule[group[grp].num].day = ymd % 100;																			// 20170302->02
	group[grp].schedule[group[grp].num].hour = hm / 100;																			// 0900->09
	group[grp].schedule[group[grp].num].min = hm % 100;																				// 0900->00
	group[grp].schedule[group[grp].num].important = imptnt;																			//중요도
	group[grp].schedule[group[grp].num].title = (char *)malloc(strlen(title) + 1);													//동적할당
	strcpy(group[grp].schedule[group[grp].num].title, title);																		//복사
	group[grp].schedule[group[grp].num].content = (char *)malloc(strlen(content) + 1);												//
	strcpy(group[grp].schedule[group[grp].num].content, content);																	//
	group[grp].num++;																												// grp번재 그룹의 일정이 1개 늘어남
	FILE *file = fopen("data.txt", "a");																							//추가모드로 파일열기
	fprintf(file, "\n%08d %04d %d %d %s %s", ymd, hm, imptnt, grp, title, content);													//일정 추가
	fclose(file);																													//파일 닫기
}

void changeSchedule(int num)																													 //
{																																				 //일정 변경 함수
	system("cls");																																 //화면 지우기
	printInformation(num);																														 //자세한 정보 출력(보면서 수정)
	int temp = 0;																																 //지나친 일정의 수
	for (int i = 0; i < 5; i++)																													 //
	{																																			 // 5(그룹의 갯수)번반복
		for (int j = 0; j < group[i].num; j++)																									 //
		{																																		 // i번째 그룹의 일정 갯수만큼 반복
			if (temp == num)																													 //
			{																																	 //출력할 부분이면
				puts("\n일정을 수정합니다.");																									 //안내 메세지
				int ymd, hm, imptnt, grp;																										 //임시변수들
				char title[TITLE_MAX + 1], content[CONTENT_MAX + 1];																			 //임시변수들
				printf("날짜를 입력하세요 : ");																									 //입력
				scanf("%d", &ymd);																												 //
				printf("시간을 입력하세요 : ");																									 //
				scanf("%d", &hm);																												 //
				printf("중요도를 입력하세요 : ");																								 //
				scanf("%d", &imptnt);																											 //
				printf("그룹을 입력하세요(0:%s/1:%s/2:%s/3:%s/4:%s) : ", groupName[0], groupName[1], groupName[2], groupName[3], groupName[4]);	 //
				scanf("%d", &grp);																												 //
				printf("제목을 입력하세요(%d자 이내) : ", TITLE_MAX);																			 //
				scanf("%s", title);																												 //
				printf("내용을 입력하세요(%d자 이내) : ", CONTENT_MAX);																			 //
				scanf("%s", content);																											 //
				if (grp == i)																													 //
				{																																 //그룹이 바뀌지 않을경우
					group[i].schedule[j].year = ymd / 10000;																					 // 20170302->2017
					group[i].schedule[j].month = (ymd % 10000) / 100;																			 // 20170302->0302->03
					group[i].schedule[j].day = ymd % 100;																						 // 20170302->02
					group[i].schedule[j].hour = hm / 100;																						 // 0900->09
					group[i].schedule[j].min = hm % 100;																						 // 0900->00
					group[i].schedule[j].important = imptnt;																					 //중요도
					group[i].schedule[j].title = (char *)realloc(group[i].schedule[j].title, strlen(title) + 1);								 //동적할당
					strcpy(group[i].schedule[j].title, title);																					 //복사
					group[i].schedule[j].content = (char *)realloc(group[i].schedule[j].title, strlen(content) + 1);							 //
					strcpy(group[i].schedule[j].content, content);																				 //나머지 정보만 바꿈
					printScheduleFile();																										 //파일로 내보내기
					return;																														 //여기서 바로 종료
				}																																 //그룹이 바뀌는 부분
				for (int k = j + 1; k < group[i].num; k++)																						 //
				{																																 //없어질 일정 뒤의 일정들을
					group[i].schedule[k - 1] = group[i].schedule[k];																			 //앞으로 1칸씩 당긴다
				}																																 //
				group[i].num--;																													 //그룹이 바뀌므로 그 전 그룹의 일정 갯수 1개 감소
				if (group[grp].num == group[grp].max)																							 //
				{																																 //현재 저장된 일정이 최대치이면
					group[grp].schedule = (Schedule *)realloc(group[grp].schedule, sizeof(Schedule) * group[grp].max * 2);						 //최대의 2배로 재할당
					group[grp].max *= 2;																										 //최대를 2배로
				}																																 //
				group[grp].schedule[group[grp].num].year = ymd / 10000;																			 // 20170302->2017
				group[grp].schedule[group[grp].num].month = (ymd % 10000) / 100;																 // 20170302->0302->03
				group[grp].schedule[group[grp].num].day = ymd % 100;																			 // 20170302->02
				group[grp].schedule[group[grp].num].hour = hm / 100;																			 // 0900->09
				group[grp].schedule[group[grp].num].min = hm % 100;																				 // 0900->00
				group[grp].schedule[group[grp].num].important = imptnt;																			 //중요도
				group[grp].schedule[group[grp].num].title = (char *)realloc(group[grp].schedule[group[grp].num].title, strlen(title) + 1);		 //동적할당
				strcpy(group[grp].schedule[group[grp].num].title, title);																		 //복사
				group[grp].schedule[group[grp].num].content = (char *)realloc(group[grp].schedule[group[grp].num].content, strlen(content) + 1); //
				strcpy(group[grp].schedule[group[grp].num].content, content);																	 //
				group[grp].num++;																												 // grp번재 그룹의 일정이 1개 늘어남
				printScheduleFile();																											 //파일로 내보내기
				initializeGroup();																												 //파일에서 다시 불러온다
				return;																															 //종료
			}																																	 //
			temp++;																																 //지나친 일정 1개 추가
		}
	}
}

void printScheduleFile()									  //
{															  //파일로 일정 출력 함수
	FILE *file = fopen("data.txt", "w");					  //쓰기 모드로 파일열기
	file = fopen("data.txt", "w");							  //
	for (int i = 0; i < 5; i++)								  //
	{														  //그룹갯수만큼반복
		if (group[i].num == 0)								  //
			continue;										  //
		for (int j = 0; j < group[i].num; j++)				  //
		{													  // i번째 그룹의 일정 갯수
			int ymd, hm;									  //미리 계산
			ymd = group[i].schedule[j].year * 10000 +		  //
				  group[i].schedule[j].month * 100 +		  //
				  group[i].schedule[j].day;					  //
			hm = group[i].schedule[j].hour * 100 +			  //
				 group[i].schedule[j].min;					  //
			fprintf(file, "\n%08d %04d %d %d %s %s", ymd, hm, //
					group[i].schedule[j].important, i,		  //
					group[i].schedule[j].title,				  //
					group[i].schedule[j].content);			  //
		}													  //
	}														  //
	fclose(file);											  //파일닫기
}

void initializeGroup()																													 //
{																																		 //파일로부터 일정 다시설정
	FILE *file = fopen("data.txt", "r");																								 //파일을 읽기모드로
	for (int i = 0; i < 5; i++)																											 //
	{																																	 //
		group[i].num = 0;																												 //
		group[i].schedule = (Schedule *)realloc(group[i].schedule, sizeof(Schedule) * 8);												 //
		group[i].max = 8;																												 //
	}																																	 //할당을 초기화
	while (!feof(file))																													 //
	{																																	 //파일의 끝이 아닐경우
		int ymd, hm, imptnt, grp;																										 // ymd : year month day//hm : hour min
		char title[TITLE_MAX + 1], content[CONTENT_MAX + 1];																			 //길이를 구해서 구조체에 저장(+1을 한 이유는 널문자'\0'까지 넣어야 하기 위해)
		fscanf(file, "%d %d %d %d %s %s",																								 //
			   &ymd, &hm, &imptnt, &grp, title, content);																				 //입력 형식에 맞게 입력
		if (group[grp].num == group[grp].max)																							 //
		{																																 //현재 저장된 일정이 최대치이면
			group[grp].schedule = (Schedule *)realloc(group[grp].schedule, sizeof(Schedule) * group[grp].max * 2);						 //최대의 2배로 재할당
			group[grp].max *= 2;																										 //최대를 2배로
		}																																 //
		group[grp].schedule[group[grp].num].year = ymd / 10000;																			 // 20170302->2017
		group[grp].schedule[group[grp].num].month = (ymd % 10000) / 100;																 // 20170302->0302->03
		group[grp].schedule[group[grp].num].day = ymd % 100;																			 // 20170302->02
		group[grp].schedule[group[grp].num].hour = hm / 100;																			 // 0900->09
		group[grp].schedule[group[grp].num].min = hm % 100;																				 // 0900->00
		group[grp].schedule[group[grp].num].important = imptnt;																			 //중요도
		group[grp].schedule[group[grp].num].title = (char *)realloc(group[grp].schedule[group[grp].num].title, strlen(title) + 1);		 //동적할당
		strcpy(group[grp].schedule[group[grp].num].title, title);																		 //복사
		group[grp].schedule[group[grp].num].content = (char *)realloc(group[grp].schedule[group[grp].num].content, strlen(content) + 1); //
		strcpy(group[grp].schedule[group[grp].num].content, content);																	 //
		group[grp].num++;																												 //
	}																																	 //
	fclose(file);																														 //파일닫기
	return;																																 //함수종료
}

void deleteSchedule(int num)										 //
{																	 //일정 지우기
	int temp = 0;													 //지나친 일정의 수
	for (int i = 0; i < 5; i++)										 //
	{																 // 5(그룹의 갯수)번반복
		for (int j = 0; j < group[i].num; j++)						 //
		{															 // i번째 그룹의 일정 갯수만큼 반복
			if (temp == num)										 //
			{														 //지울 부분이면
				for (int k = j + 1; k < group[i].num; k++)			 //
				{													 //없어질 일정 뒤의 일정들을
					group[i].schedule[k - 1] = group[i].schedule[k]; //앞으로 1칸씩 당긴다
				}													 //
				group[i].num--;										 //그룹이 바뀌므로 그 전 그룹의 일정 갯수 1개 감소
				printScheduleFile();								 //파일로 내보내기
				return;												 //종료
			}														 //
			temp++;													 //지나친 일정 1개 추가
		}
	}
}

void blankToUnderBar(char *from, char *to)	//
{											//공백을 언더바로 바꾸는 함수
	while (*from != '\0')					//
	{										//시작 문장의 길이만큼 반복
		*to = (*from == ' ') ? '_' : *from; //도착 문장의 조사하는 글자는 시작 문장의 조사하는 글자가 공백일경우는 언더바로, 아니면 그 글자 그대로 저장
		from++;								//그 다음 글자를 조사
		to++;								//그 다음 글자를 조사
	}										//
	*to = '\0';								//도착 문장의 마지막 글자를 널문자로(오류해소)
	return;									// void형 함수이므로
}
