/*52. Write a program in C to count the number of triangles that can be formed from a given array. Go to the editor
Expected Output :
The given array is : 6 18 9 7 10
Number of possible triangles can be formed from the array is: 5 */
//STILL INCOMPLETE
#include <stdio.h>
#include <math.h>
int main()
{
    int n, count = 0;

    printf("enter the number of elements in array\n");
    scanf("%d", &n);
    printf("print elements in array\n");
    int array[n];

    for (int i = 0; i < n; i++)
    {
        printf("element %d :", i);
        scanf("%d", &array[i]);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            for (int k = 2; k < n; k++)
            {
                if ((array[i] + array[j] > array[k]) && (array[i] + array[k] > array[j]) && (array[k] + array[j] > array[i]))
                {
                    count++;
                }
            }
        }
    }

    printf("Number of triangles can be made are : \" %d \" ", count);

    return 0;
}