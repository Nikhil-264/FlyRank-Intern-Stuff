#include <stdio.h>  
  
void  main()  
{  
    int arr[4]; 
    int i;  
       printf("\n\nRead and Print elements of an array:\n");
       printf("-----------------------------------------\n");	
  
    printf("Input 4 elements in the array :\n");  
    for(i=0; i<4; i++)  
    {  
	    printf("element - %d : ",i);
        scanf("%d", &arr[i]);  
    }  
  
    printf("\nElements in array are: ");  
    for(i=0; i<4; i++)  
    {  
        printf("%d \n ", arr[i]);  
    } 
    printf("\n");	
}