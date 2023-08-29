#include "helpers.h"
#include <math.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int row = 0; row < height; row++)
    {
        for (int element = 0; element < width; element++)
        {
            RGBTRIPLE pixel = image[row][element];

            int red = pixel.rgbtRed;
            int green = pixel.rgbtGreen;
            int blue = pixel.rgbtBlue;

            int aver = round((red + green + blue) / 3.0);

            image[row][element].rgbtRed = aver;
            image[row][element].rgbtGreen = aver;
            image[row][element].rgbtBlue = aver;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int row = 0; row < height; row++)
    {
        for (int element = 0; element < width; element++)
        {
            RGBTRIPLE pixel = image[row][element];

            int red = pixel.rgbtRed;
            int green = pixel.rgbtGreen;
            int blue = pixel.rgbtBlue;

            int sepiaRed = round(.393 * red + .769 * green + .189 * blue);
            int sepiaGreen = round(.349 * red + .686 * green + .168 * blue);
            int sepiaBlue = round(.272 * red + .534 * green + .131 * blue);

            sepiaRed = sepiaRed > 255 ? 255 : sepiaRed;
            sepiaGreen = sepiaGreen > 255 ? 255 : sepiaGreen;
            sepiaBlue = sepiaBlue > 255 ? 255 : sepiaBlue;

            image[row][element].rgbtRed = sepiaRed;
            image[row][element].rgbtGreen = sepiaGreen;
            image[row][element].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int row = 0; row < height; row++)
    {
        for (int element = 0; element < width / 2; element++)
        {
            RGBTRIPLE tem = image[row][element];
            image[row][element] = image[row][width - element - 1];
            image[row][width - element - 1] = tem;
        }
    }
    return;
}

// Blur image

void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int row = 0; row < height; row++)
    {
        for (int element = 0; element < width; element++)
        {
            int sr = 0, sg = 0, sb = 0, c = 0;
            for (int d_row = -1; d_row < 2; d_row++)
            {
                for (int d_element = -1; d_element < 2; d_element++)
                {
                    if (row + d_row > -1 && row + d_row < height && element + d_element > -1 && element + d_element < width)
                    {
                        sr += image[row + d_row][element + d_element].rgbtRed;
                        sg += image[row + d_row][element + d_element].rgbtGreen;
                        sb += image[row + d_row][element + d_element].rgbtBlue;
                        c++;
                    }
                }
            }

            temp[row][element].rgbtRed = round(sr / (float) c);
            temp[row][element].rgbtGreen = round(sg / (float) c);
            temp[row][element].rgbtBlue = round(sb / (float) c);
        }
    }
    for (int row = 0; row < height; row++)
    {
        for (int element = 0; element < width; element++)
        {
            image[row][element] = temp[row][element];
        }
    }
    return;
}
