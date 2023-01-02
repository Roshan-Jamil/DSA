#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *left ;
    struct node *right;
};

struct node *create ()
{
    int value;
    struct node *newnode ;
    newnode = (struct node*) malloc (sizeof(struct node));
    printf("\nEnter the data (-1 for no more nodes ) : ");
    scanf("%d",&value);
    if(value == -1)
    {
        return 0;
    }
    newnode -> data = value;
    printf("\nEnter the data for inserting in the left child of %d",value);
    newnode -> left = create ();
    printf("\nEnter the data for inserting in the left child of %d",value);
    newnode -> right = create ();
    return newnode;
}

void preorder(struct node *root)
{
    if(root == NULL)
    {
        return;
    }
    printf("%d\t",root -> data);
    preorder (root -> left);
    preorder (root -> right);
}

void postorder (struct node *root)
{
    if (root == NULL)
    {
        return ;
    }
    postorder (root -> left);
    postorder (root -> right);
    printf("%d\t",root -> data);
}

void inorder (struct node *root )
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
    int choice ;
    struct node *root = NULL;
    root = create();
    do 
    {
        printf("\npress \n1. preorder \n2. inorder \n3. postorder \n4. exit\nEnter the choice : ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1 : 
            {
                printf("\nPreorder of this tree is : \n");
                preorder (root);
                break ;
            }
            case 2 :
            {
                printf("\nInorder of this tree is : \n");
                inorder (root);
                break;
            }
            case 3 :
            {
                printf("\nPostorder of this tree is : \n");
                postorder (root);
                break;
            }
            case 4:
            {
                break;
            }
            default :
            {
                printf("\nEntered choice is invalid \n");
                break;
            }
        }
    }
    while (choice != 4);
}