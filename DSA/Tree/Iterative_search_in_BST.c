#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *getnewnode(int value)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

struct node *insert(struct node *root, int value)
{
    if (root == NULL)
    {
        root = getnewnode(value);
    }
    else
    {
        if (value <= root->data)
        {
            root->left = insert(root->left, value);
        }
        else
        {
            root->right = insert(root->right, value);
        }
    }
    return root;
}

void inorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d\t", root->data);
    inorder(root->right);
}

struct node *search(struct node *root , int value)
{
    while(root != NULL)
    {
        if (value == root -> data)
        {
            return root ;
        }
        else if(value < root -> data)
        {
            root = root -> left;
        }
        else
        {
            root = root -> right;
        }
    }
    return NULL;
}

int main()
{
    int value;
    struct node *root = NULL;
    printf("\nEnter the data for the root of the tree : ");
    scanf("%d", &value);
    root = insert(root, value);
    while (value != -1)
    {
        printf("\nEnter the data for subtree : ");
        scanf("%d", &value);
        if (value == -1)
        {
            break;
        }
        insert(root, value);
    }
    printf("\nInorder of this tree is : \n");
    inorder(root);
    printf("\nEnter the data to search : ");
    scanf("%d",&value);
    struct node *searchnode ;
    searchnode = search (root , value);
    if(searchnode != NULL)
    {
        printf("\nElement found : %d\n",searchnode -> data);
    }
    else
    {
        printf("\nElement not found !!!\n");
    }
}