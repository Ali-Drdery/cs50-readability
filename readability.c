#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // get text from user
    string text = get_string("Text: ");

    int letters = 0;
    int words = 1;
    int sentences = 0;

    // count letters, words, and sentences
    for (int i = 0; i < strlen(text); i++)
    {
        // count letters
        if (isalpha(text[i]))
        {
            letters++;
        }

        // count words
        if (text[i] == ' ')
        {
            words++;
        }

        // count sentences
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }

    // Coleman-Liau formula
    float L = ((float) letters / words) * 100;
    float S = ((float) sentences / words) * 100;

    int grade = round(0.0588 * L - 0.296 * S - 15.8);

    // print result
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}