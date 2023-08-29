#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int n = strlen(argv[1]);
    for (int c_1 = 0; c_1 < n; c_1++)
    {
        if (isalpha(argv[1][c_1]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    string plain_text = get_string("plaintext:  ");

    int key = atoi(argv[1]);
    printf("ciphertext: ");
    char cc;
    int len_plain = strlen(plain_text);
    for (int c_2 = 0; c_2 < len_plain; c_2++)
    {
        char c = plain_text[c_2];
        if (isalpha(c))
        {
            if (isupper(c))
            {
                cc = ((c - 65 + key)) % 26 + 65;
            }
            else if (islower(c))
            {
                cc = ((c - 97 + key)) % 26 + 97;
            }
            if (!(islower(cc) || isupper(cc)))
            {
                cc -= 26;
            }
        }
        else
        {
            cc = c;
        }
        printf("%c", cc);
    }
    printf("\n");
}
