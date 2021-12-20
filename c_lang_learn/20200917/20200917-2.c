#include <stdio.h>

int main()
{
    // Condition ? true : false
    int num1, num2, max, min;
    printf("Enter num1:");
    scanf("%d", &num1);
    printf("Enter num2:");
    scanf("%d", &num2);

    max = num1 > num2 ? num1 : num2;
    min = num1 < num2 ? num1 : num2;

    printf("%d / %d = %d ... %d", max, min, max / min, max % min);

    return 0;
}