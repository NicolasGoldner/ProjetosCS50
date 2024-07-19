#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    int n = 0, i = 0;

    string s = get_string("Digite aqui: ");
    n = strlen(s);
    while (i < n)
    {
        if (s[i] - 128 < 0)
        {
            printf("\U000026AB");
        }
        else
        {
            printf("\U0001F7E1");
            s[i] = s[i] - 128;
        }

        if (s[i] - 64 < 0)
        {
            printf("\U000026AB");
        }
        else
        {
            printf("\U0001F7E1");
            s[i] = s[i] - 64;
        }

        if (s[i] - 32 < 0)
        {
            printf("\U000026AB");
        }
        else
        {
            printf("\U0001F7E1");
            s[i] = s[i] - 32;
        }

        if (s[i] - 16 < 0)
        {
            printf("\U000026AB");
        }
        else
        {
            printf("\U0001F7E1");
            s[i] = s[i] - 16;
        }

        if (s[i] - 8 < 0)
        {
            printf("\U000026AB");
        }
        else
        {
            printf("\U0001F7E1");
            s[i] = s[i] - 8;
        }

        if (s[i] - 4 < 0)
        {
            printf("\U000026AB");
        }
        else
        {
            printf("\U0001F7E1");
            s[i] = s[i] - 4;
        }

        if (s[i] - 2 < 0)
        {
            printf("\U000026AB");
        }
        else
        {
            printf("\U0001F7E1");
            s[i] = s[i] - 2;
        }

        if (s[i] - 1 < 0)
        {
            printf("\U000026AB");
        }
        else
        {
            printf("\U0001F7E1");
            s[i] = s[i] - 1;
        }

        printf("\n");
        i++;
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
