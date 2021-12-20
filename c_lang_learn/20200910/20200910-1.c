#include <stdio.h>

int main()
{
    int userInput;
    printf_s("Enter second:");
    scanf_s("%d", &userInput);

    printf("--------Method1--------\n");
    int h1, m1, s1;
    h1 = userInput / 60 / 60;
    m1 = (userInput - h1 * 60 * 60) / 60;
    s1 = (userInput - h1 * 60 * 60 - m1 * 60);
    printf("%d = %02d : %02d : %02d\n", userInput, h1, m1, s1);

    printf("--------Method2--------\n");
    int h2, m2, s2;
    s2 = userInput % 60;
    m2 = (userInput / 60) % 60;
    h2 = (userInput / 60 / 60) % 60;
    printf("%d = %02d : %02d : %02d\n", userInput, h2, m2, s2);

    return 0;
}