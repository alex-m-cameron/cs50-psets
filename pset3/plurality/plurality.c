#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// canidate struct
typedef struct
{
    string name;
    int votes;
} candidate;

// Init an array of candidates
candidate candidates[MAX];

// Init number of candidates
int candidate_count;

// Function prototypes
bool is_vote_invalid(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: ./plurality name1 name2 ...]\n");
        return 1;
    }

    // Check candidates don't exceed MAX amount then populate the array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    // Get number of voters; and get vote names from user
    int voter_count = get_int("Number of voters: ");
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!is_vote_invalid(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Print winner of election
    print_winner();
}


// if vote valid increment candidate.vote tally. else return false.
bool is_vote_invalid(string name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (!strcmp(name, candidates[i].name))
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

// Look for highest .vote count then print names with that vote count
void print_winner(void)
{
    int highest_vote_count = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        if (highest_vote_count < candidates[i].votes)
        {
            highest_vote_count = candidates[i].votes;
        }
    }
    for (int i = 0; i < candidate_count; i++)
    {
        if (highest_vote_count == candidates[i].votes)
        {
            printf("%s\n", candidates[i].name);
        }
    }
    return;
}
