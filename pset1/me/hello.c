#include <stdio.h>
#include <cs50.h>

// Program that ask user for their name and says hello to them by name

int main(void)
{
    string name = get_string("what is your name? \n");
    printf("hello, %s\n", name);
}
