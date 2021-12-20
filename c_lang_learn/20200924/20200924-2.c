#include <stdio.h>

int main()
{
    char grade;
    printf("Enter grade>>");
    scanf("%c", &grade);

    int price;

    switch (grade)
    {
    case 'A':
    case 'a':
        price = 45000;
        break;
    case 'B':
    case 'b':
        price = 35000;
        break;
    case 'C':
    case 'c':
        price = 20000;
        break;
    case 'D':
    case 'd':
        price = 10000;
        break;
    }

    printf("price: %d\n", price);

    return 0;
}