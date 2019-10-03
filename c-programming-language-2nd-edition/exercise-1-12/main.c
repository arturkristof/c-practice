#include <stdio.h>

#define TAB '\t'
#define NEW_LINE '\n'
#define BLANK ' '
#define TRUE 1
#define FALSE 0

/* Print input one word per line */

int main()
{
    char input;
    int is_new_line = TRUE;

    while ((input = getchar()) != EOF)
    {
        if ((input == TAB || input == NEW_LINE || input == BLANK) && !is_new_line)
        {
            putchar('\n');
            is_new_line = TRUE;
        }
        else
        {
            putchar(input);
            is_new_line = FALSE;
        }
    }
}