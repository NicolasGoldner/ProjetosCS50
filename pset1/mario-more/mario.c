#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int altura;

    do
    {
        altura = get_int("Height:\n");
    }
    while (altura < 1 || altura > 8);

    for (int linha = 0; linha < altura; linha++)
    {
        for (int espaco = 0; espaco < altura - linha - 1; espaco++)
        {
            printf(" ");
        }
        for (int hash = 0; hash <= linha; hash++)
        {

            printf("#");
        }
        printf("  ");
        for (int hash = 0; hash <= linha; hash++)
        {

            printf("#");
        }
        printf("\n");
    }
}