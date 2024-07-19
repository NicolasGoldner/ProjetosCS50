#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#define TAMANHO 512

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }
    FILE *cartao = fopen(argv[1], "r");
    if (cartao == NULL)
    {
        printf("Could not open file %s.\n", argv[1]);
        return 1;
    }

    char filename[9]; // Tamanho deve ser 9 para acomodar o nome do arquivo e o caractere nulo terminador
    FILE *imagem = NULL;
    uint8_t buffer[TAMANHO];
    int contador = 0;

    while (fread(buffer, 1, 512, cartao) == 512)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (imagem != NULL)
            {
                fclose(imagem);
            }

            sprintf(filename, "%03i.jpg", contador);
            imagem = fopen(filename, "a"); // Abre o arquivo no modo de anexação
            if (imagem == NULL)
            {
                fclose(cartao);
                return 1;
            }
            fwrite(buffer, 1, 512, imagem);
            contador++;
        }
        else if (imagem != NULL)
        {
            fwrite(buffer, 1, 512, imagem);
        }
    }

    if (imagem != NULL)
    {
        fclose(imagem);
    }
    fclose(cartao);

    return 0;
}
