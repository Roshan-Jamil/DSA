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
void insert_node()
{
    struct node *ptr , *head;
    struct node *newhead = NULL;
    ptr = head;
    newhead = (struct node*) malloc (sizeof (struct node));
    printf("\nEnter the new element in linkedlist : ");
    scanf("%d",&newhead ->data);
    newhead->next = head;
    head = newhead;
    ptr = head;
}

void delete_end()
{
    printf("\n1\n");
    struct node *head , *ptr ;
    struct node *temp = head ;
    //struct node *prev;
 
    printf("\n2\n");
    while(temp -> next != NULL)
    {
        printf("\n3\n");
        ptr = temp;
        temp = temp -> next;
        printf("\n4\n");
    }
    printf("\n5\n");

    printf("\nData of the deleted node : %d\n",temp->data);
    ptr->next = temp->next;
    free(temp);
    ptr = head;

}

int main()
{
    int n;
    printf("Enter the number of nodes required for linkedlist : ");
    scanf("%d",&n);
    printf("Enter the elements for linkedlist : ");
    createlist(n);
    display();
    delete_end();
    display();

}
