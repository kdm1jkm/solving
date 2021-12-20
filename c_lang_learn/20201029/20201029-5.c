#include <stdio.h>

int main()
{
    int num;
    printf("Enter number>>");
    scanf("%d", &num);
    if (num < 2)
        return -1;
    if (num == 2)
    {
        printf("%d is prime number\n", num);
        return 0;
    }
    if (num % 2 == 0)
    {
        printf("%d is not prime number(2 * %d = %d)\n", num, num / 2, num);
        return 0;
    }

    int i = 1;
    while ((i += 2) < (num + 1) / 2)
    {
        if (num % i == 0)
        {
            printf("%d is not prime number(%d * %d = %d)\n", num, i, num / i, num);
            return 0;
        }
    }
    printf("%d is prime number\n", num);
    return 0;
}