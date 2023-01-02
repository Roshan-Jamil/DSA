#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next ;
    struct node *prev;
};
struct node *head = NULL;
struct node *tail = NULL;

int count = 0 ;

void create()
{
    struct node *newnode = NULL;
    struct node *temp = NULL;
    int choice = 1 ;
    while (choice == 1)
    {
        printf("Enter the data in doubly link list : ");
        newnode = (struct node *) malloc (sizeof(struct node));
        scanf("%d",&newnode -> data);
        newnode -> next = NULL;
        if(head == NULL)
        {
            head = temp = newnode;
        }
        else
        {
            newnode -> prev = temp ;
            temp -> next  = newnode;
            temp = newnode;
            tail = temp ;
        }
        printf("press 1 to continue : ");
        scanf("%d",&choice);
        count++;
    }
}

void delete ()
{
    struct node *temp = NULL;
    temp = head;
    head = head -> next;
    free (temp);
    temp = NULL;
    count --;
}

void deleteEnd()
{
    struct node *temp = NULL;
    temp =tail;
    tail = tail -> prev;
    free(temp);
    temp = NULL;
    tail -> next = NULL;
    count --;
}

void deletepos()
{
    int pos , i = 1;
    struct node *current = NULL;
    struct node *nextnode = NULL;
    printf("\nEnter the positon of deletion : ");
    scanf("%d",&pos);
    current = nextnode = head;
    if(pos > count)
    {
        printf("\nInvalid input \n");
    }
    else
    {
        while(i < pos)
        {
            current = nextnode;
            nextnode = nextnode -> next ;
            i++;
        }
        current -> next = nextnode -> next;
        nextnode -> prev = current;
        free (nextnode);
        nextnode = NULL;
    }
}

void display()
{
    struct node *temp = NULL;
    temp = head;
    printf("\nList is : \n");
    if(head == NULL)
    {
        printf("list is empty ");
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
    printf("\nAfter deleting at the begining of the link list: \n");
    delete();
    display();
    printf("\nAfter deleting at the end of the linkedlist : ");
    deleteEnd();
    display();
    printf("\nAfter deleting at the end of the linkedlist : ");
    deletepos();
    display();
}