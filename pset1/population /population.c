#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // the variabeles
    int starting_lama_pop;
    int ending_lama_pop;
    int years = 0;

    // get the start_pop, end_pop values
    starting_lama_pop = get_int("Enter the starting lama pop : ");
    ending_lama_pop = get_int("Enter the ending lama pop : ");

    while (starting_lama_pop < 9 || ending_lama_pop < starting_lama_pop)
    {
        // the starting pop shoudn't be less than 9 lama
        if (starting_lama_pop < 9)
        {
            //getting input for starting lama pop from user
            starting_lama_pop = get_int("Enter the starting lama pop : ");
        }

        if (ending_lama_pop < starting_lama_pop)
        {
            //getting input for ending lama pop from user
            ending_lama_pop = get_int("Enter the ending lama pop : ");
        }

    }
    // calculating the amount of years it would need to reach end_pop
    while (starting_lama_pop < ending_lama_pop)
    {
        starting_lama_pop = starting_lama_pop + (starting_lama_pop / 3) - (starting_lama_pop / 4);
        years ++;
    }

    printf("Years: %i\n", years);
    // TODO: Prompt for start size

    // TODO: Prompt for end size

    // TODO: Calculate number of years until we reach threshold

    // TODO: Print number of years
}
