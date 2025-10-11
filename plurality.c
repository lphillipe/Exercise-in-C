#include <stdio.h>
#include <cs50.h>
#include <string.h>

#define MAX_CANDIDATES 9

typedef struct
{
    string name;
    int votes;
} candidate;

candidate candidates[MAX_CANDIDATES];
int candidate_count;

bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // 1. verify if there are at least one candidate
    if (argc < 2)
    {
        printf("Usage: plurality [candidate1] [candidate2] ...\n");
        return 1;
    }


    // 2. keep the number of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %d.\n", MAX_CANDIDATES);
        return 2;
    }

    // 3. inicialize candidates
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    // 4. read number of voters
    int voter_count = get_int("Number of voters: ");

    // 5. for each voter, get their vote
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // call vote() after (in pass B)
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // 6. printer winner

    print_winner();
}

// testing

bool vote(string name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp (candidates[i].name, name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

void print_winner(void)
{
    // found the biggest number of votes

    int max_votes = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > max_votes)
        {
            max_votes = candidates[i]. votes;
        }
    }

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == max_votes)
        {
            printf("%s\n", candidates[i].name);
        }
    }
}


