// Program to print a certain sized pryamid to screen based on user input.

#include <cs50.h>
#include <stdio.h>

void printpyramid(int h);

// ask user for pyramid height. limited between 1 to 8 inclusive.
int main(void)
{
    int height = 0;
    while (height < 1 || height > 8)
    {
        height = get_int("What is pyramid height? ");
    }
    printpyramid(height);
}

// Function that prints a pyramid based on input height from user
void printpyramid(int height)
{
    int blocks = 1;
    int spaces = height - 1;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < spaces; j++)
        {
            printf(" ");
        }
        for (int j = 0; j < blocks; j++)
        {
            printf("#");
        }
        printf("  ");
        for (int j = 0; j < blocks; j++)
        {
            printf("#");
        }
        printf("\n");
        blocks++;
        spaces--;
    }
}
