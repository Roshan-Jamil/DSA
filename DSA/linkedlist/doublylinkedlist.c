#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;
struct node *tail = NULL;
int count = 0 ;

void createlist()
{
    struct node *newnode = NULL ;
    struct node *temp = NULL;
    int choice = 1;
    while(choice == 1)
    {
        newnode = (struct node *) malloc (sizeof(struct node));
        printf("\nEnter the data in list : ");
        scanf("%d",&newnode -> data);
        newnode -> next = NULL;
        if (head == NULL)
        {
            temp = head = newnode ;
        }
        else
        {
            temp -> next = newnode;
            newnode ->prev = temp;
            temp = newnode ;
            tail = newnode;
        }
        printf("\nDo you want to continue [y = 1 or N = 0] : ");
        scanf("%d",&choice);
        count++;
    }
}

void insert()
{
    struct node *newnode = NULL;
    printf("\nEnter the data for begining of the linked list : ");
    newnode = (struct node *) malloc (sizeof(struct node));
    scanf("%d",&newnode->data);
    newnode -> next = head;
    newnode ->prev = NULL;
    head = newnode;
    count ++;
}

void insertend()
{
    struct node *newnode = NULL;
    newnode = (struct node *) malloc (sizeof (struct node));
    printf("\nEnter the data to insert at the end of the linkedlist : ");
    scanf("%d",&newnode->data);
    newnode -> next = NULL;
    newnode -> prev = tail;
    tail -> next = newnode ;
    tail = newnode ;
    count++;
}

void insertpos()
{
    struct node *newnode = NULL;
    struct node *temp = NULL;
    struct node *prv = NULL;
    int pos , i = 1;
    printf("\nEnter the position : ");
    scanf("%d",&pos);
    if (pos > count)
    {
        printf("\nEnter valid positoin \n");
    }
    else
    {
        temp = head;
        newnode = (struct node *) malloc (sizeof(struct node));
        printf("Enter the data : ");
        scanf("%d",&newnode -> data);
        while(i < pos -1)
        {
            temp = temp -> next ;
            i++;
        }
        newnode -> next = temp -> next ;
        newnode -> prev = temp;
        prv = temp -> next;
        temp -> next = newnode;
        newnode -> prev = prv;
    }
}

void display()
{
    struct node *temp = NULL;
    temp = head;
    if(head == NULL)
    {
        printf("\nlist is empty\n");
    }
    else
    {
        printf("linked list : \n");
        while(temp != NULL)
        {
            printf("%d\t",temp -> data);
            temp = temp -> next;
        }
    }
}



int main()
{
    createlist();
    display();
    insert();
    display();
    insertend();
    display();
    insertpos();
    display();
}