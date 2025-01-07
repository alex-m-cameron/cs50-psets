// sample keys ./substitution NQXPOMAFTRHLZGECYJIUWSKDVB
//             ./substitution YTNSHKVEFXRBAUQZCLWDMIPGJO

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Function Prototypes
bool is_key_valid(string text);
string encrypt(string text, string key);

int main(int argc, string argv[])
{
    // Get key from user.
    if (argc != 2)
    {
        printf("Usage: ./substituution key\n");
        return 1;
    }

    // Validate key.
    if (is_key_valid(argv[1]) == false)
    {
        printf("Key must contain 26 letters only and no duplicates.\n");
        return 2;
    }

    // Get plain_text from user.
    string plain_text = get_string("plaintext:  ");

    // Encrypt plain_text into cipher_text and print.
    string cipher_text = encrypt(plain_text, argv[1]);
    printf("ciphertext: %s\n", cipher_text);
    return 0;
}

// Validate key; only 26 characters, only upper/lower letters and no duplicate letters.
bool is_key_valid(string text)
{
    int string_length = strlen(text);

    // Check string length is 26.
    if (string_length != 26)
    {
        return false;
    }

    // Check only letters.
    for (int i = 0; i < string_length; i++)
    {
        if (isalpha(text[i]) == 0)
        {
            return false;
        }
    }

    // Check no duplicate letters.
    for (int i = 0; i < string_length; i++)
    {
        for (int j = i + 1; j < string_length; j++)
        {
            if (text[i] == text[j])
            {
                return false;
            }
        }
    }
    return true;
}

// Encrypt plain_text to cipher_text.
string encrypt(string text, string key)
{
    string encrypted_text = text;
    for (int i = 0, string_length = strlen(text); i < string_length; i++)
    {
        if (isalpha(text[i]) != 0)
        {
            // Calculate letter_position in alphabet to look up that position in key.
            // Using a ternary operator to account for uppercase and lowercase letters.
            int letter_position = isupper(text[i]) ? text[i] - 'A' : text[i] - 'a';

            // Calculate int difference in alphabet posistion between plain_text and key ASCII value.
            int letter_delta = isupper(text[i]) ? key[letter_position] - text[i]
                                                : tolower(key[letter_position]) - text[i];

            // Adding letter_delta to plain_text value gives encrypted letter value.
            encrypted_text[i] += letter_delta;
        }

        // If not a letter keep current value.
        else
        {
            encrypted_text[i] = text[i];
        }
    }
    return encrypted_text;
}
