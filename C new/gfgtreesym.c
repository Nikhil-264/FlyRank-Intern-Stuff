// Given a Binary Tree. Check whether it is Symmetric or not, i.e. whether the binary tree is a Mirror image of itself or not.
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
                //       7
                //     /   \
                //    3     3
                //     \   /  
                //     2   2 just an examples
int main()
{
    node*p = createnode(4);

    return 0;
}