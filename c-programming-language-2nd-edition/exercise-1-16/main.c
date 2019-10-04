#include <stdio.h>

#define MAXLENGTH 1000

int loadline(char result_line[], int maxlength);
void copy(char to[], char from[]);

int main()
{
    int current_line_length;
    char current_line[MAXLENGTH];
    char longest_line[MAXLENGTH];

    int max_length = 0;
    while ((current_line_length = loadline(current_line, MAXLENGTH)) > 0)
    {
        if (current_line_length > max_length)
        {
            max_length = current_line_length;
            copy(longest_line, current_line);
        }
    }

    if (max_length > 0)
    {
        printf("Line: %s", longest_line);
        printf("Length: %d\n", max_length);
    }


    return 0;
}

int loadline(char result_line[], int maxlenght)
{
    char input;

    int i;
    for (i = 0; i < maxlenght - 1 && (input = getchar()) != EOF && input != '\n'; ++i)
    {
        result_line[i] = input;
    }

    if (input == '\n')
    {
        result_line[i] = input;
        ++i;
    }

    result_line[i] = '\0';
    return i - 1;
}

void copy(char to[], char from[])
{
    int i = 0;
    while ((to[i] = from[i]) != '\0')
    {
        ++i;
    }
}