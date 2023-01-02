#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next ;
};

struct node *head = NULL;
struct node *ptr = NULL;
struct node *tail = NULL;
int count = 0;

void create(int n)
{
    printf("Enter the data in link list : ");
    for (int i = 0 ; i<n ; i++)
    {
        if (i == 0)
        {
            head = (struct node*) malloc (sizeof(struct node));
            ptr = head ;
        }
        else
        {
            ptr -> next = (struct node *) malloc (sizeof(struct node));
            ptr = ptr -> next ;
        }
        scanf("%d",&ptr -> data);
        count++;
    }
    tail = ptr;
    ptr -> next = head;
}

void insert()
{
    struct node *newnode = NULL;
    newnode = (struct node *) malloc (sizeof(struct node));
    printf("\nEnter the data to insert at the begining of the link list : ");
    scanf("%d",&newnode->data);
    newnode -> next = head ;
    head = newnode;
    tail -> next = newnode;
    count++;
}

void insertend()
{
    struct node *newnode = NULL;
    printf("\nEnter the data : ");
    newnode = (struct node *) malloc (sizeof(struct node));
    scanf("%d",&newnode->data);
    tail -> next = newnode;
    tail = newnode;
    newnode -> next = head;
    count++;
}

void insertpos()
{
    struct node *newnode = NULL;
    int pos , i = 1;
    struct node *nextnode = NULL;
    struct node *current = NULL;
    printf("\nEnter the positon of insertion : ");
    scanf("%d",&pos);
    if(pos>count)
    {
        printf("\nEntered position is invalid \n");
    }
    else
    {
        nextnode = head;
        newnode = (struct node*) malloc (sizeof(struct node));
        printf("\nEnter the data : ");
        scanf("%d",&newnode -> data);
        while(i<pos)
        {
            current = nextnode ;
            nextnode = nextnode -> next;
            i++;
        }
        current -> next = newnode;
        newnode -> next = nextnode;
        current = nextnode;
    }
}

/*
void delete()
{
    struct node *temp = NULL;
    temp = head;
    head  = head -> next ;
    free (temp);
    temp = NULL;
    tail -> next = head;
    count--;
}
*/

void display()
{
    printf("list is : \n");
    if(head == NULL)
    {
        printf("list is empty\n");
    }
    else
    {
        ptr = head;
        while(ptr != tail)
        {
            printf("%d\t",ptr -> data);
            ptr = ptr -> next;
        }
        printf("%d",ptr -> data);
    }
}

int main()
{
    int num;
    printf("Enter the number of nodes required for linked list : ");
    scanf("%d",&num);
    create(num);
    display();
    insert();
    display();
    insertend();
    display();
    insertpos();
    display();
}