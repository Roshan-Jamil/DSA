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
    return newnode ;
}

struct node *insert (struct node *root , int value)
{
    if(root == NULL)
    {
        root = getnewnode(value);
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

struct node *search (struct node *root , int value)
{
    if(root == NULL)
    {
        return NULL;
    }
    if(root -> data == value)
    {
        return root;
    }
    else
    {
        if(root -> data > value)
        {
            return search(root -> left , value);
        }
        else
        {
            return search (root -> right , value);
        }
    }
    return root ;
}

struct node *inorderpredecessor(struct node *root)
{
    root = root -> left ;
    while (root -> left != NULL)
    {
        root = root -> right;
    }
    return root ;
}

struct node *deletion(struct node *root , int value)
{
    struct node *ipre = NULL;
    if(root == NULL)
    {
        return NULL;
    }
    if (root -> left == NULL && root -> right == NULL)
    {
        free(root);
        return NULL;
    }
    if (value < root -> data)
    {
        root -> left = deletion (root -> left , value);
    }
    else if (value > root -> data)
    {
        root -> right = deletion(root ->right , value);
    }
    else
    {
        ipre = inorderpredecessor(root);
        root -> data = ipre -> data;
        root -> left = deletion(root -> left , ipre -> data);
    }
    return root;
}

void inorder (struct node *root)
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
    printf("Enter the data for root of the tree : ");
    scanf("%d",&value);
    root = insert (root , value);
    while (value != -1)
    {
        printf("\nEnter the data in subtree : ");
        scanf("%d",&value);
        if(value == -1)
        {
            break;
        }
        insert (root , value);
    }
    printf("\nInorder of this tree is : \n");
    inorder(root);
    printf("\nEnter the data to search in tree : ");
    scanf("%d",&value);
    struct node *searchnode = NULL;
    searchnode = search(root , value);
    if (searchnode != NULL)
    {
        printf("\nElement found : %d\n", searchnode -> data);
    }
    else
    {
        printf("\nElelment nor found !!\n");
    }
    
    printf("\nEnter the data for deletion : ");
    scanf("%d",&value);
    deletion(root , value);
    printf("\nInorder After deletion of that data is : ");
    inorder(root);
}