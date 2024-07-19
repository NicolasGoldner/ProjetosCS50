#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int i = 0, S = 0, L = 0, Y = 0;
    float index, k, l;

    string s = get_string("Ponha seu texto aqui: ");

    while (s[i] != '\0')
    {
        if (s[i] == 32)//Verifica espaços
        {
            i++;
            L++; // Conta a quantidade de palavras
        }
        else if (s[i] == 33 || s[i] == 46 || s[i] == 63)//Verificas pontuações como . ? !
        {
            S++; // Conta A quantidade de frases
            i++;
        }
        else if ((s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122))
        {
            Y++; // Conta A quantidade de Letras
            i++;
        }
        else
        {
            i++;
        }
    }
    L = L + 1;//Soma + 1 pois a ultima palavra não tem espaço
    l = ((Y * 100.0) / L);
    k = ((S * 100.0) / L);
    index = 0.0588 * l - 0.296 * k - 15.8;

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %.0f\n", index);
    }
}