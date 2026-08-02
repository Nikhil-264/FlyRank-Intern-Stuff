#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left, *right;
} node;

node *createnode(int data)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

void inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// int numLeaves(node *root)
// {
//     static int k = 0;
//     if (root == NULL)
//         k++;
//     if (root != NULL)
//     {
//         numLeaves(root->left);
//         // printf("%d ", root->data);
//         numLeaves(root->right);
//     }
// }

int numLeaves(node *root)
{
    if (root == NULL)
        return 0;
    else if (root->left == NULL && root->right == NULL)
        return 1;
    else
        return numLeaves(root->left) + numLeaves(root->right);
}

int main()
{
    node *p = createnode(5);
    node *p1 = createnode(3);
    node *p2 = createnode(6);
    node *p3 = createnode(1);
    node *p4 = createnode(4);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    printf("%d", numLeaves(p));

    return 0;
}