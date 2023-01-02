#include<stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;
int count = 0 ;

void create(int data)
{
    struct node *ptr = NULL;
    struct node *temp = NULL;
    printf("Enter the data of link list : ");
    for (int i = 0 ; i<data ; i++)
    {
        if (i == 0)
        {
            head = (struct node *) malloc (sizeof(struct node));
            ptr = head;
            scanf("%d",&ptr -> data);
            ptr -> next = NULL;
        }
        else
        {
            temp = ptr -> next;
            temp = (struct node *) malloc (sizeof(struct node));
            ptr -> next = temp;
            temp ->prev = ptr;
            ptr = temp;
            scanf("%d",&temp -> data);
            temp -> next = NULL;
            tail = temp;
        }
        count ++;
    }
}

void insert ()
{
    struct node *newnode = NULL;
    printf("\nEnter the data at the begining of the list : ");
    newnode = (struct node*) malloc (sizeof(struct node));
    scanf("%d",&newnode -> data);
    newnode -> next = head;
    newnode ->prev = NULL;
    head = newnode;
    count ++;
}

void insertend()
{
    struct node *newnode = NULL;
    struct node *temp = NULL;
    temp = tail;
    printf("\nEnter the data at the end of the list : ");
    newnode = (struct node *) malloc (sizeof(struct node));
    scanf("%d",&newnode ->data);
    temp -> next = newnode;
    newnode -> prev = temp;
    newnode -> next = NULL;
    tail = newnode;
    count ++;
}

void insertpos()
{
    struct node *newnode = NULL;
    struct node *current = NULL;
    struct node *nextnode = NULL;
    int pos , i = 1;
    printf("\nEnter the position of insertion : ");
    scanf("%d",&pos);
    if(pos > count)
    {
        printf("Invalid position : ");
    }
    else
    {
        current = head;
        while(i<pos - 1)
        {
            current = current -> next;
            i++;
        }
        nextnode = current -> next;
        newnode = (struct node*) malloc (sizeof(struct node));
        printf("\nEnter the data : ");
        scanf("%d",&newnode->data);
        newnode -> prev = current;
        current -> next =newnode;
        newnode -> next = nextnode;
        nextnode ->prev = newnode;
        count ++;
    }
}

void delete ()
{
    struct node *temp  = NULL;
    printf("\nDeleting at the begining of doubly link list : \n");
    temp =  head;
    head = head -> next;
    free(temp);
    temp = NULL ;
    count --;
}

void deleteEnd()
{
    struct node *temp = NULL;
    printf("\nDeleting at the end of the doubly link list : \n");
    temp = tail;
    tail = tail -> prev;
    tail-> next = NULL;
    free (temp);
    temp = NULL ;
    count --;
}

void deletepos()
{
    struct node *current = NULL ;
    struct node *nextnode = NULL;
    int pos , i = 1;
    printf("\nEnter the position : ");
    scanf("%d",&pos);
    if(pos > count)
    {
        printf("\nEntered position is invalid \n");
    }
    else
    {
        nextnode = head;
        while(i<pos)
        {
            current = nextnode;
            nextnode = nextnode -> next;
            i++;
        }
        current -> next = nextnode -> next;
        nextnode -> prev = current;
        count--;
    }
}

void display()
{
    struct node *temp = NULL;
    if(head == NULL)
    {
        printf("\nlist is empty\n");
    }
    else
    {
        printf("\nlist is : \n");
        temp = head ;
        while (temp != NULL)
        {
            printf("%d\t",temp -> data);
            temp = temp-> next;
        }
    }
    
}

int main()
{
    int num;
    printf("Enter the nunber of nodes required for list : ");
    scanf("%d",&num);
    create(num);
    display();
    /*
    insert();
    display();
    insertend();
    display();
    insertpos();
    display();
    delete();
    display();
    deleteEnd();
    display();
    deletepos();
    display();
    */
    
}