#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int media = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            media = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            image[i][j].rgbtBlue = image[i][j].rgbtGreen = image[i][j].rgbtRed = media;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int sepiaBlue, sepiaGreen, sepiaRed;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            sepiaBlue = round(image[i][j].rgbtBlue * 0.131 + image[i][j].rgbtGreen * 0.534 + image[i][j].rgbtRed * 0.272);
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            sepiaGreen = round(image[i][j].rgbtBlue * 0.168 + image[i][j].rgbtGreen * 0.686 + image[i][j].rgbtRed * 0.349);
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            sepiaRed = round(image[i][j].rgbtBlue * 0.189 + image[i][j].rgbtGreen * 0.769 + image[i][j].rgbtRed * 0.393);
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtRed = sepiaRed;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE ajuda = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = ajuda;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    int contador = 0, totalGreen, totalRed, totalBlue, i = 0, j = 0, x = 0, y = 0, novox = 0, novoy = 0;
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            totalGreen = 0, totalRed = 0, totalBlue = 0, contador = 0;
            for (x = -1; x < 2; x++)
            {

                for (y = -1; y < 2; y++)
                {
                    novox = i + x;
                    novoy = j + y;
                    if ((novox < 0 || novoy < 0 || novox > (height - 1) || novoy > (width - 1)))
                    {
                        continue;
                    }
                    totalGreen = totalGreen + image[novox][novoy].rgbtGreen;
                    totalRed = totalRed + image[novox][novoy].rgbtRed;
                    totalBlue = totalBlue + image[novox][novoy].rgbtBlue;
                    contador++;
                }
            }
            copy[i][j].rgbtGreen = round((totalGreen * 1.0 / contador));
            copy[i][j].rgbtRed = round((totalRed * 1.0 / contador));
            copy[i][j].rgbtBlue = round((totalBlue * 1.0 / contador));
        }
    }

    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            image[i][j].rgbtGreen = copy[i][j].rgbtGreen;
            image[i][j].rgbtRed = copy[i][j].rgbtRed;
            image[i][j].rgbtBlue = copy[i][j].rgbtBlue;
        }
    }

    return;
}
