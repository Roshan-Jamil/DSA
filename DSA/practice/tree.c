#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *create (int value)
{
    struct node *newnode;
    newnode = (struct node *) malloc (sizeof(struct node));
    newnode -> data = value;
    newnode -> left = NULL;
    newnode -> right = NULL;
    return newnode;
}

struct node *insert (struct node *root , int value)
{
    if (root == NULL)
    {
        root = create(value);
    }
    else 
    {
        if (value < root -> data)
        {
            root -> left = insert (root -> left , value);
        }
        else 
        {
            root -> right = insert (root -> right , value);
        }
    }
    return root;
}

struct node *search(struct node *root , int value)
{
    if (root == value)
    {
        return root ;
    }
    else 
    {
        if (root -> data > value)
    }
}

void inorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root -> left);
    printf("%d  ",root -> data);
    inorder(root -> right);
}

int main ()
{
    struct node *root = NULL;
    root = insert(root , 15);
    insert (root , 10);
    insert (root , 20);
    insert (root , 8);
    insert (root , 12);
    insert (root , 17);
    insert (root , 25);
    printf("\nInorder of this tree is : \n");
    inorder(root);
}