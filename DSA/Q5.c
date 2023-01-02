#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void linkedlist()
{
    int n;
    struct node *head, *ptr, *newhead;
    printf("Enter the number of nodes required in for linkedlist : ");
    scanf("%d", &n);
    printf("Enter the elelments in linked list : ");

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

    newhead= (struct node*) malloc (sizeof(struct node));
    printf("\nEnter the element for newhead of the linkedlist : ");
    scanf("%d",&newhead->data);
    newhead->next=head;
    head=newhead;
    ptr=head;
    while(ptr!=NULL)
    {
        printf("%d\t",ptr->data);
        ptr=ptr->next;
    }
    
}

int main()
{
    linkedlist();

    return 0;
}