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
    newnode -> next = NULL;
}

void swap ()
{
    int i = 1;
    struct node *prev = head;
    struct node *current = prev -> next;
    struct node *nextnode = current -> next;
    struct node *temp =NULL;
    struct node *ptr = NULL;
    while (current != NULL || current -> next != NULL)
    {
        if (i == 1)
        {
            current -> next = prev;
            prev -> next = nextnode;
            head = current;
            temp = current;
            current = prev;
            prev = temp ;
            free(temp);
            temp =NULL;
            ptr = current;
            prev = nextnode;
            current = nextnode -> next;
            nextnode = nextnode -> next -> next;
        }
        else{
            current -> next = prev;
            prev -> next = nextnode;
            ptr -> next = current;
            temp = current;
            current = prev;
            prev = temp ;
            free(temp );
            temp = NULL;
            ptr = current;
            prev = nextnode;
            current = nextnode -> next;
            nextnode = nextnode -> next -> next;
        }
        i++;
    }
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
        while (temp != NULL)
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
    swap();
}