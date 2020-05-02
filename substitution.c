#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

//command line arguments
int main(int argc, string argv[])
{
    //to only 2 arguments passed
    if (argc == 2)
    {
        if (strlen(argv[1]) == 26)//to chek only 26 characters are there not
        {
            //assignment of argv data to key array
            char key[27];
            for (int z = 0; z < 26; z++)
            {
                key[z] = argv[1][z];
            }

            //to check whether our key has any duplicate alphabet
            int p = 0;
            for (int m = 0; m < 26; m++)
            {
                for (int n = m + 1; n < 26; n++)
                {
                    if (key[m] == key[n])
                    {
                        p++;
                        break;
                    }
                }
            }
            if (p == 0)// if value of p doesn't change then it means no duplicacy
            {
                //if our key has digits anywhere in the form of string
                int count = 0;
                for (int i = 0; i < 26; i++)
                {
                    if ((key[i] >= 'a' && key[i] <= 'z') || (key[i] >= 'A' && key[i] <= 'Z'))
                    {
                        count++;
                    }
                }
                if (count == 26)//if all the alphabets present then count will be 26
                {
                    char alpha[] = "abcdefghijklmnopqrstuvwxyz";
                    char ALPHA[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

                    //get the plaintext
                    string text = get_string("plaintext:  ");

                    //this is for ciphertext in making !!
                    for (int j = 0; j < strlen(text); j++)
                    {
                        for (int k = 0; k < 26; k++)
                        {
                            if (text[j] == alpha[k])//to check any plaintext letter is lowercase letter
                            {
                                text[j] = tolower(key[k]);//mapping the general alphabet order to our key order
                                break;
                            }
                            else if (text[j] == ALPHA[k])// to check any plaintext letter is uppercase letter
                            {
                                text[j] = toupper(key[k]);//mapping the general alphabet order to our key order
                                break;
                            }
                        }
                    }
                    printf("ciphertext: %s\n", text);//output
                    return 0;
                }
                else
                {
                    printf("Key must contain 26 characters.\n");
                    return 1;
                }

            }
            else
            {
                printf("Key mustn't contain duplicate characters.\n ");
                return 1;
            }
        }
        else
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
    }
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
}