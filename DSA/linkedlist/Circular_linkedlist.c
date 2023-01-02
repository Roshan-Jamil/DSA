#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void create (int num)
{
    struct node *newnode = NULL;
    printf("\nEnter the data in list : ");
    for (int i = 0 ; i< num ; i++)
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
        scanf("%d",&newnode -> data);
    }
    newnode -> next = head;
}

void display()
{
    struct node *temp = NULL ;
    if (head == NULL)
    {
        printf("\nList is empty\n");
    }
    else 
    {
        printf("\nList is : \n");
        temp = head;
        while (temp -> next != head)
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
    create(num);
    display();
}

