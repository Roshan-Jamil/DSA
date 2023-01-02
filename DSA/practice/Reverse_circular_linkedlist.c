#include <stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

void create(int num)
{
    struct node *newnode ;
    printf("\nEnter the data in list : ");
    for (int i = 0 ; i<num ; i++)
    {
        if (head == NULL)
        {
            newnode = (struct node *) malloc (sizeof(struct node));
            head = newnode;
        }
        else 
        {
            newnode -> next = (struct node *) malloc (sizeof(struct node));
            newnode = newnode ->  next;
        }
        scanf("%d",&newnode -> data);
    }
    tail = newnode;
    newnode -> next = head;
}

//Reverse circular linkedlist

void reverse()
{
    struct node *current = NULL;
    struct node *nextnode = NULL;
    struct node *prev = tail;
    current = head;
    while (current != tail)
    {    
        nextnode = current -> next;
        current -> next = prev;
        prev = current;
        current = nextnode;
    }
    nextnode = head;
    current -> next = prev;
    prev = current;
    current = nextnode;
    tail = nextnode;
    head = prev;
}

void display()
{
    struct node *temp = NULL;
    temp = head;
    if (head == NULL)
    {
        printf("\nList is empty\n");
    }
    else 
    {
        printf("\nList is : \n");
        while (temp != tail)
        {
            printf("%d\t",temp -> data);
            temp = temp -> next;
        }
        printf("%d",temp -> data);
    }
}

int main()
{
    int num;
    printf("Enter the number of nodes required : ");
    scanf("%d",&num);
    create(num);
    display();
    reverse();
    display();
}