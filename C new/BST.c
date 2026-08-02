
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

int isBST(node *root)
{
    static node *prev = NULL;
    if (root != NULL)
    {
        // check left subtree
        if (!isBST(root->left))
            return 0;
        if (prev != NULL && root->data <= prev->data)
            return 0;
        prev = root;
        return isBST(root->right);
    }
    else
        return 1;
}
// bool isBST(node* root, node* &prev) {
//     if (root == nullptr)
//         return true;
    
//     if (!isBST(root->left, prev))
//         return false;
    
//     if (prev != nullptr && root->data <= prev->data)
//         return false;
    
//     prev = root;
    
//     return isBST(root->right, prev);
// }

// bool isBST(node* root) {
//     node* prev = nullptr;
//     return isBST(root, prev);
// }


int searchinBST(node *root, int key)
{
    if (root->data == key)
        return 1;
    if (root != NULL && key > root->data)
    {
        root = root->right;
        searchinBST(root, key);
    }
    else if (root != NULL && key < root->data)
    {
        root = root->left;
        searchinBST(root, key);
    }
    else
        return -1;
}

node *search(node *root, int key)
{
    if (root == NULL)
        return NULL;
    if (root->data == key)
        return root;
    else if (root->data > key)
        return search(root->left, key);
    else
        return search(root->right, key);
}
// insertion
void insertion(node *root, int key)
{
    if (root->data == key)
        printf("Cant insert a .Element already present");
    node *newnode = createnode(key);
    if (key > root->data && root->right != NULL)
    {
    }
}

void insert(node *root, int key)
{
    node *prev = NULL;
    node *ptr;
    while (root != NULL)
    {

        prev = root;
        if (key == root->data)
        {
            printf("Cant insert\n");
            return;
        }
        else if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    ptr = createnode(key);
    if (key < prev->data)
        prev->left = ptr;
    else
        prev->right = ptr;
}

node *inorderpredescessor(node *root)
{
    root = root->left;
    while (root->right != NULL)
        root = root->right;
    return root;
}
// deletion
node *delete(node *root, int key)
{
    node *iPre;
    if (root == NULL)
        return NULL;
    if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }
    // searching the node first
    if (key < root->data)
        root->left = delete (root->left, key);
    else if (key > root->data)
        root->right = delete (root->right, key);
    // deletion strategy
    else
    {
        iPre = inorderpredescessor(root);
        root->data = iPre->data;
        root->left = delete (root->left, iPre->data);
    }
    return root;
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

    // inorder(p);
    // printf("%d", isBST(p));
    // printf("%d", search(p, 4)->data);
    // if (search(p, 2) != NULL)
    //     printf("Element is present in tree");
    // else
    //     printf("Element is not in tree");
    insert(p, 2);
    inorder(p);
    printf("\n");
    delete (p, 3);
    inorder(p);
    printf("\n");
    delete (p, 2);
    inorder(p);
    return 0;
}
//         5
//     /      \
            //    3        6
//  /   \      
            //  1     4
