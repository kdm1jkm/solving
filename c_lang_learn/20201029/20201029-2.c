#include <stdio.h>

int main()
{
    int num;
    printf("Enter number>>");
    scanf("%d", &num);

    int oddSum, evenSum;
    oddSum = evenSum = 0;

    int i = 0;

    while (i++ < num)
    {
        if (i % 2 == 0)
            evenSum += i;
        else
            oddSum += i;
    }
    printf("oddSum:%d, evenSum:%d, sum:%d\n", oddSum, evenSum, oddSum + evenSum);
}