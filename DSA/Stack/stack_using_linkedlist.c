#include <stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};
struct node *top = NULL;

void push(int data)
{
    struct node *newnode  = (struct node*) malloc (sizeof(struct node));
    if(newnode == NULL)
    {
        printf("stack is overflow : ");
    }
    else
    {
        newnode -> data = data ;
        newnode -> link = NULL ;
        newnode -> link = top;
        top = newnode ;
    }
}

void display()
{
    struct node *temp ;
    temp = top;
    printf("Stack is : \n");
    while (temp)
    {
        printf("%d\n",temp -> data);
        temp = temp -> link;
    }
    printf("\n");
}

void pop ()
{
    if(top == NULL)
    {
        printf("\nstack underflow\n");
    }
    else
    {
        struct node *temp = NULL;
        temp = top ;
        printf("\nDeleting element is : %d\n",top->data);
        top = top -> link;
        free (temp);
        temp = NULL;
    }
}

int main ()
{
    push(5);
    push(4);
    push(3);
    push(2);
    push(1);
    display();
    pop();
    printf("After deleting top stack is : \n");
    display();
}