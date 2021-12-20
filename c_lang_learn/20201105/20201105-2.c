#include <stdio.h>

int main()
{
    int scores[3];
    for (int i = 0; i < 3; i++)
    {
        printf("Enter #%d>>", i + 1);
        scanf("%d", scores + i);
    }
    int sum = 0;
    for (int i = 0; i < 3; i++)
    {
        sum += scores[i];
    }
    printf("Sum: %d, Average: %f\n", sum, sum / 3.0);
}