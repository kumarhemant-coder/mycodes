//Prints left & right aligned pyramid with a permanent space between them !!
#include<stdio.h>
#include<cs50.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Please enter the height of the pyramid between 1 and 8 (both inclusive): ");
    }
    while (height < 1 || height > 8); //OR operator to allow input from 1 to 8

    for (int i = 0; i < height; i++) //this iteration for number of rows i.e. height
    {
        for (int j = height; j > i + 1; j--) //this iteration to print space
        {
            printf(" ");
        }
        for (int k = 0; k <= i; k++) //this iteration to print left aligned pyramid
        {
            printf("#");
        }

         printf("  "); //permanent space between two pyramids

        for (int m = 0; m <= i; m++) //this iteration to print right aligned pyramid
        {
            printf("#");
        }
        printf("\n");
    }

}