#include <stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;
struct node *head = NULL;
struct node *ptr = NULL;

void push(int value)
{
    struct node *newnode = NULL;
    if(top == NULL)
    {
        head = (struct node*) malloc (sizeof(struct node));
        head -> next = top;
        top = head;
        top -> data = value;
    }
    else
    {
        newnode = (struct node*) malloc (sizeof(struct node));
        newnode -> data = value;
        newnode -> next  = top;
        top = newnode;
    }
}

void pop()
{
    struct node *temp = NULL;
    printf("Deleting data from stack is : %d ",top -> data);
    temp = top ;
    top = top -> next;
    free (temp);
    temp = NULL ;
}

void display()
{
    struct node *temp = NULL;
    temp = top ;
    printf("\nStack is :\n");
    if(top == NULL)
    {
        printf("\nStack is empty\n");
    }
    else
    {
        while(temp)
        {
            printf("%d\n",temp ->data);
            temp = temp -> next;
        }
    }
}
int main()
{
    int choice , data ;
    do
    {
        printf("\npress 1. push \npresss 2. pop \npress 3. display\npress 4. extit\nchoose : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 : 
            {
                printf("\nEnter the data in stack : ");
                scanf("%d",&data);
                push(data);
                break;
            }
            case 2 : 
            {
                pop();
                break;
            }
            case 3 : 
            {
                display();
                break;
            }
            case 4 : 
            {
                break;
            }
            default :
            {
                printf("\nEntered choice is invalid\n");
                break;
            }
        }
    }
    while(choice != 4);
    return 0 ;
}