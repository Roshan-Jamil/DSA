#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;
struct node *tail  = NULL;
int count = 0;

void create(int num)
{
    struct node *newnode = NULL;
    struct node *temp = NULL;
    printf("\nEnter the data in link list : ");
    for (int i = 0 ; i < num ; i++)
    {
        newnode = (struct node *) malloc (sizeof(struct node));
        scanf("%d",&newnode -> data);
        newnode -> next = NULL;
        if (head == NULL)
        {
            head = temp =  newnode;
            temp -> prev =  NULL;
        }
        else 
        {
            newnode -> prev = temp;
            temp -> next = newnode;
            temp = newnode;
            tail = temp;
        }
        count++;
    }
}

//insert at the begining of the linklist
void insert()
{
    struct node *newnode = NULL;
    newnode = (struct node *) malloc (sizeof(struct node));
    printf("\nEnter the data of node : ");
    scanf("%d",&newnode -> data);
    newnode -> next = head;
    head -> prev = newnode;
    head = newnode;
    count++;
}

void insertend()
{
    struct node *newnode = NULL;
    newnode = (struct node *) malloc (sizeof(struct node));
    printf("\nEnter the data for the end of the linklist : ");
    scanf("%d",&newnode -> data);
    tail -> next = newnode;
    newnode -> prev = tail;
    tail = newnode;
    newnode -> next = NULL;
    count++;
}

// Insert at any position

void insertpos()
{
    struct node *newnode = NULL;
    struct node *temp = NULL;
    struct node *ptr = NULL;
    int pos, i= 1;
    printf("\nEnter the position of newnode : ");
    scanf("%d",&pos);
    if (pos > count)
    {
        printf("Entered position is invalid !!!\n");
    }
    else
    {
        temp = head;
        while(i<pos)
        {
            ptr = temp;
            temp = temp -> next;
            i++;
        }
        printf("Enter the data of newnode : ");
        newnode = (struct node*) malloc (sizeof(struct node));
        scanf("%d",&newnode -> data);
        ptr -> next = newnode;
        newnode -> prev = ptr;
        newnode -> next  = temp;
        temp -> prev = newnode;
        count++;
    }
}

// Deleting at the begining of the linklist

void delete()
{
    struct node *temp = head;
    head = head -> next;
    head -> prev = NULL;
    free(temp);
    temp = NULL;
    count --;
}
// Deleting at the end of the linklist

void deleteEnd ()
{
    struct node *temp = NULL;
    temp = tail;
    tail = tail -> prev;
    tail -> next = NULL;
    free (temp);
    temp = NULL;
    count--;
}

// Deleting at any position of the linklist
void deletepos ()
{
    int pos, i = 1;
    struct node *current = NULL;
    struct node *temp = NULL;
    struct node *ptr =  NULL;
    printf("\nEnter the position of the deletion : ");
    scanf("%d",&pos);
    if (pos > count)
    {
        printf("\nEntered postion is invalid \n");
    }
    else 
    {
        current = head;
        while(i<pos)
        {
            temp = current ;
            current  = current -> next;
            i++;
        }
        temp -> next = current -> next;
        ptr = current;
        current = current -> next;
        current -> prev = temp;
        free (ptr);
        ptr = NULL;
    }
}

void displayreverse()
{
    struct node *temp = NULL;
    temp = tail;
    printf("\nReversed List is : \n");
    while(temp != NULL)
    {
        printf("%d\t",temp-> data);
        temp = temp -> prev;
    }
}

void display()
{
    struct node *temp = NULL;
    temp = head ;
    if (head == NULL)
    {
        printf("\nList is empty !! ");
    }
    else 
    {
        printf("\nList is : \n");
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
    printf("Enter the number of nodes reqired : ");
    scanf("%d",&num);
    create(num);
    display();
    // insert();
    // display();
    // insertend();
    // display();
    // insertpos();
    // display();
    delete ();
    printf("\nAfter Deleting at the begining of the linklist : \n");
    display();
    deleteEnd ();
    printf("\nAfter Deleting at the end of the linklist : \n");
    display();
    deletepos ();
    printf("\nAfter Deleting at the any position of the linklist : \n");
    display();
}