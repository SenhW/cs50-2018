#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    long long cc_number;
    int cc_length = 0;
    do {
        cc_number = get_long_long("Number: ");
    }
    while (cc_number < 0);
    // Get length of credit card number
    long long cc = cc_number;
    while (cc != 0) {
        cc /= 10;
        cc_length++;
    }
    // Get first digit and first 2 digits of card
    int first_two_digits, first_digit;
    first_two_digits = cc_number / pow(10, cc_length - 2);
    first_digit = cc_number / pow(10, cc_length - 1);
    // Luhn's algorithm: Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products' digits together.
    int position = 1;
    int digit, t, total = 0;
    while (position < cc_length) {
        digit = (cc_number / (long long int)pow(10, position)) % 10;
        t = digit * 2;
        if (t > 9) {
            t = (t / 10) + (t % 10);
        }
        total += t;
        position += 2;
    }
    // Luhn's algorithm: Add the sum to the sum of the digits that weren’t multiplied by 2.
    position = 0;
    while (position < cc_length) {
        digit = (cc_number / (long long int)pow(10, position)) % 10;
        total += digit;
        position += 2;
    }
    // Luhn's algorithm: If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!
    int last_digit = total % 10;
    // Check which type of card it is (AMEX, MASTERCARD, VISA)
    if (last_digit == 0) {
        if (cc_length == 15 && (first_two_digits == 34 || first_two_digits == 37)) {
            printf("AMEX\n");
        }
        else if (cc_length == 16 && (first_two_digits == 51 || first_two_digits == 52 || first_two_digits == 53 || first_two_digits == 54
                                     || first_two_digits == 55)) {
            printf("MASTERCARD\n");
        }
        else if ((cc_length == 13 || cc_length == 16) && first_digit == 4) {
            printf("VISA\n");
        }
        else {
            printf("INVALID\n");
        }
    }
    else {
        printf("INVALID\n");
    }
}