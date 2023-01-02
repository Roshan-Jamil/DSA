#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void createlist()
{
    struct node *head = NULL;
    struct node *ptr = NULL;
    struct node *temp = NULL;

    int n;

    printf("Enter the number of nodes required for linked list : ");
    scanf("%d", &n);
    printf("Enter the data in nodes : ");
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            head = (struct node *) malloc (sizeof(struct node));
            ptr = head;
        }
        else
        {
            ptr -> next = (struct node *) malloc (sizeof(struct node));
            ptr = ptr->next;
        }
        scanf("%d",&ptr->data);
    }
    ptr->next = NULL;

    ptr = head;
    printf("\nEntered data is : \n");
    while(ptr != NULL)
    {
        printf("%d\t",ptr->data);
        ptr = ptr -> next;
    }
    //for deleting node at the end of the linkedlist

    ptr = head;
    struct node *prev;
    temp = head;
    while (temp ->next !=NULL)
    {
        prev = temp;
        temp = temp ->next;
    }
    printf("\nValue of the deleted node = %d",temp ->data);
    prev -> next = temp ->next;
    free(temp);

    printf("\nAfter deleting at the end of the linlkedlist :\n");

    ptr = head;

    while(ptr !=NULL )
    {
        printf("%d\t", ptr->data);
        ptr = ptr -> next;
    }
}

int main()
{
    createlist();
}