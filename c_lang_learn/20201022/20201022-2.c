#include <stdio.h>

int main()
{
    int num;
    printf("몇 명>>");
    scanf("%d", &num);

    int sum = 0;
    int acceptance = 0;
    for (int i = 0; i < num; i++)
    {
        int score;
        printf("%d번의 점수>>", i + 1);
        scanf("%d", &score);

        sum += score;
        if (score >= 70)
            acceptance++;
    }

    printf("=========================\n");
    printf("평균: %f\n", sum / (float)num);
    printf("합격자수: %d\n", acceptance);
    printf("탈락자수: %d\n", num - acceptance);

    return 0;
}