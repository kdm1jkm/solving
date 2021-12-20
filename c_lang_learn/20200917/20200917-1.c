#include <stdio.h>

int main()
{
    // Condition ? true : false
    int num;
    printf("Enter num:");
    scanf("%d", &num);

    printf("%d is %s", num, (num % 2 == 0) ? "even" : "odd");

    return 0;
}