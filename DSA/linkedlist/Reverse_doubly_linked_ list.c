#include <stdio.h>
#include <stdlib.h>

/*struct node 
{
    int data;
    struct node *next ;
    struct node *prev ;
};

struct node *head = NULL;
struct node *tail = NULL;

void create ()
{
    struct node *newnode = NULL;
    struct node *temp = NULL;
    int choice = 1;
    
    while(choice == 1)
    {
        newnode = (struct node *) malloc (sizeof(struct node));
        printf("\nEnter the data in list : ");
        scanf("%d",&newnode -> data);
        newnode -> next = NULL;
        if(head == NULL)
        {
            temp = head = newnode;
        }
        else
        {
            temp -> next = newnode;
            newnode -> prev = temp;
            temp = newnode;
            tail = temp;
        }
        printf("\nDo you want to continue[y=1 or N =0] :  ");
        scanf("%d",&choice);
    }
}

void display()
{
    struct node *temp = NULL;
    temp = head ;
    printf("\n List is : ");
    if(head == NULL)
    {
        printf("\nList is empty\n");
    }
    else
    {
        while(temp != NULL)
        {
            printf("%d\t",temp -> data);
            temp = temp -> next;
        }
        printf("\n");
    }
}

void reverse()
{
    struct node *nextnode = NULL;
    struct node *current = NULL;
    current = head;
    while(current != NULL)
    {
        nextnode = current -> next;
        current -> next = current -> prev;
        current -> prev = nextnode;
        current = nextnode;
    }
    current = head;
    head = tail;
    tail = current;

}

int main()
{
    create();
    display();
    reverse();
    printf("\nAfter reversing doubly linked list : \n");
    display();
    return 0;
}


struct node
{
    int data;
    struct node *next ;
    struct node *prev;
};
struct node *head = NULL;
struct node *tail = NULL;

void create()
{
    struct node *newnode = NULL;
    struct node *temp = NULL;
    int choice = 1;
    while(choice == 1)
    {
        printf("Enter the data in list : ");
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
            temp -> next = newnode;
            temp = newnode;
            tail  = temp;
        }
        printf("\n Do you want to continue : ");
        scanf("%d",&choice);
    }
}

void reverse ()
{
    struct node *current = NULL;
    struct node *nextnode = NULL;
    current = head;
    while(current != NULL)
    {
        nextnode = current -> next;
        current -> next = current -> prev;
        current -> prev = nextnode;
        current  = nextnode;
    }
    current = head;
    head = tail ;
    tail = current ;
}


void display()
{
    struct node *temp = NULL;
    temp =  head;
    printf("\nList is : \n");
    if(head == NULL)
    {
        printf("\nList is empty\n");
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
    printf("\nAfter reversing doubly linked list : \n");
    reverse();
    display();
}
*/

struct node
{
    int data;
    struct node *next ;
    struct node *prev;
};

struct node *head = NULL;
struct node *tail = NULL;

void create ()
{
    struct node *temp  = NULL;
    struct node *newnode = NULL;
    int choice = 1 ;
    while(choice == 1)
    {
        newnode = (struct node *) malloc (sizeof(struct node));
        printf("Enter the data : ");
        scanf("%d",&newnode -> data);
        newnode -> next = NULL;
        if (head == NULL)
        {
            head = temp = newnode;
        }
        else
        {
            newnode -> prev = temp;
            temp -> next = newnode;
            temp = newnode;
            tail = temp ;
        }
        printf("Press 1 to continue ");
        scanf("%d",&choice);
    }
}

void reverse()
{
    struct node *current = NULL;
    struct node *nextnode = NULL;
    current= head;
    while(current != NULL)
    {
        nextnode = current -> next;
        current -> next = current -> prev;
        current -> prev = nextnode;
        current = nextnode;
    }
    current = head;
    head = tail ;
    tail = current;
}

void display()
{
    struct node *temp = NULL;
    temp = head;
    printf("List is : \n");
    if(head == NULL)
    {
        printf("List is empty\n");
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
    printf("\nAfter reversing doubly linked list : \n");
    reverse();
    display();
}