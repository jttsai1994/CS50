#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
float dollars;
    do
    {
        dollars = get_float("Change owed: ");
    }
    while(dollars<0);
int cents = round(dollars*100);
int count=0;  
// printf("%i\n",cents);
    do
    {
        count+=cents/25;
        cents=cents%25;
    }
    while(cents/25>= 1);
    while(cents/10>=1)
    {
        count+=cents/10;
        cents=cents%10;
    }
        while(cents/5>=1)
    {
        count+=cents/5;
        cents=cents%5;
    }
     while(cents/1>=1)
     {
         count+=cents/1;
         cents=0;
     }
        printf("%d \n",count);
}
