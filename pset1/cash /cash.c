#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

int get_cents(void)
{
    // getting number input from user
    int cents;
    cents = get_int("Changed owed: ");
    // this part is for checking that if the number is positive or not
    while (cents < 0)
    {
        // if the number isn't positive it will ask again to enter another number
        cents = get_int("Changed owed: ");
    }
    return cents;
}

// our counters for all kinds of coins
int quarters_count = 0;
int dimes_count = 0;
int nickels_count = 0;
int pennies_count = 0;

// the quarters function
int calculate_quarters(int cents)
{
    // it will continues the operation until it reaches below 25
    while (cents >= 25)
    {
        cents -= 25;
        quarters_count ++;
    }
    return quarters_count;
}

// the dimes function
int calculate_dimes(int cents)
{
    // it will continues the operation until it reaches below 10
    while (cents >= 10)
    {
        cents -= 10;
        dimes_count ++;
    }
    return dimes_count;
}

// the nickels function
int calculate_nickels(int cents)
{
    // it will continues the operation until it reaches below 5
    while (cents >= 5)
    {
        cents -= 5;
        nickels_count ++;
    }
    return nickels_count;
}

// the pennies function
int calculate_pennies(int cents)
{
    // it will continues the operation until it reaches below 1
    while (cents >= 1)
    {
        cents -= 1;
        pennies_count ++;
    }
    return pennies_count;
}
