#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

node *createnode(int data)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

// traversal
// preorder traversal => root left right is the visiting order
void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// postorder traversal
// left right root

void postorder(node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// inorder traveesal
// left -> root -> right
void inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main()
{
    node *p = (node *)malloc(sizeof(node));
    p->left = NULL;
    p->right = NULL;
    node *p1, *p2;
    p->data = 3;
    p1 = createnode(4);
    p2 = createnode(5);
    // connecting nodes
    p->left = p1;
    p->right = p2;
    p1->left = createnode(13);
    p1->right = createnode(6789);
    p2->left = createnode(-1);
    p2->right = createnode(10);
    // given tree is
    //            3
    //         /     \
      //      4        5
    //       /\        /\
      //    13 6789  -1 10
    printf("preorder: ");
    preorder(p);
    printf("\n");
    printf("postorder:");
    postorder(p);
    printf("\n");
    printf("inorder : ");
    inorder(p);

    return 0;
}