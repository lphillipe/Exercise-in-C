#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

int preferences[MAX_VOTERS][MAX_CANDIDATES];

typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

candidate candidates[MAX_CANDIDATES];

int voter_count;
int candidate_count;

// Prototypes funcions
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // 1. validadte arguments (name of candidates)
    if (argc < 2)
    {
        printf("Usage: runoff [candidate1] [candidate2] ...\n");
        return 1;
    }

    // 2. Inicializate candidate_count and validate limit

    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %d.\n", MAX_CANDIDATES);
        return 2;
    }

    // 3. form array candidates[] (votes = 0, eliminated = false)
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }
    
    // 4. read number of voters and validate
    voter_count = get_int("Number of voters: ");
    if (voter_count < 0 || voter_count > MAX_VOTERS)
    {
        printf("Invalid number of voters.\n");
        return 3;
    }

    // 5. each voter, read all preferences (rank 0.. candidate_count -1)
    for (int i = 0; i < voter_count; i++)
    {
        for (int rank = 0; rank < candidate_count; rank++)
        {
            string name = get_string("Rank %i for voter %i: ", rank + 1, i + 1);

            if (!vote(i, rank, name))
            {
                printf("Invalid vote.\n");
                rank--;
            }
        }
    }
    // 6. run rounds until winner found or tie
    while (true)
    {
        // tabulate votes for non-eliminated candidates
        tabulate();

        // check for winner
        if (print_winner())
        {
            break;
        }
        // find minimum votes among non-eliminated candidates
        int min = find_min();

        // check if tie between all non-eliminated

        if (is_tie(min))
        {
            // print all non-eliminated (tie)
            for (int i = 0 ; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
        
            break;
        }
        eliminate(min);
    }
    return 0;
}

bool vote(int voter, int rank, string name)
{
    // search the candidate name
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            // check is this candidate  has already been chosen by this voter
            for (int r = 0; r < rank; r++)
            {
                if (preferences[voter][r] == i)
                {
                    // has already been chosen before
                    return false;
                }
            }
        
            // record the voter's preference
            preferences[voter][rank] = i;
            return true;
        }
    }
    return false;
}

void tabulate(void)
{
    // reset votes to zero
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].votes = 0;
    }

    // for each voter, count your best chosen not eliminated

    for (int v = 0; v < voter_count; v++)
    {
        for (int rank = 0; rank < candidate_count; rank++)
        {
            int cand = preferences[v][rank];
            if (!candidates[cand].eliminated)
            {
                candidates[cand].votes++;
                break; // break to next voter
            }
        }
    }
}

bool print_winner(void)
{
    int max_votes = 0;
    // found the biggest number of votes between non eliminated

    for (int i= 0; i< candidate_count; i++)
    {
        if (!candidates[i].eliminated && candidates[i].votes > max_votes)
        {
            max_votes = candidates[i]. votes;
        }
    }

    // if any has more than half votes, print all of with this number (for safe)
    if (max_votes > voter_count /2)
    {
        for (int i = 0; i < candidate_count; i++)
        {
            if (!candidates[i].eliminated && candidates[i].votes == max_votes)
            {
                printf("%s\n", candidates[i].name);

            }
        }
        return true;
    }
    return false;
}
int find_min(void)
{
    int min_votes = INT_MAX;
    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated && candidates[i].votes < min_votes)
        {
            min_votes = candidates[i].votes;
        }
    }
    return min_votes;
}

bool is_tie(int min)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated && candidates[i].votes != min)
        {
            return false; // exist a candidate non-eliminated with votes different is not draw.
        }
    }
    return true; // all non-eliminated candidates have votes == min
}

void eliminate(int min)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated && candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
        }
    }
}