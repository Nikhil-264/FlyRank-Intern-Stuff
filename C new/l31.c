//Call by refernce
//program to swap the values
#include<stdio.h>
void swap(int * x,int*y)//#
{
    int value;
    value = *x; // change of address here
    *x = *y ;
    *y = value;

}
int main ()
{
    int a , b;
    printf("Enter a and b repectively :\n");
    scanf("%d %d",&a,&b);
    printf("The original values are : \na = %d\nb = %d\n",a,b);
    swap(&a,&b); // address is provided in fuction swap in #
    printf("The swapped values are :\na = %d\nb = %d",a,b);
    return 0;
}