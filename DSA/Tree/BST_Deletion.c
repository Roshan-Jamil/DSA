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
    if (root == NULL)
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
    return root;
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
struct node *search(struct node *root , int value)
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
        if (root -> data > value)
        {
            return search (root -> left , value);
        }
        else 
        {
            return search (root -> right , value);
        }
    }
}

struct node *inorderpredecessor (struct node *root)
{
    root = root -> left;
    while (root != NULL)
    {
        root = root -> right;
    }
    return root ;
}

struct node *deletion(struct node *root , int value)
{
    struct node *ipre;
    if (root == NULL)
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
        root -> right = deletion (root -> right , value);
    }
    else 
    {
        ipre = inorderpredecessor (root);
        root -> data = ipre -> data;
        root -> left = deletion (root -> left , ipre -> data);
    }
    return root;
}

int main ()
{
    int value;
    struct node *root = NULL;
    printf("\nEnter the data of root in tree : ");
    scanf("%d",&value);
    root = insert (root , value);
    while (value != -1)
    {
        printf("\nEnter the data for subtree : ");
        scanf("%d",&value);
        if(value == -1)
        {
            break;
        }
        insert (root, value);
    }
    printf("\nInorder of this root is : ");
    inorder(root);
    struct node *searchnode = NULL;
    printf("\nEnter the value to search : ");
    scanf("%d",&value);
    searchnode = search(root , value);
    if(searchnode != NULL)
    {
        printf("\nElemtnt found : %d",searchnode-> data);
    }
    else
    {
        printf("Entered element is not found !! ");
    }
    printf("\nEnter the data you want to delete : ");
    scanf("%d",&value);
    deletion(root , value);
    printf("\nInorder of this root is : \n");
    inorder (root);
    
}