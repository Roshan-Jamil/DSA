#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left ;
    struct node *right;
};

struct node *getnewnode(int value)
{
    struct node *newnode ;
    newnode = (struct node *) malloc (sizeof(struct node));
    newnode -> data = value;
    newnode -> left = NULL;
    newnode -> right = NULL;
    return newnode;
}

struct node *insert(struct node *root , int value)
{
    if (root == NULL)
    {
        root = getnewnode (value);
    }
    else
    {
        if(value <= root -> data)
        {
            root -> left = insert (root -> left , value);
        }
        else
        {
            root -> right = insert (root -> right , value);
        }
    }
    return root ;
}

void inorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder (root -> left);
    printf("%d\t",root -> data);
    inorder (root -> right);
}

void preorder (struct node *root)
{
    if(root == NULL)
    {
        return ;
    }
    printf("%d\t",root -> data);
    preorder (root -> left);
    preorder (root -> right);
}

void postorder (struct node *root)
{
    if(root == NULL)
    {
        return;
    }
    postorder(root -> left);
    postorder (root -> right);
    printf("%d\t",root -> data);
}

int main()
{
    struct node *root = NULL ;
    root = insert(root , 15);
    insert (root , 10);
    insert (root , 20);
    insert (root , 8);
    insert (root , 12);
    insert (root , 17);
    insert (root , 25);
    printf("\nInorder of this tree is : \n");
    inorder(root);
    printf("\nPreorder of this tree is : \n");
    preorder (root);
    printf("\nPostorder of this tree is : \n");
    postorder (root);
    return 0;
}