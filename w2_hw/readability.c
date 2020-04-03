#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int main(void)
{
    int letters = 0;
    int words = 1;
    int sentences = 0;
    string inputText = get_string("Input:  ");
    printf("Output: ");
     for (int i = 0, n = strlen(inputText); i < n; i++)
    {   
       if (isalpha(inputText[i]))
       {
           letters++;
       }
       else if (inputText[i] == ' ')
       {
           words++;
       }
       else if (inputText[i] == '.' || inputText[i] == '!' || inputText[i] == '?')
       {
           sentences++;
       }
       
    }
    printf(" %i word(s) \n %i letters \n %i sentences\n" , words,letters,sentences);
    float grade = 0.0588 * (100 * (float) letters / (float) words) - 0.296 * (100 * (float) sentences / (float) words) - 15.8;
    if (grade < 16 && grade >= 0)
    {
        printf("Grade %i\n", (int) round(grade));
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Before Grade 1\n");
    }

}