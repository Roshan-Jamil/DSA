#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void create(int num)
{
    printf("\nEnter the data in list : ");
    struct node *newnode = NULL;
    for (int i = 0; i < num; i++)
    {
        if (head == NULL)
        {
            newnode = (struct node *)malloc(sizeof(struct node));
            head = newnode;
        }
        else
        {
            newnode->next = (struct node *)malloc(sizeof(struct node));
            newnode = newnode->next;
        }
        scanf("%d", &newnode->data);
    }
    newnode->next = NULL;
}

// Reverse singly linkedlist

void reverse()
{
    struct node *current = NULL;
    struct node *nextnode = NULL;
    struct node *prev = NULL;
    current = head;
    while (current != NULL)
    {    
        nextnode = current -> next;
        current -> next = prev;
        prev = current;
        current = nextnode;
    }
    head = prev;
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
            printf("%d\t", temp->data);
            temp = temp->next;
        }
    }
}

int main()
{
    int num;
    printf("Enter the number of nodes required : ");
    scanf("%d", &num);
    create(num);
    display();
    reverse();
    display();
}