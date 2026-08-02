// stone paper scissor game
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int n = 0, rps, com = 0, player = 0, k;
    char name[100];
    printf("ENter your name to play the game :");
    gets(name);
    printf("press \n0 for stone \n1 for paper \n2 for scossor\n");
    while (n < 17)
    {
        srand(time(NULL));
        // 0=stone,1=paper,2=scissor//
        printf("Give your response : ");
        scanf("%d", &rps);
        k = rand() % 2;
        printf("%d\n", k);
        if (rps == k)
        {
            printf("Its a tie \n");
        }

        if ((rps == 1) && (k == 2))
        {
            printf("computer wins\n");
            com++;
        }
        if ((rps == 2) && (k == 0))
        {
            printf("computer wins\n");
            com++;
        }
        if ((rps == 0) && (k == 1))
        {
            printf("computer wins\n");
            com++;
        }
        if ((rps == 1) && (k == 0))
        {
            printf("player wins\n");
            player++;
        }
        if ((rps == 0) && (k == 2))
        {
            printf("player wins\n");
            player++;
        }
        if ((rps == 2) && (k == 1))
        {
            printf("player wins\n");
            player++;
        }

        n++;
        printf("\n");
    }
    printf("SCORES ARE:\ncom = %d\n%s = %d\n", com, name, player);
    if (com > player)
    {
        printf("The winner is computer\n");
    }
    if (player > com)
    {
        printf("YOU WIN\n");
    }
    if (player == com)
    {
        printf("This is a tie\n");
    }

    return 0;
}
// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>
// #include <string.h>

// #define MAX_STRINGS 100
// #define MAX_STRING_LENGTH 100

// int main() {
//     char strings[MAX_STRINGS][MAX_STRING_LENGTH];
//     int num_strings, random_index;
//     char random_string[MAX_STRING_LENGTH];

//     // Read in the user-provided strings
//     printf("Enter up to %d strings, one per line:\n", MAX_STRINGS);
//     num_strings = 0;
//     while (num_strings < MAX_STRINGS && fgets(strings[num_strings], MAX_STRING_LENGTH, stdin) != NULL) {
//         // Remove the newline character at the end of the string
//         strings[num_strings][strcspn(strings[num_strings], "\n")] = '\0';
//         num_strings++;
//     }

//     // Seed the random number generator
//     srand(time(NULL));

//     // Generate a random index into the array of strings
//     random_index = rand() % num_strings;

//     // Copy the randomly selected string into the random_string buffer
//     strncpy(random_string, strings[random_index], MAX_STRING_LENGTH);

//     printf("Random string: %s\n", random_string);

//     return 0;
// }
