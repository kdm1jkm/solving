#include <stdio.h> //헤더파일
#include <string.h>

int isPal(char word[32], int num); // 함수 원형

int main()											   // 메인 함수
{													   //
	char word[32];									   // 단어 변수 선언
	scanf("%s", word);								   // 단어 입력
	printf("%s", (isPal(word, 0)) ? "true" : "false"); // 단어가 회문이면 true, 아니면 false출력.(삼항연산자 사용)
}

int isPal(char word[32], int num)		   // 함수 선언 num인수는 몇번째 글자를 비교할지 나타냄(ex.0이면 0번째와 길이-0, 3이면 3번째와 길이-3등)
{										   //
	int len = strlen(word) - 1;			   // 길이 변수(1을빼는 이유는 실제 길이와 마지막 글자의 수가 안맞기 때문.ex)apple길이:5, 마지막글자:4, 첫번째글자:0)
										   //
	if (2 * num + 1 > len)				   // num인수가 길이의 반이 되면
		return 1;						   // 그냥 true를 반환
	else if (word[num] != word[len - num]) // 비교하는 두 글자가 다르면
		return 0;						   // false 반환
	else								   // 비교하는 두 글자가 같으면
		return isPal(word, num + 1);	   // 그 다음 두글자를 반환
}
