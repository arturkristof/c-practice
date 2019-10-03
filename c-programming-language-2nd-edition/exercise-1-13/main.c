#include <stdio.h>

#define BLANK ' '
#define NEW_LINE '\n'
#define TAB '\t'
#define MAX_WORD_LENGTH 10
#define MIN_WORD_LENGTH 1

/* Print histogram of the lengths of words in input */

int main()
{
    int number_of_words[MAX_WORD_LENGTH];

    int current_word_length = 0;
    char input;

    for (int i = 0; i < MAX_WORD_LENGTH; ++i)
    {
        number_of_words[i] = 0;
    }

    while ((input = getchar()) != EOF)
    {
        if (input == BLANK || input == NEW_LINE || input == TAB)
        {
            if (current_word_length >= MIN_WORD_LENGTH && current_word_length <= MAX_WORD_LENGTH)
            {
                ++number_of_words[current_word_length - 1];
            }
            current_word_length = 0;
        }
        else 
        {
            ++current_word_length;
        }
    }

    int max_number_of_words_with_the_same_length = 0;
    for (int i = 0; i < MAX_WORD_LENGTH; ++i)
    {
        if (number_of_words[i] > max_number_of_words_with_the_same_length)
        {
            max_number_of_words_with_the_same_length = number_of_words[i];
        }
    }

    printf("\nNumber of words\n");
    for (int i = max_number_of_words_with_the_same_length; i > 0; --i)
    {
        printf("%15d", i);
        int previous_number_of_words_index = -1;
        for (int j = 0; j < MAX_WORD_LENGTH; ++j)
        {
            if (number_of_words[j] >= i)
            {
                int number_of_tabs_to_print;
                if (previous_number_of_words_index < 0)
                {
                    number_of_tabs_to_print = j + 1;
                }
                else
                {
                    number_of_tabs_to_print = j - previous_number_of_words_index;
                }
                previous_number_of_words_index = j;

                for (int k = 1; k <= number_of_tabs_to_print; ++k)
                {
                    putchar(TAB);
                }
                putchar('|');
            }
        }
        putchar(NEW_LINE);
    }

    printf("%15s", "Length");
    for (int i = 1; i <= MAX_WORD_LENGTH; ++i) 
    {
        printf("%c%d", TAB, i);
    }
    putchar(NEW_LINE);
}