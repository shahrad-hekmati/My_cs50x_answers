#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        return 1;
    }

    FILE *file = fopen(argv[1], "r");

    unsigned char *space_for_jpg = malloc(512);

    char *file_name = malloc(3 * sizeof(int));
    int image = 0;

    if (space_for_jpg == NULL || file_name == NULL)
    {
        return 1;
    }

    while (fread(space_for_jpg, sizeof(unsigned char), 512, file))
    {
        if (space_for_jpg[0] == 0xff && space_for_jpg[1] == 0xd8 && space_for_jpg[2] == 0xff && (space_for_jpg[3] == 0xe0))
        {
            sprintf(file_name, "%03i.jpg", image);
            FILE *image_file = fopen(file_name, "w");
            fwrite(space_for_jpg, 1, 512, image_file);
            fclose(image_file);
            image++;
        }

        else if (image != 0)
        {
            FILE *image_file = fopen(file_name, "a");
            fwrite(space_for_jpg, 1, 512, image_file);
            fclose(image_file);
        }
    }

    fclose(file);
    free(space_for_jpg);
    free(file_name);
}
