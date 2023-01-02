#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *left ;
    struct node *right;
};

struct node *create()
{
    int value;
    struct node *newnode;
    newnode = (struct node *) malloc (sizeof(struct node));
    printf("\nEnter the data (press -1 for no more nodes ) : ");
    scanf("%d",&value);
    if (value == -1)
    {
        return 0;
    }
    newnode -> data = value;
    printf("\nEnter the data for left child of %d ",value);
    newnode -> left = create();
    printf("\nEnter the data for right child of %d ",value);
    newnode -> right = create();
    return newnode;
}

void preorder(struct node *root)
{
    if (root == 0)
    {
        return;
    }
    printf("%d\t",root->data);
    preorder(root -> left);
    preorder(root -> right);
}

int main()
{
    struct node *root = NULL;
    root = create();
    printf("\nPreorder of this data is : \n");
    preorder(root);
}