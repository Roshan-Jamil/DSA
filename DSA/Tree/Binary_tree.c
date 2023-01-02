#include<stdio.h>
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
    newnode = (struct node *) malloc (sizeof(struct node));
    printf("\nEnter the data in tree (press -1 to stop ) : ");
    scanf("%d",&value);
    if(value == -1)
    {
        return 0;
    }
    newnode -> data = value;
    printf("\nEnter the data for left child of %d ", value);
    newnode -> left = create();
    printf("\nEnter the data for right child of %d " , value);
    newnode -> right = create();
    return newnode ;
}

int main()
{
    struct node *root = NULL;
    root = create();
    return 0;
}