#include <stdio.h>

int main()
{
    int totalMoney;
    printf("Enter Money:");
    scanf("%d", &totalMoney);
    printf("50000(%d) 10000(%d) 5000(%d) 1000(%d) 500(%d) 100(%d) 50(%d) 10(%d)",
           totalMoney / 50000,
           totalMoney / 10000 % 5,
           totalMoney / 5000 % 2,
           totalMoney / 1000 % 5,
           totalMoney / 500 % 2,
           totalMoney / 100 % 5,
           totalMoney / 50 % 2,
           totalMoney / 10 % 5);

    return 0;
}