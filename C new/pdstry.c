#include <stdio.h>
#include <stdlib.h>
typedef struct student
{
    int rollno;
    char name[30];
    int marks;

} std;

int main()
{
    std student1;
    student1 = (std){21, "Nikhil", 98};
    std student2 = {22, "Aman", 99};
    printf("%d %s %d", student1.rollno, student1.name, student1.marks);
    return 0;
}