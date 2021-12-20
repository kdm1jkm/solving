#include <stdio.h> // 헤더파일

int isSame(char *str1, char *str2);			// 문자열이 동일한지 검사하는 함수
void blankToUnderBar(char *from, char *to); // 공백을 언더바('_')로 바꾸는 함수

int main()													 // 메인 함수
{															 //
	char str1[100], str2[100], str3[100];					 // 변수 선언(1번 문장, 2번 문장, 공백을 언더바로 바꿀 문장)
															 //
	gets(str1);												 // 입력
	gets(str2);												 // 입력
															 //
	printf("%s\n", (isSame(str1, str2)) ? "true" : "false"); // 두 문장이 같으면 "true" 출력, 다르면 "false" 출력.(삼항연산자)
															 //
	blankToUnderBar(str1, str3);							 // 1번문장의 공백을 언더바로 고친후 그것을 3번문장으로 옮긴다.
															 //
	printf("%s", str3);										 // 3번문장 출력
															 //
	return 0;												 // 정상종료
}

int isSame(char *str1, char *str2) // 문장이 같은지 조사하는 함수
{								   //
	while (*str1 != '\0')		   // 1번 문장의 조사하는 부분이 널문자가 아닐 동안(1번문장의 길이만큼 반복)
	{							   //
		if (*str1 != *str2)		   // 1번문장의 조사하는 부분과 2번분장의 조사하는 부분이 다르면
			return 0;			   // false 반환
								   //
		str1++;					   //그 다음 글자를 조사
		str2++;					   //그 다음 글자를 조사
	}							   //
								   //
	if (*str2 != '\0')			   // 앞은 같지만 2번문장이 뒤어 더 있을경우
		return 0;				   // false 반환
								   //
	return 1;					   // 위의 조건을 다 통과했을경우는 같은 문장이므로 true(1) 반환
}

void blankToUnderBar(char *from, char *to)	// 공백을 언더바로 바꾸는 함수
{											//
	while (*from != '\0')					// 시작 문장의 길이만큼 반복
	{										//
		*to = (*from == ' ') ? '_' : *from; // 도착 문장의 조사하는 글자는 시작 문장의 조사하는 글자가 공백일경우는 언더바로, 아니면 그 글자 그대로 저장
		from++;								// 그 다음 글자를 조사
		to++;								// 그 다음 글자를 조사
	}										//
											//
	*to = '\0';								// 도착 문장의 마지막 글자를 널문자로(오류해소)
}
