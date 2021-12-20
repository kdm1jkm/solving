//==================================코드설명===========================================
// 이 프로그램은 input.txt파일의 내용을 입력받아서 출력하는 프로그램이다.
// 도전과제5의 코드에서 입력 부분을 사용자에서 파일로 바꾸고,
// 출력내용을 전체에서 각 그룹에 들어있는 원소의 갯수로 바꾼것이다.
// 조금 더 코드를 짧게 할 수 있었으나 어딘지 알 수 없는 곳에서 오류가 나서 더 짧게 하지 못했다
//=====================================================================================

#define TITLE_MAX 127	// 제목 최대 글자수
#define CONTENT_MAX 127 // 내용 최대 글자수

#include <stdio.h>	// 표준 입출력
#include <stdlib.h> // 메모리 할당을 하기위해
#include <string.h> // strlen, strcpy함수 사용을 위해

typedef struct			  // 구조체 선언
{						  //
	int year, month, day; // 년, 월, 일
	int hour, min;		  // 시간, 분
	int important;		  // 중요도
	int group;			  // 그룹
	char *title;		  // 제목(글자수에 맞추기 위해서 포인터 변수. 나중에 할당)
	char *content;		  // 내용
} Schedule;				  // Schedule형 완성

//=================================================================================================================================

int main()																								 // 메인 함수
{																										 //
	Schedule *schedule;																					 // 저장할 데이터의 시작점
	Schedule *buffer;																					 // 계속 이동할 포인터
	FILE *file = fopen("input.txt", "r");																 // 지정된 파일을 읽기 전용으로 열기
	int count;																							 // 갯수
	int group[5] = {0, 0, 0, 0, 0};																		 // 각 그룹에 들어간 원소의 갯수를 구하기 위해서
	fscanf(file, "%d", &count);																			 // 갯수 입력
	schedule = (Schedule *)malloc(sizeof(Schedule) * count);											 // 갯수만큼 메모리 할당
	buffer = schedule;																					 // 앞에서부터 입력
	for (int i = 0; i < count; i++)																		 //
	{																									 // 갯수만큼 반복
		int buf1, buf2;																					 // 나중에 쪼갬
		char buf3[TITLE_MAX + 1], buf4[CONTENT_MAX + 1];												 // 길이를 구해서 구조체에 저장(+1을 한 이유는 널문자'\0'까지 넣어야 하기 위해)
		fscanf(file, "%d %d %d %d %s %s", &buf1, &buf2, &buffer->important, &buffer->group, buf3, buf4); // 입력받기
		buffer->year = buf1 / 10000;																	 // 나머지는 버리므로
		buffer->month = (buf1 - buffer->year * 10000) / 100;											 // 나머지는 버리므로(20170302-(2017*10000))/100->03
		buffer->day = (buf1 % 100);																		 // 100으로 나눈 나머지는 위에건 다 잘라 버린다(20170302->02)
		buffer->hour = buf2 / 100;																		 // 위와 같음
		buffer->min = (buf2 % 100);																		 // 위와 같음
		buffer->title = (char *)malloc(sizeof(char) * strlen(buf3));									 // 문자의 길이만큼 메모리 할당
		strcpy(buffer->title, buf3);																	 // 문자열 복사
		buffer->content = (char *)malloc(sizeof(char *) * strlen(buf4));								 // 문자열 길이만큼 메모리 할당
		strcpy(buffer->content, buf4);																	 // 문자열 복사
		buffer++;																						 // 그 다음 자료
	}																									 //
	buffer = schedule;																					 // 처음부터 조사
	for (int i = 0; i < count; i++)																		 //
	{																									 // 갯수만큼 반복
		group[buffer->group]++;																			 // 그룹갯수 카운트(0이면 group[0]에 1을 더함. 아까 0으로 초기화한 이유는 이것때문)
		buffer++;																						 // 그 다음 자료
	}																									 //
	printf("%d %d %d %d %d", group[0], group[1], group[2], group[3], group[4]);							 // 출력
	buffer = schedule;																					 // 다시 처음으로
	for (int i = 0; i < count; i++)																		 //
	{																									 // 갯수만큼 반복
		free(buffer->title);																			 // 제목 메모리 할당해제
		free(buffer->content);																			 // 내용 메모리 할당해제
		buffer++;																						 // 그 다음 자료
	}																									 //
	free(schedule);																						 // 멤버를 모두 할당해제 후 구조체 포인터 메모리 할당하제
	fclose(file);																						 //
	return 0;																							 // 정상종료
}
