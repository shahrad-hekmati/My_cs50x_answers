// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file
    uint8_t size_file;
    uint8_t buffer;

    for (int i = 0; i < HEADER_SIZE; i++)
    {
        fread(&buffer, sizeof(size_file), 1,
              input); // (a pointer of starting location, sizeof(size_file), how big is the words that we have to read, input_file)
        fwrite(
            &buffer, sizeof(size_file), 1,
            output); // (a pointer of starting location, sizeof(size_file), how big is the words that we have to read, output_file)
    }

    // TODO: Read samples from input file and write updated data to output file
    int16_t new_size_file;
    int16_t template;

    while (fread(&template, sizeof(new_size_file), 1, input))
    {
        template *= factor;
        fwrite(&template, sizeof(new_size_file), 1, output);
    }

    // Close files
    fclose(input);
    fclose(output);
}
