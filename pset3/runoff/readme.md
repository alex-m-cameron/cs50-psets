Runoff
https://cs50.harvard.edu/x/2025/psets/3/runoff/
The int main(int argc, string argv[]) and function prototypes are provided by CS50.
My code is all of the logic in the functions below int main.


This Runoff program simulates a ranked-choice voting system.
Voters vote for candidates in order of preference.

If in the first round of totaling first preference votes there is not a >50% majority, the candidate/candidates with the lowest amount first preference votes are eliminated and those voters 2nd preference is added to the sum_total of votes from the first round. This repeats until a candidate has >50% or a tie occurs.











How to test
Be sure to test your code to make sure it handles…

An election with any number of candidate (up to the MAX of 9)
Voting for a candidate by name
Invalid votes for candidates who are not on the ballot
Printing the winner of the election if there is only one
Not eliminating anyone in the case of a tie between all remaining candidates
