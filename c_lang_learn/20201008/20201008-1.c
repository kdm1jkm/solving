#include <stdio.h>

int main()
{
    // 다섯번 출력하기
    for (int i = 0; i < 5; ++i)
    {
        printf("C programming language.\n");
    }

    // 1-5 출력하기
    for (int i = 0; i < 5; ++i)
    {
        printf("%d\n", i + 1);
    }

    // 5-1 츨력하기 (1)
    for (int i = 0; i < 5; ++i)
    {
        printf("%d\n", 5 - i);
    }

    // 5-1 출력하기 (2)
    for (int i = 5; i > 0; --i)
    {
        printf("%d\n", i);
    }

    int sum = 0;

    // 1-10합
    for (int i = 0; i < 10; ++i)
    {
        sum += (i + 1);
    }
    printf("Sum: %d\n", sum);

    // 100미만 3의 배수의 합
    sum = 0;
    for (int i = 3; i < 100; i += 3)
    {
        sum += i;
    }
    printf("sum: %d\n", sum);

    // 입력받은 수만큼 3의배수 출력
    int count;
    printf("Enter count>>");
    scanf("%d", &count);
    for (int i = 0; i < count; ++i)
    {
        if (i % 10 == 0)
            printf("\n");
        printf("%4d", (i + 1) * 3);
    }
    printf("\n");

    // 1 + 3 + 5...n의 합이 1000을 넘는 n 찾기 (1)
    int n;
    for (n = 1, sum = 0; sum < 1000; n += 2)
    {
        sum += n;
    }
    printf("n: %d\n", n);

    // 1 + 3 + 5...n의 합이 1000을 넘는 n 찾기 (2)
    n = 1;
    sum = 0;
    while (sum < 1000)
    {
        sum += n;
        n += 2;
    }
    printf("n: %d\n", n);

    return 0;
}