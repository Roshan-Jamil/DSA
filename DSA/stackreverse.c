#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *link;
};

int empty (struct node *top)
{
    if(top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

struct node* push(int data , struct node *top)
{
    struct node *newnode;
    newnode = (struct node*) malloc (sizeof(struct node));
    if(newnode == NULL)
    {
        printf("stack underflow ");
        exit(1);
    }
    newnode -> data = data;
    newnode -> link = NULL;
    newnode -> link = top;
    top = newnode;
    return top;
}

void display(struct node *top)
{
    struct node *temp;
    temp = top;
    if(empty(top))
    {
        printf("Stack underflow ");
        exit (1);
    }
    while(temp)
    {
        printf("%d\n",temp->data);
        temp = temp -> link;
    }
    printf("\n");
}

int main()
{
    struct node *top = NULL;
    struct node *top1= NULL;
    struct node *top2 = NULL;
    top = push(1,top);
    top = push(2, top);
    display(top);
}