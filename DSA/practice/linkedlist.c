#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *next;
};

int count = 0;
struct node *head = NULL;

void create (int num)
{
    printf("Enter the data in linked list : ");
    struct node *newnode;
    for (int i = 0 ; i < num ; i++)
    {
        if (head == NULL)
        {
            newnode = (struct node *) malloc (sizeof(struct node));
            head = newnode ;
        }
        else
        {
            newnode -> next = (struct node *) malloc (sizeof(struct node ));
            newnode = newnode -> next;
        }
        scanf("%d",&newnode -> data);
        count ++;
    }
    newnode -> next = NULL;
}

//Inserting node at the bigining of the linkedlist

void insert ()
{
    struct node *newnode = NULL;
    newnode = (struct node *) malloc (sizeof(struct node));
    printf("\nEnter the data for inserting bigining of the linked list : ");
    scanf("%d",&newnode -> data);
    newnode -> next = head;
    head = newnode;
    count++;
}

//Inserting node the the end of the linked list

void insertEnd ()
{
    struct node *newnode = NULL;
    struct node *temp = head;
    newnode = (struct node *) malloc (sizeof (struct node));
    printf("\nEnter the data at the end  of the linked list : ");
    scanf("%d",&newnode -> data);
    while(temp -> next != NULL)
    {
        temp = temp -> next;
    }
    temp -> next = newnode ;
    newnode -> next = NULL;
    count++;
}

//Inserting node at any position of the linke list

void insertpos()
{
    struct node *newnode = NULL;
    struct node *nextnode = NULL;
    struct node *current = NULL;
    int i , pos;
    printf("\nEnter the position of insertion : ");
    scanf("%d",&pos);
    if (pos > count)
    {
        printf ("\nEntered position is Invalid ");
    }
    else
    {
        i = 1;
        current = head;
        newnode = (struct node *) malloc (sizeof(struct node));
        printf("\nEnter the data for node : ");
        scanf("%d",&newnode -> data);
        while(i < pos -1)
        {
            current = current -> next;
            i++;
        }
        nextnode = current -> next;
        current -> next = newnode;
        newnode -> next = nextnode;
        count++;

    }
}

//Deleting at the bigining of the linklist

void delete()
{
    struct node *temp = NULL;
    temp = head;
    head = head -> next;
    free(temp);
    temp = NULL;
    count --;
}

//Deleting at the end of the link list

void deleteEnd()
{
    struct node *temp = NULL;
    temp = head;
    struct node *prev = NULL;
    while (temp -> next != NULL)
    {
        prev = temp;
        temp = temp -> next;
    }
    prev -> next = NULL;
    free(temp);
    temp = NULL;
    count --;

}

// Deleting node at any position of the link list

void deletepos()
{
    struct node *temp = NULL;
    struct node *prev = NULL;
    temp = head;
    int pos , i = 0 ;
    printf("\nEnter the position of the linklist : ");
    scanf("%d",&pos);
    if(pos > count)
    {
        printf("\nEntered position is Invalid !!\n");
    }
    else
    {
        while (i < pos -1)
        {
            prev = temp;
            temp = temp -> next;
            i++;
        }
        prev -> next = temp -> next;
        free(temp);
        temp  = NULL;
        count --;
    }
}

// Reversing single linkedlist

void reverse()
{
    struct node *current = NULL;
    struct node *temp = NULL;
    struct node *prev = NULL;
    prev = current = head;
    
    while (current != NULL)
    {
        current = current -> next;
        prev -> next = temp;
        temp = prev;
        prev = current;
    }
    head = temp;
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
        printf("Linked list is : \n");
        while (temp != NULL)
        {
            printf("%d\t",temp -> data);
            temp = temp -> next;
        }
    }
}

int main()
{
    int num;
    printf("Enter the number of nodes required : ");
    scanf("%d",&num);
    create(num);
    display();
    // insert();
    // display();
    // insertEnd();
    // display();
    // insertpos();
    // display();
    // delete();
    // printf("\n");
    // display();
    // deleteEnd();
    // printf("\n");
    // display();
    // deletepos();
    // printf("\n");
    // display();
    printf("\n");
    reverse();
    display();
}