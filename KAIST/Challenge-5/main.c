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
	char *title;		  // 제목(글자수에 맞추기 위해서 포인터 변수. 나중에 할당)
	char *content;		  // 내용
} Schedule;				  // Schedule형 완성

// ========================================================================================================================================================

int main()																	   // 메인함수
{																			   //
	Schedule *schedule;														   // 저장할 데이터의 시작점
	Schedule *buffer;														   // 계속 이동할 포인터
	int count;																   // 갯수
	scanf("%d", &count);													   // 갯수 입력받음
	schedule = (Schedule *)malloc(sizeof(Schedule) * count);				   // 갯수만큼 메모리 할당
	buffer = schedule;														   // 앞에서부터 입력
	for (int i = 0; i < count; i++)											   // 갯수만큼 반복
	{																		   //
		int buf1, buf2;														   // 나중에 쪼갬
		char buf3[TITLE_MAX + 1], buf4[CONTENT_MAX + 1];					   // 길이를 구해서 구조체에 저장(+1을 한 이유는 널문자'\0'까지 넣어야 하기 위해)
		scanf("%d %d %d %s %s", &buf1, &buf2, &buffer->important, buf3, buf4); // 순서대로 입력받음
		buffer->year = buf1 / 10000;										   // 나머지는 버리므로
		buffer->month = (buf1 - buffer->year * 10000) / 100;				   // 나머지는 버리므로(20170302-(2017*10000))/100->03
		buffer->day = (buf1 % 100);											   // 100으로 나눈 나머지는 위에건 다 잘라 버린다(20170302->02)
		buffer->hour = buf2 / 100;											   // 위와 같음
		buffer->min = (buf2 % 100);											   // 위와 같음
		buffer->title = (char *)malloc(sizeof(char) * strlen(buf3));		   // 문자의 길이만큼 메모리 할당
		strcpy(buffer->title, buf3);										   // 문자열 복사
		buffer->content = (char *)malloc(sizeof(char *) * strlen(buf4));	   // 문자열 길이만큼 메모리 할당
		strcpy(buffer->content, buf4);										   // 문자열 복사
		buffer++;															   // 그 다음 자료
	}																		   //
	buffer = schedule;														   // 다시 처음으로 돌아옴
	for (int i = 0; i < count; i++)											   // 갯수만큼 반복
	{																		   //
		printf("%4d.%02d.%02d. %02d:%02d %d %s %s\n",						   // 출력 설명에 맞게 출력
			   buffer->year, buffer->month, buffer->day,					   //
			   buffer->hour, buffer->min,									   //
			   buffer->important,											   //
			   buffer->title, buffer->content);								   //
		buffer++;															   // 그 다음 자료
	}																		   //
	buffer = schedule;														   // 다시 처음으로
	for (int i = 0; i < count; i++)											   //
	{																		   // 갯수만큼 반복
		free(buffer->title);												   // 제목 메모리 할당해제
		free(buffer->content);												   // 내용 메모리 할당해제
		buffer++;															   // 그 다음 자료
	}																		   //
	free(schedule);															   // 멤버를 모두 할당해제 후 구조체 포인터 메모리 할당하제
	return 0;																   // 정상종료
}
