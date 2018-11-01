#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float change;
    do {
        change = get_float("Change owed: ");
    }
    while (change < 0);
    int cents = round(change * 100);
    int coins[] = {25, 10, 5, 1};
    int num_coins = 0;
    int new_change = cents;
    int element = 0;
    // Go through each coin and subtract from change one by one to determine how much of each coin change can be made
    // Stop when cents = 0
    while (cents > 0) {
        new_change = cents - coins[element];
        if (new_change >= 0) {
            num_coins++;
            cents = new_change;
        }
        else {
            element++;
            new_change = cents;
        }
    }
    printf("%i\n", num_coins);
}