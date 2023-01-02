#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next ;
    struct node *prev;
};
struct node * head = NULL ;
struct node *last = NULL;

void create()
{
    struct node *newnode = NULL;
    struct node *temp = NULL;
    int choice =1;
    while(choice == 1)
    {
        newnode = (struct node*) malloc (sizeof(struct node));
        printf("\nEnter the data for linked list : ");
        scanf("%d",&newnode->data);
        newnode -> next = NULL;
        newnode -> prev = NULL;
        if(head == NULL)
        {
            head = temp = newnode;
        }
        else
        {
            newnode -> prev = temp;
            temp -> next  = newnode;
            temp = newnode;
            last = temp;
        }
        printf("\npress 1 to continue : ");
        scanf("%d",&choice);
    }
}

void reverse()
{
    struct node *temp = NULL;
    struct node *curr = NULL;
    curr = head;
    while(curr != NULL)
    {
        temp = curr-> next ;
        curr ->next = curr -> prev;
        curr -> prev = temp ;
        curr = temp;
    }
    curr = head;
    head = last;
    last = curr;
}

void display()
{
    struct node *temp =NULL;
    temp = head;
    if(head == NULL)
    {
        printf("\nlist is empty\n");
    }
    else
    {
        while(temp != NULL)
        {
            printf("%d\t",temp -> data);
            temp = temp -> next;
        }
    }
}

int main()
{
    create();
    display();
    reverse();
    printf("\nAfter reverseing list\n");
    display();
}