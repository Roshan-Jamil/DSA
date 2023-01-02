#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev ;
    struct node *next;
};

struct node * head = NULL;
struct node *tail = NULL;
int count = 0;

void create (int num)
{
    struct node *newnode = NULL;
    struct node *temp = NULL;
    printf("\nEnter the data in list : \n");
    for (int i = 0 ; i < num ; i++)
    {
        if (head == NULL)
        {
            newnode = (struct node *) malloc (sizeof(struct node ));
            head = temp = newnode ; 
        }
        else
        {
            newnode = (struct node *) malloc (sizeof(struct node));
            newnode -> prev = temp;
            temp -> next = newnode;
            temp = newnode;
            tail = temp;
        }
        scanf("%d",&newnode -> data);
        count ++;
    }
    tail -> next = head;
    head -> prev = tail;
}

// Insert at the end of the list

void insertend ()
{
    struct node *newnode = NULL;
    printf("\nEnter the data for list : ");
    newnode = (struct node *) malloc (sizeof(struct node));
    scanf("%d",&newnode -> data);
    newnode ->prev = tail ;
    tail -> next = newnode;
    tail = newnode;
    tail -> next = head;
    head -> prev = tail;
    count ++;
}


// Insert at the begining of the list

void insert ()
{
    struct node *newnode = NULL;
    printf("\nEnter the data for begining of the list : ");
    newnode = (struct node *) malloc (sizeof(struct node));
    scanf("%d",&newnode -> data);
    newnode -> next = head ;
    head -> prev = newnode;
    head = newnode;
    tail -> next = head;
    count ++;
}

// Insert at any position

void insertpos()
{
    struct node *newnode = NULL;
    struct node *current = NULL;
    struct node *temp = NULL;
    int pos , i = 1;
    printf("\nEnter the position of newnode : ");
    scanf("%d",&pos);
    if(pos > count)
    {
        printf("\nEntered position is invalid !!");
    }
    else 
    {
        printf("\nEnter the data for list : ");
        newnode = (struct node *) malloc (sizeof(struct node));
        scanf("%d",&newnode -> data);
        temp = head;
        while (i<pos)
        {
            current = temp;
            temp = temp -> next;
            i++;
        }
        newnode -> next = temp;
        temp -> prev = newnode;
        current -> next = newnode ;
        newnode -> prev = current;
    }
}

void displayrev()
{
    struct node *temp = NULL;
    printf("\nList in reverse is : \n");
    temp = tail;
    while (temp  != head)
    {
        printf("%d\t",temp -> data);
        temp = temp -> prev;
    }
    printf("%d",temp -> data);
}

void display()
{
    struct node *temp = NULL;
    if (head == NULL)
    {
        printf("\nList is empty\n");
    }
    else
    {
        temp = head;
        printf("\nList is : \n");
        while(temp != tail)
        {
            printf("%d\t",temp -> data);
            temp = temp -> next;
        }
        printf("%d",temp ->data);
    }
}

int main()
{
    printf("Enter the number of nodes required : ");
    int num;
    scanf("%d",&num);
    create(num);
    display();
    displayrev();
    insert();
    display();
    displayrev();
    insertend();
    display();
    displayrev();
    insertpos();
    display();
    displayrev();
}