#include <stdio.h>
#include <stdlib.h>
int main()
{
    char c;
    printf("Enter character\n");
    scanf("%c", &c);
    int count = 0, flag = 0, fly = 0;
    while (1)
    {
        getchar();
        scanf("%c", &c);
        if (c == '(')
        {
            count = 1;
        }
        if (c == '=' && count > 0)
        {
            count++;
        }
        if (c == ')' && count > 0)
        {
            count++;
            if (count > flag)
                flag = count;
            fly++;
            count = 0;
        }

        if (c == '\n')
            break;
    }
    printf("\nThe number of flying saucers is %d\n", fly);
    printf("The biggest flying saucers is of lenght %d\n", flag);

    return 0;
}