// Given a string str, find the minimum characters to be added at front of the string to make it a palindrome.

//                     Example 1 :

//     Input : str = ABCD
//                         Output : 3 Explanation : The resultant string
//                                                      after adding 3 characters is DCBABCD.The minimum possible answer is 3. Example 2 :

//     Input : str = ABA
//                         Output : 0 Explanation : The given string
//                                                      is already a palindrome.
#include <stdio.h>
#include <string.h>
int palindrome(char str[], int n)
{


    int i = 0;
    while (str[i] == str[n - 1 - i])
    {
        i++;
    }
    if (i == n)
        return 0;
    else
        return n - 1;
}
int main()
{
    char str[100];
    int n;
    printf("Give your string here : ");
    gets(str);
    n = strlen(str);
    printf("%d ", palindrome(str, n));

    return 0;
}