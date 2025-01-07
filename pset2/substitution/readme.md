Substitution
https://cs50.harvard.edu/x/2024/psets/2/substitution/

Program that encrypts user plain_text into cipher_text based on an input key.







refactored code line 77 to 85

        if (isupper(text[i]) != 0)
        {
            int letter_posistion = text[i] - 'A';
            int letters_delta = toupper(key[letter_posistion]) - text[i];
            encrypted_text[i] += letters_delta;
        }
        if (islower(text[i]) != 0)
        {
            int letter_posistion = text[i] - 'a';
            int letters_delta = tolower(key[letter_posistion]) - text[i];
            encrypted_text[i] += letters_delta;
        }
