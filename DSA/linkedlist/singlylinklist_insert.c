#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *next ;
};

int count = 0;
struct node *head = NULL;
struct node *ptr = NULL ;

void createlist(int n)
{
    printf("Enter the data in list : ");
    for (int i = 0 ; i<n ; i++)
    {
        if(i == 0)
        {
            head = (struct node*) malloc (sizeof(struct node));
            ptr = head;
        }
        else
        {
            ptr -> next = (struct node*) malloc (sizeof(struct node));
            ptr = ptr -> next ;
        }
        scanf("%d",&ptr -> data);
        count ++;
    }
    ptr -> next = NULL;
}

void insertfront()
{
    struct node *newnode = NULL;
    newnode = (struct node*) malloc (sizeof(struct node));
    printf("\nEnter the data for begining of the linkedlist : ");
    scanf("%d",&newnode -> data);
    newnode -> next = head;
    head = newnode;
}

void insertend()
{
    struct node *newnode = NULL;
    struct node *prev = NULL;
    newnode = (struct node*) malloc (sizeof(struct node));
    printf("\nEnter the data to insert at the end of the linkedlist : ");
    scanf("%d",&newnode->data);
    ptr = head;
    while(ptr -> next != NULL)
    {
        ptr = ptr -> next;
    }
    ptr -> next = newnode;
    newnode -> next = NULL;
}

void insertpos()
{
    int pos , i=1;
    struct node *newnode = NULL;
    struct node *temp = NULL;
    printf("\nEnter the position  of insertion : ");
    scanf("%d",&pos);
    {
        if(pos > count)
        {
            printf("\nInvalid positon \n");
        }
        else
        {
            ptr = head;
            while(i<pos-1)
            {
                ptr = ptr -> next;
                i++;
            }
            temp = ptr ->next;
            newnode = (struct node *) malloc (sizeof(struct node));
            printf("\nEnter the data for linkelist : ");
            scanf("%d",&newnode -> data);
            ptr -> next = newnode;
            newnode ->next = temp;
        }
    }
}

void display()
{
    if (head == NULL)
    {
        printf("\nList is empty : \n");
    }
    else
    {
        ptr = head;
        while(ptr != NULL)
        {
            printf("%d\t",ptr -> data);
            ptr = ptr -> next;
        }
    }
}

int main()
{
    int i;
    printf("Enter the number  of nodes required for linkedlist : ");
    scanf("%d",&i);
    createlist (i);
    display();
    insertfront();
    display();
    insertend();
    display();
    insertpos();
    display();
}