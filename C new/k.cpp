// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// #define MAX_HEIGHT 100000

// struct Node
// {
//     int data;
//     struct Node *left;
//     struct Node *right;
// };

// struct Node *newNode(int val)
// {
//     struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
//     temp->data = val;
//     temp->left = NULL;
//     temp->right = NULL;
//     return temp;
// }

// struct Node *buildTree(char *str)
// {
//     if (strlen(str) == 0 || str[0] == 'N')
//         return NULL;

//     char *token;
//     char *rest = str;
//     char *delimiter = " ";

//     struct Node *root = newNode(atoi(strtok_r(rest, delimiter, &rest)));

//     struct Node **queue = (struct Node **)malloc(MAX_HEIGHT * sizeof(struct Node *));
//     int front = 0, rear = 0;
//     queue[rear++] = root;

//     while (front != rear && strlen(rest))
//     {
//         struct Node *currNode = queue[front++];
//         token = strtok_r(rest, delimiter, &rest);

//         if (strcmp(token, "N") != 0)
//         {
//             currNode->left = newNode(atoi(token));
//             queue[rear++] = currNode->left;
//         }

//         if (strlen(rest) == 0)
//             break;

//         token = strtok_r(rest, delimiter, &rest);

//         if (strcmp(token, "N") != 0)
//         {
//             currNode->right = newNode(atoi(token));
//             queue[rear++] = currNode->right;
//         }
//     }

//     free(queue);
//     return root;
// }

// // Function to perform inorder traversal and print the binary tree
// void inorderTraversal(struct Node *root)
// {
//     if (root != NULL)
//     {
//         inorderTraversal(root->left);
//         printf("%d ", root->data);
//         inorderTraversal(root->right);
//     }
// }

// // Main function
// int main()
// {
//     char str[] = "1 2 3 N N 4 5";

//     // Build the binary tree
//     struct Node *root = buildTree(str);

//     // Traverse and print the binary tree (inorder traversal)
//     printf("Inorder traversal of the binary tree: ");
//     inorderTraversal(root);
//     printf("\n");

//     return 0;
// }
