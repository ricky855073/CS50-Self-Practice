#include <stdio.h>
#include <cs50.h>

float Average(int argc, float argv[]);

int n;

//The main must be in int type.
int main (void)
{
    //Asking the number of scores. If the result is negative number, ask the user again until getting the positive real number.
    do
    {
        n = get_int("Scores: ");
    }
    while (n < 0);

    //First define the scores inside scores array respectively.
    float scores[n];
    //Prompt the user give n scores by for loop.
    for (int i = 0; i < n; i++)
    {
        scores[i] = get_float("Scores %i: ", i+1);
    }
    //Printing out the average scores by "Average" function which defined by the local.
    printf("Average is %.2f \n", Average(n, scores));
    return 0;
}

//Define a new function called "Average," and it need contain number(argc) and scores array(argv[]).
//start from float sum and add every scores into sum to get ready.
float Average(int argc, float argv[])
{
    float sum = 0;
    for (int i = 0; i < argc; i++)
    {
        sum += argv[i];
    }
    //Returning the average number which is in float type.
    return  sum /  argc;
}