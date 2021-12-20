#include <stdio.h>

int main()
{
    int applePrice, appleCount;
    int pearPrice, pearCount;
    int bananaPrice, bananaCount;
    int money;

    printf("Enter the price of apple:");
    scanf("%d", &applePrice);
    printf("Enter the number of apple:");
    scanf("%d", &appleCount);

    printf("Enter the price of pear:");
    scanf("%d", &pearPrice);
    printf("Enter the number of pear:");
    scanf("%d", &pearCount);

    printf("Enter the price of banana:");
    scanf("%d", &bananaPrice);
    printf("Enter the number of banana:");
    scanf("%d", &bananaCount);

    printf("Give me money:");
    scanf("%d", &money);

    int sum = applePrice * appleCount + pearPrice * pearCount + bananaPrice * bananaCount;

    printf("Sum: %d\n", sum);
    printf("Money: %d\n", money);
    printf("Exchange: %d\n", money - sum);

    return 0;
}