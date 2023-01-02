#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *left;
    struct node *right;
    int height;
};

int getheight (struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return root -> height;
}

struct node *getnewnode (int value)
{
    struct node *newnode ;
    newnode = (struct node *) malloc (sizeof(struct node));
    newnode -> data = value;
    newnode -> left = NULL;
    newnode -> right = NULL;
    newnode -> height = 1;
    return newnode;
}

int balancefactor (struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return getheight (root -> left) - getheight (root -> right);
}

int max (int a , int b)
{
    return a>b?a:b;
}

struct node *rightrotate(struct node *rootY)
{
    struct node *rootX = rootY -> left;
    struct node *T2 = rootX -> right;
    
    rootX -> right = rootY;
    rootY -> left = T2;
    
    rootX ->  height = max (getheight(rootX -> right),getheight(rootX-> left)) +1 ;
    rootY -> height = max (getheight (rootY ->right),getheight(rootY ->left)) +1 ;
    return rootX;
}

struct node *leftrotate (struct node *rootX)
{
    struct node *rootY = rootX ->right;
    struct node *T2 = rootY -> left;
    
    rootY->left = rootX;
    rootX ->right = T2;
    rootY -> height = max(getheight(rootY->right) , getheight (rootY -> left))  +1 ;
    rootX -> height = max(getheight (rootX -> right) , getheight(rootX-> left)) +1 ;
    return rootY;
}

struct node *insert (struct node *root , int value)
{
    if (root == NULL)
    {
        root = getnewnode (value);
    }
    if(value < root -> data)
    {
        root -> left = insert (root -> left , value);
    }
    else if (value > root -> data)
    {
        root -> right = insert (root -> right , value);
    }
    return root;
    
    root -> height = 1 + max (getheight (root -> left), getheight (root -> right));
    int bf = balancefactor (root) ;
    
    // If Left Left case
    
    if(bf > 1 && value < root -> right -> data)
    {
        return rightrotate(root);
    }
    
    // If Right Right case
    
    if(bf < -1 && value > root -> left -> data)
    {
        return leftrotate (root);
    }
    
    // Left Right case
    if (bf > 1 && value > root -> left -> data)
    {
        root -> left = leftrotate(root -> left);
        rightrotate(root);
    }
    
    // Right Left case
    if(bf < -1 && value < root -> right -> data)
    {
        root -> right = rightrotate(root -> right);
        leftrotate (root);
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

void preorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d\t",root -> data);
    preorder (root -> left);
    preorder (root -> right);
}


int main()
{
    struct node *root = NULL;
    root = insert (root , 1);
    root = insert (root , 2);
    root = insert (root , 4);
    root = insert (root , 5);
    root = insert (root , 6);
    root = insert (root , 3);
    preorder(root);
    printf("\n");
    inorder(root);
    return 0;
}