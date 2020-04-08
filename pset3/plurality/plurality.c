#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
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

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    for (int i = 0; i < candidate_count; i++)
    {  
        //Compare two string, if the input name equals the candidate's name, then the votes of candidates[i] add 1.
        if (!strcmp(candidates[i].name, name))
        {
            candidates[i].votes += 1;
            return true;
        }
    }
    return false;
    //Because of the type of vote function, Boolean. The final return need to be true or false.
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    int highest_votes = 0; //first declare a new variable, highest_votes, to count the highest number of votes among the candidates
    // for the following nested for loop, I have try to use "j = i + 1" in the second for loop at the initial; however, it still got wrong even though it would be more efficient.
    // In final, I get back to the original one iteration, using nested for loop to figure out which candidates is the highest even though it need (n - 1) times for every candidates to check the result 
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {   
            // Here, we need to ensure that the highest_votes would not be changed under two candidates got the same votes and the votes still lower than the original highest votes.
            if ((candidates[i].votes >= candidates[j].votes) && (candidates[i].votes >= highest_votes)) 
            {
                highest_votes = candidates[i].votes;
            }
        }
    }
    //printf("Highest: %i", highest_votes);
    //Now, we have to print the result out even though the highest votes have multiple candidates.
    for (int k = 0; k < candidate_count; k++)
    {
        if (candidates[k].votes == highest_votes)
        {
            printf("%s\n", candidates[k].name);
        }
    }
    return; //In the last, it should not forget to return the result getting back to the main code.
}

