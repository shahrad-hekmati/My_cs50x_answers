#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // our defined variabels
    int height;
    int r;
    int c;
    int space;

    // get height
    height = get_int("Enter the height : ");

    //if height isnt in the range it will ask againe
    while (1 > height || height > 8)
    {
        height = get_int("Enter the height : ");
    }

    // the for loop for rows
    for (r = 0; r < height; r++)
    {
        // the for loop for spaces from left
        for (space = 0; space < height - r - 1; space ++)
        {
            printf(" ");
        }
        // the for loop for columns
        for (c = 0; c <= r ; c++)
        {
            printf("#");
        }
        printf("\n");
    }
}
