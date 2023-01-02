#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *getnewnode (int value)
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
        if (value <= root -> data)
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

struct node *search (struct node *root , int value)
{
    if (root == NULL)
    {
        return ;
    }
    if (root -> data == value)
    {
        return root;
    }
    else
    {
        if (root -> data > value)
        {
            return search(root -> left , value);
        }
        else 
        {
            return search (root -> right , value);
        }
    }
}

void inorder (struct node *root)
{
    if(root == NULL)
    {
        return;
    }
    inorder (root -> left);
    printf("%d\t",root -> data);
    inorder (root -> right);
}

int main ()
{
    int value;
    struct node *root = NULL;
    printf("\nEnter the root of this tree : ");
    scanf("%d",&value);
    root = insert (root , value);
    while(value != -1)
    {
        printf("\nEnter the data in subtree : ");
        scanf("%d",&value);
        if(value == -1)
        {
            break;
        }
        insert (root , value);
    }
    
    printf("\nInorder of this tree is : ");
    inorder(root);
    printf("\nEnter the data for search : ");
    scanf("%d",&value);
    struct node *searchnode = search(root , value);
    if(searchnode != NULL)
    {
        printf("\nElement found : %d" , searchnode -> data);
    }
    else
    {
        printf("\nElement not found !!");
    }
}