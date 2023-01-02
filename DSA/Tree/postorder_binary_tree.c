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
    struct node *newnode;
    newnode = (struct node *) malloc (sizeof(struct node));
    printf("\nEnter the data (press -1 for no more nodes) : ");
    scanf("%d",&value);
    if(value == -1)
    {
        return 0;
    }
    newnode -> data = value ;
    printf("\nEnter the data for left child of %d",value);
    newnode -> left = create();
    printf("\nEnter the data for right child of %d",value);
    newnode -> right = create();
    return newnode;
}

void postorder(struct node *root)
{
    if(root == NULL)
    {
        return;
    }
    postorder (root -> left);
    postorder (root -> right);
    printf("%d\t",root -> data);
}

int main()
{
    struct node *root = NULL;
    root = create();
    printf("\npost order of tree is : \n");
    postorder(root);
}