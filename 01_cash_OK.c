#include <stdio.h>
#include <math.h>
#include <cs50.h>

int main(void)
{
    int change = 0;
    float input = 0;
    int vint = 0;
    
    do
    {
        input = get_float("Change owed: ");
    }
    while (input < 0);

    //I take the integer part of input, if greater than 0, divide by the biggest coin and increment the change counter
    vint = (int)input;
    if (vint > 0)
    {
        change = vint / 0.25;
        //Keep the floating only
        input = input - vint;
    }
    //At this point I could only have a number with 0 integer part -> 0.xxx
    //Multiply by 100 to gets value in cents
    
    int cents = round(input * 100);
    //1st check for the greater number of quarters
    while (cents >= 25)
    {
        cents = cents - 25;
        change++;
    }
    //2nd check for the greater number of dimes
    while (cents >= 10)
    {
        cents = cents - 10;
        change++;
    }
    //3rd check for the greater number of nickels
    while (cents >= 5)
    {
        cents = cents - 5;
        change++;
    }
    //4th check for the greater number of pennies
    while (cents >= 1)
    {
        cents = cents - 1;
        change++;
    }
    //Print the final result
    printf("%d\n", change);
    
}