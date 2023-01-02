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
int count = 0;

void create (int n)
{
    struct node *newnode = NULL;
    struct node *temp = NULL;
    printf("Enter the data in link list : ");

    for (int i = 0 ; i<n ; i++)
    {
        if (head == NULL)
        {
            head  = (struct node *) malloc (sizeof(struct node));
            temp = head;
            tail = temp ;
            scanf("%d",&temp -> data);
        }
        else
        {
            newnode = (struct node *) malloc (sizeof(struct node));
            temp -> next = newnode;
            newnode -> prev = temp;
            temp = newnode;
            tail = temp;
            scanf("%d",&newnode -> data);
        }
        count++;
        tail -> next = head;
        head -> prev = tail;
    }
}

void insert ()
{
    struct node *newnode = NULL;
    printf("\nEnter the data for begining of the linkelist : ");
    newnode = (struct node *) malloc (sizeof (struct node));
    scanf("%d",&newnode -> data);
    newnode ->  next = head;
    newnode -> prev = tail;
    head = newnode;
    tail  -> next = head ;
    count ++;
    
}

void insertend()
{
    struct node *newnode  = NULL;
    struct node *temp = NULL;
    printf("\nEnter the data for end of the linklist : ");
    newnode = (struct node *) malloc (sizeof(struct node));
    scanf("%d",&newnode -> data);
    newnode -> next = head;
    newnode -> prev = tail;
    tail -> next = newnode;
    head -> prev = newnode;
    tail = newnode;
    count++;
}

void insertpos()
{
    int pos , i = 0;
    struct node *newnode = NULL;
    struct node *current = NULL;
    struct node *nextnode = NULL;
    printf("\nEnter the postion of instertion : ");
    scanf("%d",&pos);
    if(pos>count)
    {
        printf("Entered postion is invalid \n ");
    }
    else
    {
        nextnode = head;
        newnode = (struct node*) malloc (sizeof(struct node));
        printf("Enter the data : ");
        scanf("%d",&newnode -> data);
        while(i<pos)
        {
            current = nextnode;
            nextnode = nextnode -> next;
            i++;
        }
        newnode -> next = nextnode;
        nextnode -> prev = newnode;
        current -> next = newnode;
        newnode -> prev = current;
        current = nextnode;
        count++;
    }
}

void display()
{
    printf("list is : \n");
    struct node *temp = NULL;
    temp = head;
    if(head == NULL)
    {
        printf("\nlist is empty\n");
    }
    else
    {
        while(temp != tail)
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
    // insert ();
    // display();
    // insertend();
    // display();
    // insertpos();
    // display();
}