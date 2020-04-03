#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    //check for key validation
    if (argc != 2)
    {
        // handle too many argument or empty key
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // handle non-numeric key
    for (int j=0 , k=strlen(argv[1]) ; j < k ; j++)
    {
        if (!isdigit(argv[1][j]))
        {
        printf("Usage: ./caesar key\n");
        return 1;
        }
    }
    // transfer inputText
    printf("Success, key = %s\n", argv[1]);
    int key = atoi(argv[1]);
    key=key%26;
    string inputText = get_string("plaintext:");
    printf("ciphertext:");
    for( int i=0 , n = strlen(inputText); i < n ; i++)
    {
        // only deal with inputText is alphabet
        if(isalpha(inputText[i]))
        {   
            // discuss uppercase and lowercase inputText[i] respectively
            if(isupper(inputText[i]))
            {
                // ASCII code of A-Z is between 65-90
                // discuss whether inputText[i]+key is out of range 65-90 or not
                if( inputText[i] + key <=90 )
                {
                    inputText[i] += key;
                    inputText[i]=(inputText[i])%65+65;
                }
                else
                {
                    // if inputText[i]+key is out of range (that is > 90 )
                    // I have to make sure that will count from 65
                    inputText[i]=64+key-(90-inputText[i]);
                }
            }
            else if(islower(inputText[i]))
            {
                if( inputText[i] + key <=122 )
                {
                    inputText[i] += key;
                    inputText[i]=(inputText[i])%97+97;
                }
                else
                {
                    inputText[i]=96+key-(122-inputText[i]);
                }
            }
        }
       
        printf("%c", inputText[i]);
        
    }
    printf("\n");
    return 0;
}
