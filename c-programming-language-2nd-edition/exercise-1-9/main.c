#include <stdio.h>

#define BLANK ' '

/* Copy input to output replacing >1 blanks with 1 blank */

int main()
{
    char input;
    char previous_input;

    input = getchar();

    while (input != EOF) 
    {
        if (input != BLANK)
        {
            if (previous_input == BLANK)
            {
                putchar(BLANK);
            }

            putchar(input);
        }

        previous_input = input;
        input = getchar();
    }
}