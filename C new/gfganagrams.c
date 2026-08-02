// Given two strings a and b consisting of lowercase characters. The task is to check whether two given strings are an anagram of each other or not. An anagram of a string is another string that contains the same characters, only the order of characters can be different. For example, act and tac are an anagram of each other.

// Note:-

// If the strings are anagrams you have to return True or else return False

// |s| represents the length of string s.

// Example 1:

// Input:a = geeksforgeeks, b = forgeeksgeeks
// Output: YES
// Explanation: Both the string have same characters with
//         same frequency. So, both are anagrams.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int isAnagram(char str1[], char str2[])
{
    int len1, len2, count = 0;
    len1 = strlen(str1);
    len2 = strlen(str2);
    if (len1 != len2)
        return -1;
    for (int i = 0; i < len1; i++)
    {
        for (int j = 0; j < len2; j++)
        {
            if (str1[i] == str2[j])
            {
                count++;
                break;
            }
            if (str1[i] != str2[j] && j == len2 - 1)
                return -1;
        }
        if (count == len1)
        {
            return 1;
        }
    }
}

int main()
{
    char str1[100], str2[100];
    printf("Enter your first string  : ");
    gets(str1);
    printf("Enter your second string : ");
    gets(str2);
    if (isAnagram(str1, str2) == 1) printf("YES\n");
    if (isAnagram(str1, str2) == -1) printf("NO\n");
    return 0;
}
