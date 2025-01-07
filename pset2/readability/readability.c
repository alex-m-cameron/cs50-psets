#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    int letters;
    int words;
    int sentences;
} text_count;

// Function prototypes
text_count calculate_text(string text);
float calculate_index(text_count count);

int main(void)
{
    // Get text from user
    string text = get_string("Text: ");

    // Calculate letters words and sentences
    text_count count = calculate_text(text);

    // Calculate index value
    float index = calculate_index(count);

    // Print grade level
    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", (int) round(index));
    }
}

// Calculate letters, words, and sentences in text.
// Initialise words with 1 since no space at end of sentence for last word
text_count calculate_text(string text)
{
    text_count count = {0, 1, 0};
    for (int i = 0, string_length = strlen(text); i < string_length; i++)
    {
        if (isalpha(text[i]) != 0)
        {
            count.letters++;
        }
        else if (text[i] == ' ')
        {
            count.words++;
        }
        else if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            count.sentences++;
        }
    }
    return count;
}

// Calculate index/grade value
float calculate_index(text_count count)
{
    float letters_per_100words = (float) count.letters / count.words * 100;
    float sentence_per_100words = (float) count.sentences / count.words * 100;
    float index = (0.0588 * letters_per_100words) - (0.296 * sentence_per_100words) - 15.8;
    return index;
}
