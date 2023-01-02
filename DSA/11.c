#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
void create(int n)
{
    struct node *ptr = NULL;
    struct node *head = NULL;
    for (int i = 0 ; i<n ; i++)
    {
        if (i == 0)
        {
            head = (struct node*) malloc (sizeof(struct node));
            ptr = head;
        }
        else
        {
            ptr -> next = (struct node*) malloc (sizeof(struct node));
            ptr = ptr->next;
        }
        scanf("%d",&ptr ->data);
    }
    ptr ->next = NULL;
    ptr = head;
}

void display()
{
    struct node *ptr , *head;
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d\t", ptr ->data);
        ptr = ptr -> next;
    }
}
void insert()
{
    struct node *ptr , *head;
    struct node *newhead = NULL;
    ptr = head;
    printf("\nEnter the new element for begining of the linkedlist : ");
    newhead = (struct node*) malloc (sizeof(struct node));
    scanf("%d",&newhead ->data);
    newhead ->next = head;
    head = newhead;
    ptr = head;

}
void delete()
{
    struct node *ptr , *head;
    struct node *temp = NULL;
    ptr = head;
    printf("\nDeleting element at the begining of the linkedlist : \n");
    temp = head;
    head = head->next;
    ptr = head;
}
void del()
{
    struct node *ptr , *head;
    struct node *temp = head;
    ptr = head;
    printf("\nList after deleting the element at the end of the linlkedlist : ");
    while(ptr!= NULL)
    {
        if(ptr == NULL)
        {
            
            temp = ptr;
            free(temp);
            ptr = head;

        }
        
    }
}

int main()
{
    int num;
    printf("Enter the number of nodes : ");
    scanf("%d",&num);
    printf("Enter the elements of linkedlist : ");
    create(num);
    display();
    insert();
    display();
    delete();
    display();
    del();
    display();
}