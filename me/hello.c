#include <cs50.h>
#include <stdio.h>

int main(void)
{
    char *s = get_string("What's is your name?\n");
    printf("Hello, %s\n", s);
}
