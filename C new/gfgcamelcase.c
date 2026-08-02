// Given a dictionary of words where each word follows CamelCase notation, print all words (in lexicographical order) in the dictionary that match with a given Pattern consisting of uppercase characters only.

// Example: GeeksForGeeks matches the Pattern "GFG", because if we combine all the capital letters in GeeksForGeeks they become GFG.

// CamelCase is the practice of writing compound words or phrases such that each word or abbreviation begins with a capital letter. Common examples include PowerPoint and Wikipedia, GeeksForGeeks, CodeBlocks, etc.

// Example 1:

// Input:
// N=3
// Dictionary=["WelcomeGeek",
// "WelcomeToGeeksForGeeks","GeeksForGeeks"]
// Pattern="WTG"
// Output:
// WelcomeToGeeksForGeeks
// Explanation:
// Since only WelcomeToGeeksForGeeks matches
// the Pattern, it is the only answer.
// Example 2:

// Input:
// N=8
// Dictionary=["Hi","Hello","HelloWorld",
// "HiTech","HiGeek","HiTechWorld",
// "HiTechCity","HiTechLab"]
// Pattern="HA"
// Output:
// -1
// Explanation:
// Since the Pattern matches none of the words
// of the string,the output is -1.
// Your Task:
// You don't need to read input or print anything. Your Task is to complete the function CamelCase() which takes an integer N, a Vector of strings Dictionary and a string Pattern and returns the strings in the dictionary that match the Pattern, if not found any return -1.

// Expected Time Complexity: O(N*|S|) S=Longest string in Dictionary
// Expected Auxillary Space: O(26*N)

// Constraints:
// 1<=N<=1000
// 1<=|S|<=100
// 1<=|Pattern|<=|S|<=100
// S is the longest word in Dictionary.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void CamelCase(int N, char Dictionary[][100], char *Pattern)
{
    char *temp[N];
    for (int i = 0; i < N; i++)
    {
        temp[i] = malloc(sizeof(char) * (100 + 1));
        int k = 0;
        for (int j = 0; Dictionary[i][j] != '\0'; j++)
        {
            if (Dictionary[i][j] >= 'A' && Dictionary[i][j] <= 'Z')
            {
                temp[i][k] = Dictionary[i][j];
                k++;
            }
        }
        temp[i][k] = '\0';
    }
    for (int i = 0; i < N; i++)
        if (strstr(temp[i], Pattern))
            printf("%s \n", Dictionary[i]);
    for (int i = 0; i < N; i++)
        free(temp[i]);
}

int main()
{
    int N;
    printf("N : ");
    scanf("%d", &N);
    char Dictionary[N][100];
    for (int i = 0; i < N; i++)
        scanf("%s", Dictionary[i]);
    char p[100];
    printf("Pattern : ");
    scanf("%s", p);
    CamelCase(N, Dictionary, p);

    return 0;
}