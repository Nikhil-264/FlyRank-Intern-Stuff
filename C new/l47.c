#include <stdio.h>
#include <stdlib.h>

int main()
{
    //use of malloc
    int *ptr,n;
    printf("Enter the number n : ");
    scanf("%d",&n);
    ptr=(int*)malloc(n*sizeof(int));
    for (int i = 0; i < n; i++)
    {
        printf("Enter the value of %d of array\n",i);
        scanf("%d",&ptr[i]);
    }
    

    return 0;
}
