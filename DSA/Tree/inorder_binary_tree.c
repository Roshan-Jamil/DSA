#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *create()
{
    int value;
    struct node *newnode ;
    newnode = (struct node*) malloc (sizeof(struct node));
    printf("\nEnter the data (-1 for no more nodes) : ");
    scanf("%d",&value);
    if(value == -1)
    {
        return 0;
    }
    newnode -> data = value;
    printf("\nEnter the data for child of %d",value);
    newnode -> left = create();
    printf("\nEnter the data for child of %d",value);
    newnode -> right = create();
    return newnode ;
}

void inorder (struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d\t",root -> data);
    inorder (root -> right);
}

int main()
{
    struct node *root = NULL;
    root = create();
    printf("Inorder of this tree is : \n");
    inorder(root);
    return 0;
}