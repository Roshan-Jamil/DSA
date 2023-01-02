#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *ptr = NULL;

void create (int data)
{
    struct node *newnode = NULL;
    printf("\nEnter the data in list : ");
    for (int i = 0 ; i<data; i++)
    {
        if (head == NULL)
        {
            head = (struct node *) malloc (sizeof(struct node));
            ptr = head ;
        }
        else
        {
            ptr -> next = (struct node *) malloc (sizeof(struct node));
            ptr = ptr -> next;
        }
        scanf("%d",&ptr -> data);
    }
    ptr -> next = NULL;
}

void swap (int n)
{
    struct node *current = NULL;
    struct node *prev = NULL;
    struct node *nextnode = NULL;
    struct node *temp = NULL;
    prev = head;
    for (int i = 0 ; i < n/2 ; i++)
    {
        current = prev -> next ;
        nextnode = current -> next;
        temp = prev;
        prev-> next = current -> next;
        current -> next = temp;
        prev = current = nextnode;
    }
}

void display()
{
    struct node *temp = NULL;
    if (head == NULL)
    {
        printf("\nList is empty \n");
    }
    else
    {
        printf("\nStack is : \n");
        temp = head ;
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
    printf("Enter the nunber of nodes required for list : ");
    scanf("%d",&num);
    create(num);
    display();
    swap(num);
    display();
}