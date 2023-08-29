#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner

    // win for player one
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");

    }

    // win for player two
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }

    // if non of the players won
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    // TODO: Compute and return score for string

    // the variables part
    int length_of_the_word = strlen(word);
    int total_score_of_word = 0;

    // a for loop for the scaning the each charechter in order to find the score of that charechter
    for (int pointer = 0; pointer < length_of_the_word; pointer ++)
    {
        // if the charechter is lowwer case
        if (isalpha(word[pointer]) != 0)
        {
            if (islower(word[pointer]))
            {
                total_score_of_word += POINTS[word[pointer] - 97];
            }

            // if the charechter is upper case
            else if (isupper(word[pointer]))
            {
                total_score_of_word += POINTS[word[pointer] - 65];
            }
        }
        // if the charechter is neither upper orlowwer case
        else
        {} //pass
    }
    return total_score_of_word;
}
