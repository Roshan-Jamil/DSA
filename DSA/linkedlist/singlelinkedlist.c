#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *next;
};

int count = 0 ;

struct node *head = NULL;
struct node *ptr = NULL;

void create(int n)
{
    for (int i = 0 ; i<n ; i++)
    {
        if (i == 0)
        {
            head = (struct node *) malloc (sizeof(struct node));
            ptr = head;
        }
        else
        {
            ptr -> next = (struct node *) malloc (sizeof(struct node));
            ptr = ptr -> next;
        }
        scanf("%d",&ptr -> data);
        count++;
    }
    ptr -> next = NULL;
    ptr = head;
}

void display()
{
    ptr = head;
    while(ptr != NULL)
    {
        printf("%d\t",ptr->data);
        ptr = ptr -> next ;
    }
}

// Insert newnode at the bigining of the linkedlist

void insertnode()
{
    struct node *newnode = NULL;
    newnode = (struct node *) malloc (sizeof(struct node));
    printf("\nEnter the newnode at the begining of the linlkedlist : ");
    scanf("%d",&newnode -> data);
    ptr = head;
    newnode -> next = head;
    head = newnode;
}

// Delete node at the begining of the linkelist

void deletenode()
{
    printf("\nAfter deleting node at the begining of the linkelist\n");
    ptr = head;
    head = head ->next;
    free (ptr);
}

// Delete at the end of the linkelist

void deletenode1()
{
    struct node *temp = NULL;
    struct node  *prev  = NULL;
    printf("\nDeleting at the end of the linkedlist\n");
    temp = head;
    while(temp -> next != NULL)
    {
        prev = temp;
        temp = temp -> next ;
    }
    prev -> next = NULL;
    free (temp);
    ptr = head;
    while(ptr != NULL)
    {
        printf("%d\t",ptr ->data);
        ptr = ptr -> next;
    }
}

void insertpostion()
{
    struct node *newnode = NULL;
    struct node *temp = NULL;
    int pos , i = 1;
    printf("\nEnter the postion to insert an element : ");
    scanf("%d",&pos);
    if(pos>count)
    {
        printf("\nPostion is invalid\n");
    }
    else
    {
        temp = head;
        while (i<pos)
        {
            temp = temp -> next;
            i++;
        }
        newnode = (struct node *) malloc (sizeof(struct node));
        printf("Enter the data : ");
        scanf("%d",&newnode -> data);
        newnode -> next = temp -> next ;
        temp -> next = newnode;
    }

}
void insertend()
{
    struct node *newnode = NULL;
    struct node *temp = NULL;
    ptr = head ;
    while(ptr != NULL)
    {
        temp = ptr;
        ptr = ptr -> next;
    }
    newnode = (struct node *) malloc (sizeof(struct node));
    printf("\nEnter the data for end of the linlkedlist : ");
    scanf("%d",&newnode -> data);
    temp -> next = newnode ;
    newnode -> next = NULL;
}

int main()
{
    int n;
    printf("Enter the number of nodes required : ");
    scanf("%d",&n);
    printf("Enter elelments in linked list : ");
    create(n);
    display();
    insertnode();
    display();
    deletenode();
    display();
    //deletenode1();
    //insertpostion();
    insertend();
    display();
}