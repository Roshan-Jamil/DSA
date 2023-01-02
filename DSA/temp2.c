#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void createlist()
{
    int n;
    struct node *head = NULL;
    struct node *ptr = NULL;
    struct node *temp = NULL;
    
    printf("Enter the no. of nodes for linkedlist : ");
    scanf("%d", &n);
    printf("Enter the elements in linkedlist : ");
    for (int i = 0 ; i<n ; i++)
    {
        if(i == 0)
        {
            head = (struct node*) malloc (sizeof(struct node));
            ptr = head;
        }
        else
        {
            ptr->next = (struct node *) malloc (sizeof(struct node));
            ptr = ptr -> next;
        }
        scanf("%d",&ptr ->data);
    }
    ptr -> next = NULL;
    ptr = head;
    
    if(head == NULL)
    {
        printf("\nList is empety \n");
    }
    else
    {
        while(ptr != NULL)
        {
            printf("%d\t", ptr ->data);
            ptr = ptr -> next;
        }
    }
    
    temp = head;
    head = head -> next;
    
    printf("\nAfter deletion at the begining of the lilnked list : \n");
    ptr = head;
    if (head == NULL)
    {
        printf("Nothing to delete");
    }
    else 
    {
        ptr = head;
        while (ptr != NULL)
        {
            printf("%d\t",ptr->data);
            ptr = ptr->next;
        }
    }
    
}

int main()
{
    createlist();
}