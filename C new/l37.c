// structures syntax
#include <stdio.h>
#include<string.h>
struct student
{
    char name[100];
    int rollno;
    float marks;
    char grade;
};
struct student S1, S2, S3;

int main()
{
    struct student S1 = {"Nikhil", 10036, 7.76, 'A'};
    struct student S2 = {"Anmol", 10021, 9.76, 'X'}; // can write like this
    strcpy(S3.name, "Amruta");
    S3.rollno = 10077;
    S3.marks = 9.56; // can write like this as well
    S3.grade = 'X';
    printf("%d\n", S2.rollno);
    printf("%c\n", S1.grade);
    printf("%s\n",S3.name);

    return 0;
}
