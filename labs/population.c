#include <stdio.h>

int main(void){
    int ilhama, anos = 0, final;
    do
    {
        printf("Quantas Ilhamas você tem?(Digite um número maior que 9)\n");
        scanf("%i", &ilhama);
    }
    while(ilhama < 9);

    do
    {
        printf("Quantas ilhamas você quer no futuro?(Min de: %i)\n", ilhama);
        scanf("%i", &final);
    }
    while(final < ilhama);

    while(ilhama < final){
    ilhama = ilhama + ilhama/3 - ilhama/4;
    anos++;
    }

    printf("Years: %i\n", anos);
}