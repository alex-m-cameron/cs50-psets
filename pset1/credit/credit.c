// Program to check if a credit card number could be vaild based on luhns Algorithm
// example visa number 4003600000000014

#include <cs50.h>
#include <stdio.h>

bool luhns_check(long n);
void card_type_check(long n);

// Get a cardnumber from user that is between 13 to 16 digits. Then apply luhns algorithm
int main(void)
{
    long cardnumber = get_long("Number: ");
    if (cardnumber < 1E+12 || cardnumber > 1E+16)
    {
        printf("INVALID\n");
        return 0;
    }

    if (luhns_check(cardnumber) == true)
    {
        card_type_check(cardnumber);
    }
    else
    {
        printf("INVALID\n");
    }
}

// Luhns algorithm function.
bool luhns_check(long n)
{
    // Find credit card digit length.
    int card_length = 0;
    long x = n;
    while (x > 0)
    {
        x = x / 10;
        card_length++;
    }

    // Calculate sumtotal using algorithm, interates over last 2 digits at a time.
    int sum_total = 0;
    for (int i = 0; i < card_length; i += 2)
    {
        // Add first digit.
        sum_total += n % 10;
        n = n / 10;

        // Multiply second digit by 2 then add digits of result together and add to sumtotal.
        int a = (n % 10) * 2;
        int b = a % 10;
        int c = a / 10;
        sum_total += b + c;
        n = n / 10;
    }
    // if sum_total is a mulitple of 10 return true.
    if (sum_total % 10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Check if card has valid starting digits and length
void card_type_check(long n)
{
    if ((n >= 34E+13 && n < 35E+13) || (n >= 37E+13 && n < 38E+13))
    {
        printf("AMEX\n");
    }
    else if ((n >= 4E+12 && n < 5E+12) || (n >= 4E+15 && n < 5E+15))
    {
        printf("VISA\n");
    }
    else if (n >= 51E+14 && n < 56E+14)
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
