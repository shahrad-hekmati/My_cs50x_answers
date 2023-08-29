#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

float letter_counter(string text);
float word_counter(string text);
float sentence_counter(string text);

int main(void)
{
    // getting the input from user
    string text = get_string("Enter your text : ");

    // variables
    float letter;
    float word;
    float sentence;
    float Letter;
    float Word;
    float Sentence;

    // defining the letter word and sentence
    Letter = letter_counter(text);
    Word = word_counter(text);
    Sentence = sentence_counter(text);

    // the formula for index
    float L = Letter * 100 / Word;
    float S = Sentence * 100 / Word;
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    // if statements for index ==> 1 < index < 15
    if (index > 15)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

// the function for letter_counter
float letter_counter(string text)
{
    float letter = 0;

    // for loop
    for (int counter = 0; counter < strlen(text); counter++)
    {
        // the statement for beeing alphabet
        if (isalpha(text[counter]) != 0)
        {
            letter++;
        }
    }
    return letter;
}
// the function for word_counter
float word_counter(string text)
{
    float word = 1;

    // for loop
    for (int counter = 0; counter < strlen(text); counter++)
    {
        // the statements for space
        if (text[counter] == 32)
        {
            word++;
        }
    }
    return word;
}
// the function for sentence_counter
float sentence_counter(string text)
{
    float sentence = 0;

    // for loop
    for (int counter = 0; counter < strlen(text); counter++)
    {
        // the statement for the end of sentence
        if (text[counter] == 63 || text[counter] == 33 || text[counter] == 46)
        {
            sentence++;
        }
    }
    return sentence;
}
