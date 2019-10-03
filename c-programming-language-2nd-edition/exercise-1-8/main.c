#include <stdio.h>

#define BLANK '\b'
#define TAB '\t'
#define NEW_LINE '\n'

int main()
{
    int blanks_count = 0;
    int tab_count = 0;
    int new_line_count = 0;

    char input;
    while ((input = getchar()) != EOF) 
    {
        switch (input)
        {
        case BLANK:
            ++blanks_count;
            break;
        case TAB:
            ++tab_count;
            break;
        case NEW_LINE:
            ++new_line_count;
            break;
        default:
            break;
        }
    }
}