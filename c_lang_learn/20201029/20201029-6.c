#include <stdio.h>
#include <stdlib.h>

// return 1: prime number
// return -1: Invalid paramater
// return other number: paramter cna be devided into returned number.
int isPrime(int num)
{
    if (num < 2)
        return -1;
    if (num == 2)
        return 1;
    if (num % 2 == 0)
    {
        return 2;
    }

    int i = 1;
    while ((i += 2) < (num + 1) / 2)
    {
        if (num % i == 0)
        {
            return i;
        }
    }
    return 1;
}

int main()
{
    int num;
    printf("Enter number>>");
    scanf("%d", &num);

    int sum = 0;
    int i = 0;
    while (i++ < num)
    {
        if (isPrime(i) == 1)
        {
            printf("%d ", i);
            sum += i;
        }
    }
    printf("\nsum: %d\n", sum);
    return 0;
}