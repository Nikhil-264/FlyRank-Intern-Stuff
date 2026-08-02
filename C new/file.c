#include <stdio.h>

int main(int argc, char const *argv[])
{
    FILE *fptr;

    // Create a file
    fptr = fopen("Lecture 2.pdf", "w");

    // Close the file
    fclose(fptr);
    return 0;
}
