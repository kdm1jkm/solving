#include <stdio.h> // 표준 라이브러리 포함

// 함수 원형
double av(int num, int nums[100]);
double di(int num, int nums[100]);
int max(int num, int nums[100]);
int min(int num, int nums[100]);
int pow(int num);

int main()							 // 메인 함수
{									 //
	int num, nums[100];				 // 변수 선언
	scanf("%d", &num);				 // 갯수 입력
	for (int i = 0; i < num; i++)	 // 갯수만큼 반복
		scanf("%d", &nums[i]);		 // 값 입력
	printf("%.4f\n", av(num, nums)); // 평균 출력(소수점 4자리까지)
	printf("%.4f\n", di(num, nums)); // 분산 출력
	printf("%d\n", max(num, nums));	 // 최댓값 출력
	printf("%d\n", min(num, nums));	 // 최솟값 출력
	return 0;						 // 정상종료
}

int pow(int num)	  //제곱 함수
{					  //
	return num * num; //제곱을 반환
}

double av(int num, int nums[100]) // 평균 함수
{								  //
	int result = 0;				  // 결과값 선언과 초기화
	for (int i = 0; i < num; i++) // 갯수만큼 반복
		result += nums[i];		  // 모두 더한다
	result /= num;				  // 전체 합에서 갯수로 나눔(평균)
	return result;				  // 평균값 반환
}

double di(int num, int nums[100])	// 분산 함수
{									//
	int result = 0;					// 결과값 선언과 초기화
	int m = av(num, nums);			// 평균값 계산
	for (int i = 0; i < num; i++)	// 갯수만큼 반복
		result += pow(nums[i] - m); // 분산값 공식
	result /= num;					// 분산값 공식
	return result;					// 분산값 반환
}

int max(int num, int nums[100])							// 최댓값 함수
{														//
	int result = nums[0];								// 0으로 대입했을시 모든 수가 음수일수 있으므로 첫번째수 대입
	for (int i = 1; i < num; i++)						//
	{													// 0번째수는 이미 대입했으므로 i변수를 1로 초기화
		result = (result > nums[i]) ? result : nums[i]; // 삼항연산자 사용. 현재값과 비교값중 더 큰것을 현재값에 넣는다.
	}													//
	return result;										//결과값 반환
}

int min(int num, int nums[100])							// 최솟값 함수
{														//
	int result = nums[0];								// 0으로 대입했을시 모든 수가 양수일수 있으므로 첫번째수 대입
	for (int i = 1; i < num; i++)						// 0번째수는 이미 했으므로 i변수를 1로 초기화
		result = (result < nums[i]) ? result : nums[i]; // 삼항연산자 사용. 현재값과 비교값중 더 작은것을 현재값에 넣는다.
	return result;										// 결과값 반환
}
