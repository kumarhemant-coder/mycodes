#include<stdio.h>
#include<cs50.h>

int main(void)
{
    long num;
    do
    {
        num = get_long("Please input credit card number: ");//get the card number
    }
    while (num <= 0);//to check whether card number is positive or not

    long a = num;// assign card number value to another variable
    int count = 0;// counter
    while (a != 0)//to find the number of digits of the card number
    {
        count++;
        a = a / 10;
    }
    if (count != 16 && count != 15 && count != 13)// to check card number other than 16, 15 digits
    {
        printf("INVALID\n");
    }
    else
    {
        long num1 = num;
        int sumev = 0, sumod = 0, c = 1;
        while (num != 0)// to find the sum of both places i.e. even and odd
        {
            if (c % 2 == 0)// to check whether it is even place or not
            {
                int z = num % 10 * 2, y = 0;//according to the problem first multiply the even place digit by 2
                while (z != 0)// if we get the result in 2 digits after multiplication by 2 then to find the sum of those 2 digits
                {
                    y = y + z % 10;
                    z = z / 10;
                }
                sumev = sumev + y;//finally total addition
            }
            else
            {
                sumod = sumod + num % 10;// simply total of odd place
            }
            num = num / 10;
            c++;
        }
        long k = 1;
        for (int i = 0; i < count - 2; i++)
        {
            k = k * 10;
        }
        int add = sumev + sumod;
        if (add % 10 == 0)// to check the combined addition gives us zero or not
        {
            //to determine which company the card belongs
            num1 = num1 / k;
            if (num1 == 34 || num1 == 37)
            {
                printf("AMEX\n");
            }
            else if (num1 == 51 || num1 == 52 || num1 == 53 || num1 == 54 || num1 == 55)
            {
                printf("MASTERCARD\n");
            }
            else if (num1 / 10 == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");//if card number does not belong to any of the above metioned companies, although checksum is correct
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
}