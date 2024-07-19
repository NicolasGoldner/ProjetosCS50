#include <cs50.h>
#include <stdio.h>

int main()
{
    long n = get_long("Number:");
    long somaI = 0, somaP = 0;
    int m = 10;

    for(int x = 1; x < 17; x++)
    {
        if(x % 2 == 0)
        {
            somaP = somaP + (n%m);
        }
        else
        {
            somaI = somaI + (n%m);
        }
        m = m*10;
    }
    long total = somaP*2 + somaI;
    if(total%10 == 0)
    {
        printf("VISA\n");
    }

    return 0;
}
