#include<stdio.h>
#include<cs50.h>
#include<math.h>
int main(void)
{
    int  j;
    do
    {
        float n = get_float("Money ownes:$ "); // get the 2 decimal point input 
        j = round(n * 100);//convert decimal to integer with round figure
    }
    while (j <= 0);// check whether the value is negative or zero
   
    int quo = j / 25;// Largest quotient which can divide my converted number
    j = j - 25 * quo; // extract the non divisible part 
    int quo2 = j / 10; // repeat step 14
    j = j - 10 * quo2; // repeat step 15
    int quo3 = j / 5; // repeat step 14
    j = j - 5 * quo3; // repeat step 15
    int quo4 = j / 1; // repeat step 14
    int count = quo + quo2 + quo3 + quo4;
    printf("Required number of coins will be: %d\n", count);
    
}