#include <stdio.h>
#include <stdlib.h>
int main()
{
    printf("file name is %s\n", __FILE__);
    printf("date  is %s\n", __DATE__);
    printf("time  is %s\n", __TIME__);
    printf("line number  is %d\n", __LINE__);
    printf("ANSI  is %d\n", __STDC__);
    return 0;
}