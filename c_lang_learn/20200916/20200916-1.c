#include <stdio.h>

int main()
{
    int price;
    double euro, dollar;
    printf("Enter price(EURO):");
    scanf("%d", &price);

    euro = price * 1403.79;
    dollar = price * 1.19 * 1183;

    printf("Euro: %.2f\ndollar: %.2f\n", euro, dollar);
    printf("Diff: %.2f", -euro + dollar);

    return 0;
}