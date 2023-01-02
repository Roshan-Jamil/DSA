#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
void createlist()
{
    struct node *head = NULL ;
    struct node *ptr = NULL ;
    struct node *temp =head ;
    struct node *prev = NULL;
    int n;
    printf("Enter the number of nodes required for linkedlist : ");
    scanf("%d",&n);
    printf("Enter the data in nodes : ");
    
    for (int i = 0 ; i < n ; i++)
    {
        if(i == 0)
        {
            head = (struct node*) malloc (sizeof(struct node));
            ptr = head;
        }
        else
        {
            ptr->next = (struct node*) malloc (sizeof(struct node));
            ptr = ptr ->next;
        }
        scanf("%d",&ptr->data);
    }
    
    ptr->next = NULL;
    
    ptr = head;
    
    while(ptr != NULL)
    {
        printf("%d\t",ptr->data);
        ptr = ptr -> next;
    }
    
    ptr= head;
    //for deleting ending node
    temp = head;
    while(temp->next != NULL)
    {
        prev = temp;
        temp = temp -> next;
    }
    printf("\nData of the deleted node : %d",temp->data);
    prev->next  = temp ->next;
    printf("\nAfter deleting node from end of the linkedlist : \n");
    
    ptr = head;
    while (ptr!= NULL)
    {
        printf("%d\t",ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    createlist();
    return 0;
}