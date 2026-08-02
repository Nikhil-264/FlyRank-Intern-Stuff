#include <stdio.h>

#define MAX_SIZE 100

// Function to check if an element is already in the set
int isElementInSet(int set[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (set[i] == element)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    int set[MAX_SIZE];
    int size = 0;

    printf("Enter integers (enter -1 to stop):\n");

    int input;
    while (1)
    {
        scanf("%d", &input);

        if (input == -1)
        {
            break; // Exit the loop when -1 is entered
        }

        if (!isElementInSet(set, size, input))
        {
            set[size] = input;
            size++;
        }
        else
        {
            printf("Element %d is already in the set.\n", input);
        }
    }

    printf("Elements in the set: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", set[i]);
    }
    printf("\n");

    return 0;
}
