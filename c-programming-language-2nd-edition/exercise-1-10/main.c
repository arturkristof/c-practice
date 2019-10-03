#include <stdio.h>

#define TAB '\t'
#define BACKSPACE '\b'
#define BACKSLASH '\\'

/* Copy input to output replacing each tab, backspace and backslash
    by "\t", "\b" and "\\" respectively */

int main()
{
    char input;

    while ((input = getchar()) != EOF)
    {
        switch (input)
        {
        case TAB:
            printf("\\t");
            break;
        case BACKSPACE:
            printf("\\b");
            break;
        case BACKSLASH:
            printf("\\\\");
            break;
        default:
            putchar(input);
            break;
        }
    }
}