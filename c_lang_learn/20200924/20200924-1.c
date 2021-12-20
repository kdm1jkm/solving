#include <stdio.h>

int main()
{
    int num1, num2;
    char symbol;
    printf("Enter >>");
    scanf("%d %c %d", &num1, &symbol, &num2);

    switch (symbol)
    {
    case '+':
        printf("%d + %d = %d", num1, num2, num1 + num2);
        break;
    case '-':
        printf("%d - %d = %d", num1, num2, num1 - num2);
        break;
    case '*':
        printf("%d * %d = %d", num1, num2, num1 * num2);
        break;
    case '/':
        printf("%d / %d = %d", num1, num2, num1 / num2);
        break;
    case '%':
        printf("%d %% %d = %d", num1, num2, num1 % num2);
        break;
    default:
        printf("Enter appropriate symbol.\n");
        break;
    }

    return 0;
}