#include <stdio.h>

#define NUMBER_OF_ASCII_CHARS 256
#define TAB '\t'
#define NEW_LINE '\n'

/* Histogram of frequencies of different characters in input */

int main()
{
    int character_count[NUMBER_OF_ASCII_CHARS];

    for (int i = 0; i < NUMBER_OF_ASCII_CHARS; ++i)
    {
        character_count[i] = 0;
    }

    char input;
    while ((input = getchar()) != EOF)
    {
        ++character_count[input];
    }

    int max_character_count = 0;
    for (int i = 0; i < NUMBER_OF_ASCII_CHARS; ++i)
    {
        if (character_count[i] > max_character_count)
        {
            max_character_count = character_count[i];
        }
    }

    printf("\nNumber of chars\n");
    for (int i = max_character_count; i > 0; --i)
    {
        printf("%15d", i);
        int previous_character_count_index = -1;
        for (int j = 0; j < NUMBER_OF_ASCII_CHARS; ++j)
        {
            if (character_count[j] >= i)
            {
                int number_of_tabs_to_print;
                if (previous_character_count_index < 0)
                {
                    number_of_tabs_to_print = j + 1;
                }
                else
                {
                    number_of_tabs_to_print = j - previous_character_count_index;
                }
                previous_character_count_index = j;

                for (int k = 1; k <= number_of_tabs_to_print; ++k)
                {
                    putchar(TAB);
                }
                putchar('|');
            }
        }
        putchar(NEW_LINE);
    }

    printf("%15s", "Char");
    for (int i = 0; i < NUMBER_OF_ASCII_CHARS; ++i)
    {
        printf("%c%c", TAB, i);
    }
    putchar(NEW_LINE);
}