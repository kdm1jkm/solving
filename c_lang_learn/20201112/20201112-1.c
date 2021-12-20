#include <stdio.h>

#define STRING_LENGTH 100

int main()
{
    char schoolname[STRING_LENGTH], name[STRING_LENGTH], studentNum[STRING_LENGTH];
    printf("Enter school name>>");
    fgets(schoolname, STRING_LENGTH, stdin);
    fflush(stdin);

    printf("Enter student number>>");
    fgets(studentNum, STRING_LENGTH, stdin);
    fflush(stdin);

    printf("Enter name>>");
    fgets(name, STRING_LENGTH, stdin);
    fflush(stdin);

    printf("%s highschool %cgrade %cclass num: %c%c name: %s\n", schoolname, studentNum[0], studentNum[1], studentNum[2], studentNum[3], name);
}