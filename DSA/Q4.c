#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void displaylist()
{
    int n, new;
    struct node *ptr, *head, *newhead, *temp, *newelement;
    printf("Enter the number of nodes you want to create : ");
    scanf("%d", &n);
    printf("Enter the element in nodes : ");

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            head = (struct node *)malloc(sizeof(struct node));
            ptr = head;
        }
        else
        {
            ptr->next = (struct node *)malloc(sizeof(struct node));
            ptr = ptr->next;
        }
        scanf("%d", &ptr->data);
    }

    ptr->next = NULL;

    ptr = head;
    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }

    // To insert new head or element at the begining of the linked list
    newhead = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the element for newhead : ");
    scanf("%d", &newhead->data);
    newhead->next = head;
    head = newhead;
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d \t", ptr->data);
        ptr = ptr->next;
    }

    // To delete the head of the linked list at the begining

    temp = head;
    head = head->next;
    printf("\nAfter deletion at the begining of the lilnked list : ");
    ptr = head;
    printf("\n");
    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }

    // Insert an elelment at the position p from the begining of the single linkedlist

    struct node *prev, *newN;
    int val;
    printf("\nEnter the value to insert node After : ");
    scanf("%d", &val);
    prev = head;
    while (prev->next != NULL && prev->data != val)
        prev = prev->next;
    if (prev->data == val)
    {
        newN = (struct node *)malloc(sizeof(struct node));
        printf("\nEnter the new data : ");
        scanf("%d", &newN->data);

        newN->next = prev->next;
        prev->next = newN;
    }
    else
    {
        printf("Value %d is not in linkedlist \n", val);
    }

    ptr = head;
    printf("\n");
    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }

    // Delete an element at the position p from the begining of the single linkedlist

    struct node *del, *previous;
    int value;
    printf("\nEnter the value to delete node After : ");
    scanf("%d", &value);
    previous = head;
    while (previous->next != NULL && previous->data != value)
        previous = previous->next;
    if (previous->data == value)
    {
        del = previous;
        previous = previous->next;
    }
    else
        printf("value %d is not in linkedlist \n", value);

    ptr = head;
    printf("\n");
    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    displaylist();

    return 0;
}