#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Init array; A to Z score for each letter
const int letter_score[26] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                              1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
// Function prototype
int calculate_score(string word);

int main(void)
{
    // Get players words
    string player1_word = get_string("Player 1: ");
    string player2_word = get_string("Player 2: ");

    // Calculate each player score
    int player1_score = calculate_score(player1_word);
    int player2_score = calculate_score(player2_word);

    // Print winner to terminal
    if (player1_score > player2_score)
    {
        printf("Player 1 wins!\n");
    }
    else if (player1_score < player2_score)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
    return 0;
}

// Calculate score
int calculate_score(string word)
{
    int score = 0;
    for (int i = 0, string_length = strlen(word); i < string_length; i++)
    {
        // Convert each word letter to uppercase
        word[i] = toupper(word[i]);
        // Then useing ASCII value to work out each letter value from 65
        // then use letter_score array for score of each letter
        if (word[i] >= 'A' && word[i] <= 'Z')
        {
            int j = (int) word[i] - 'A';
            score += letter_score[j];
        }
    }
    return score;
}
