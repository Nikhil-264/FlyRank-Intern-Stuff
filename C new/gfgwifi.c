// There are N rooms in a straight line in Geekland State University's hostel, you are given a binary string S of length N where S[i] = '1' represents that there is a wifi in ith room or S[i] = '0' represents no wifi. Each wifi has range X i.e. if there is a wifi in ith room then its range will go upto X more rooms on its left as well as right. You have to find whether students in all rooms can use wifi.

// Example 1:
// Input:
// N = 3, X = 0
// S = "010"
// Output:
// 0
// Explanation:
// Since the range(X)=0, So Wifi is only
// accessible in second room & 1st & 2nd
// room have no wifi.

// Example 2:
// Input:
// N = 5, X = 1
// S = "10010"
// Output:
// 1
// Explanation:
// Index 0 : Wifi is available
// Index 1 : Since range of 0th Index is 1
//           so, here wifi will be available.
// Index 2 : Since range of 3rd Index is 1
//           so, here also wifi available.
// Index 3 : Wifi is available
// Index 4 : here range of 3rd Index is available.
// So all the rooms have wifi, so return true.
#include <stdio.h>
#include <stdlib.h>
int wifirange()
{
    int x;
    printf("Enter the range : ");
    scanf("%d", &x);
    int n;
    printf("Enter the number of elements in array :");
    scanf("%d", &n);
    printf("Enter the members of array\n");
    char array[n];
    for (int i = 0; i < n; i++)
    {
        getchar();
        printf("Element %d = ", i);
        scanf("%c", &array[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (array[i] == '0')
        {
            for (int j = i + 1; j <= i + x; j++)
            {
                if (array[j] == '1')
                {
                    break;
                }
            }
        }
    }
}
int main()
{
    printf("%d", wifirange());
    return 0;
}
//incorrect try again