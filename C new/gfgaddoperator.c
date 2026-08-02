// Given a string S that contains only digits (0-9) and an integer target, return all possible strings to insert the binary operator ' + ', ' - ', or ' * ' between the digits of S so that the resultant expression evaluates to the target value.

// Note: Operands in the returned expressions should not contain leading zeros. For example, 2 + 03 is not allowed whereas 20 + 3 is fine. It is allowed to not insert any of the operators.

// Example 1:

// Input:
// S = "123"
// target = 6
// Output: { "1*2*3", "1+2+3"}
// Explanation: Both "1*2*3" and "1+2+3" evaluate to 6.

// Example 2:

// Input:

// S = "3456237490"
// target = 9191
// Output: { } 
// Explanation: There are no expressions that can be created from "3456237490"  to evaluate to 9191.

// Example 3:

// Input:
// S = "12"
// target = 12
// Output: { "12"} 
// Explanation: S itself matches the target. No other strings are possible.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function addOperators() which takes string S and integer target as parameters and returns a list of strings that contains all valid possibilities.

// Expected Time Complexity: O(|S|*4^|S|)
// Expected Auxiliary Space: O(|s|*3^|S|)

// Constraints:
// 1 ≤ |S| ≤ 10
// S consists of only digits.
// -231 ≤ target ≤ 231-1
//try in holidays

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void generateExpressions(char* S, int target, char* expression, long long currentValue, int index, char* result[], int* count);

void addOperators(char* S, int target, char* result[], int* count) {
    *count = 0;
    int len = strlen(S);
    char* expression = (char*)malloc((2 * len + 1) * sizeof(char));
    expression[0] = '\0';

    generateExpressions(S, target, expression, 0, 0, result, count);

    free(expression);
}

void generateExpressions(char* S, int target, char* expression, long long currentValue, int index, char* result[], int* count) {
    int len = strlen(S);
    if (index == len) {
        if (currentValue == target) {
            result[*count] = strdup(expression);
            (*count)++;
        }
        return;
    }

    long long num = 0;
    for (int i = index; i < len; i++) {
        num = num * 10 + (S[i] - '0');

        if (index == 0) {
            // Start of the expression
            sprintf(expression, "%lld", num);
            generateExpressions(S, target, expression, num, i + 1, result, count);
        } else {
            // Append '+' operator
            sprintf(expression + strlen(expression), "+%lld", num);
            generateExpressions(S, target, expression, currentValue + num, i + 1, result, count);
            expression[strlen(expression) - digitCount(num) - 1] = '\0';

            // Append '-' operator
            sprintf(expression + strlen(expression), "-%lld", num);
            generateExpressions(S, target, expression, currentValue - num, i + 1, result, count);
            expression[strlen(expression) - digitCount(num) - 1] = '\0';

            // Append '*' operator
            sprintf(expression + strlen(expression), "*%lld", num);
            generateExpressions(S, target, expression, currentValue * num, i + 1, result, count);
            expression[strlen(expression) - digitCount(num) - 1] = '\0';
        }

        if (S[index] == '0') {
            break; // Avoid leading zeros
        }
    }
}

int digitCount(long long num) {
    if (num == 0) {
        return 1;
    }

    int count = 0;
    while (num > 0) {
        num /= 10;
        count++;
    }
    return count;
}

int main() {
    char* S = "147";
    int target = 29;
    char* result[100];
    int count;

    addOperators(S, target, result, &count);

    printf("Output: { ");
    for (int i = 0; i < count; i++) {
        printf("\"%s\"", result[i]);
        if (i < count - 1) {
            printf(", ");
        }
    }
    printf(" }\n");

    return 0;
}

