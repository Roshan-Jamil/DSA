#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void createlist(int n)
{
    struct node *ptr = NULL;
    struct node *head = NULL;
    for (int i = 0 ; i < n ; i++)
    {
        if (i == 0)
        {
            head = (struct node *) malloc (sizeof(struct node));
            ptr = head;
        }
        else
        {
            ptr->next = (struct node *) malloc (sizeof (struct node));
            ptr = ptr ->next;
        }
        scanf("%d",&ptr->data);
    }

    ptr->next = NULL;
    ptr = head;
}

void display()
{
    struct node *ptr,*head;
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d\t",ptr->data);
        ptr = ptr->next;
    }
    
}
// void insert_node()
// {
//     struct node *ptr , *head;
//     struct node *newhead = NULL;
//     ptr = head;
//     newhead = (struct node*) malloc (sizeof (struct node));
//     printf("\nEnter the new element in linkedlist : ");
//     scanf("%d",&newhead ->data);
//     newhead->next = head;
//     head = newhead;
//     ptr = head;
//}

void reverse()
{
    struct node *prev = NULL,*ptr , *head;
    ptr = head;
    if(head == NULL)
    {
        printf("\nEmpty linked list  ");
        return;
    }
    else
    {
        while(ptr != NULL)
        {
            ptr = ptr ->next;
            prev = ptr;
        }
    head = prev;
    }
}

int main()
{
    int n;
    printf("Enter the number of nodes required for linkedlist : ");
    scanf("%d",&n);
    printf("Enter the elements for linkedlist : ");
    createlist(n);
    display();
    reverse();
    display();
}
