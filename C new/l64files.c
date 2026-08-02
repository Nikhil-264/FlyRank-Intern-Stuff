#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *ptr = NULL;
    char str[54]="I am in heaven";
    // reading  a file
    //  ptr = fopen("myfile.txt", "r");
    //  fscanf(ptr, "%s", str);
    //  printf("The content is %s\n", str);
    // Writing a file
    ptr = fopen("myfile.txt", "a");//if r we can only read//if w we can change contnt from scrach//if a content is added in previuos content
    fprintf  (ptr, "%s", str);
   

    return 0;
}