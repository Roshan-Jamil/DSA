#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *next;
};

int count = 0;
struct node *head = NULL;
struct node *tail = NULL;

void createlist (int num)
{
    struct node *newnode = NULL;
    printf("Enter the data in linkedlist : ");
    for (int i = 0 ; i<num ; i++)
    {
        if (head == NULL)
        {
            newnode = (struct node *) malloc (sizeof (struct node));
            head = newnode;
        }
        else 
        {
            newnode -> next = (struct node *) malloc (sizeof(struct node));
            newnode = newnode -> next;
        }
        scanf("%d", &newnode -> data);
        count ++;
    }
    tail = newnode;
    newnode -> next = head;
}

// Insertion at the begining of the linkedlist

void insertion ()
{
    struct node *newnode = NULL;
    newnode = (struct node * ) malloc (sizeof(struct node));
    printf("\nEnter the data for begining of the linkedlist : ");
    scanf("%d",&newnode -> data);
    newnode -> next = head ;
    head = newnode;
    tail -> next = head;
    count ++;
}

// Insertion at the end of the linkedlist

void insertend ()
{
    struct node *newnode  = NULL;
    newnode = (struct node *) malloc (sizeof(struct node));
    printf("\nEnter the data for end of the linkelist : ");
    scanf("%d",&newnode -> data);
    tail -> next = newnode ;
    tail = newnode;
    tail -> next = head;
    count ++;
}

// Insert at any position of the linklist

void insertpos()
{
    struct node *newnode = NULL;
    struct node *prev = NULL;
    struct node *temp = NULL;
    temp = head;
    int pos , i = 1;
    printf("\nEnter the postion of insertion : ");
    scanf("%d",&pos);
    if (pos > count)
    {
        printf("\nEntered position is invalid ");
    }
    else
    {
        printf("\nEnter the data : ");
        newnode = (struct node *) malloc (sizeof(struct node));
        scanf("%d",&newnode -> data);
        while (i < pos)
        {
            prev = temp ;
            temp = temp -> next ;
            i++;
        }
        newnode -> next = temp ;
        prev -> next = newnode;
    }
}

// Delete at the begining of the linklist

void delete ()
{
    struct node *temp = NULL;
    temp = head;
    head  = head -> next ;
    free (temp);
    temp = NULL;
    tail -> next = head;
    count --;
}

void deleteEnd()
{
    struct node *temp = NULL;
    temp = head ;
    while (temp -> next != tail)
    {
        temp = temp -> next;
    }
    tail = temp ;
    temp = temp -> next;
    free (temp);
    temp = NULL;
    tail -> next = head;
    count --;
}

void display()
{
    struct node *temp = NULL;
    temp = head ;
    if (head == NULL)
    {
        printf("\nList is empty\n");
    }
    else 
    {
        printf("linklist is : \n");
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
    printf("Enter the number of nodes : ");
    scanf("%d",&num);
    createlist(num);
    display();
    /*insertion () ;
    display();
    insertend();
    display();
    insertpos();
    display();
    */
    printf("\nAfter deleting at the begining of the linkedlist : \n");
    delete();
    display();
    printf("\nAfter deleting at the end of the linkedlist : \n");
    deleteEnd();
    display();
}