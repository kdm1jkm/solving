#include <stdio.h>

int main()
{
    char a;
    printf("Enter alphabet:");
    scanf("%c", &a);

    if (a >= 'a' && a <= 'z')
    {
        printf("%c is small letter, ascii: %d", a, a);
    }
    else if (a >= 'A' && a <= 'Z')
    {
        printf("%c is big letter, ascii: %d", a, a);
    }

    return 0;
}