#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *left ;
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

struct node *insert (struct node *root , int value)
{
    if(root  == NULL)
    {
        root = getnewnode(value);
    }
    else if (value <= root -> data)
    {
        root -> left = insert (root -> left , value);
    }
    else
    {
        root -> right = insert (root -> right , value);
    }
    return root;
}

void insertnewnode(struct node *root , int value)
{
    struct node *prev = NULL;
    while(root != NULL)
    {
        prev = root;
        if (value == root -> data)
        {
            return;
        }
        else if (value < root -> data)
        {
            root = root -> left;
        }
        else
        {
            root = root -> right;
        }
    }
    struct node *new = getnewnode(value);
    if (value < prev -> data)
    {
        prev -> left = new;
    }
    else
    {
        prev -> right  = new;
    }
}


void inorder (struct node *root )
{
    if (root == NULL)
    {
        return;
    }
    inorder (root -> left);
    printf("%d\t",root -> data);
    inorder (root -> right);
}

int main()
{
    int value;
    struct node *root = NULL;
    printf("\nEnter the data for root of the tree : ");
    scanf("%d",&value);
    root = insert (root ,value);
    while(value != -1)
    {
        printf("\nEnter the data for subtrees : ");
        scanf("%d",&value);
        if(value == -1)
        {
            break;
        }
        insert (root , value);
    }
    printf("\nInorder of this tree is : \n");
    inorder (root);
    printf("\nEnter the new data to insert : ");
    scanf("%d",&value);
    insertnewnode(root , value);
    printf("\nInorder of this tree is : \n");
    inorder (root);
    return 0;
}