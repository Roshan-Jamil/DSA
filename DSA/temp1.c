#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
void createlist()
{
    int n;
    struct node *ptr = NULL;
    struct node *head = NULL;
    printf("Enter the number of nodes required for linkedlist : ");
    scanf("%d", &n);
    printf("Enter the elements for linkedlist : ");
    
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

    int i , pos , nodes = 0 ;
    struct node  *prev = NULL;
    struct node *newnode = NULL;

    ptr = head;
    while (ptr != NULL)
    {
        nodes++;
        ptr = ptr -> next;
    }
    printf("\nEnter the postion for newnode : ");
    scanf("%d",&pos);

    if (pos>nodes)
    {
        printf("Please enter valid postion");
    }

    newnode = (struct node *) malloc (sizeof (struct node));
    printf("Enter the data of new element : ");
    scanf("%d",&newnode->data);

    if(pos == 1)
    {
        newnode ->next = head;
        head = head;
    }
    i=1;
    ptr = head;
    while(i<pos)
    {
        i++;
        prev = ptr;
        ptr = ptr->next;
    }
    newnode ->next = ptr;
    prev->next = newnode;

    ptr = head;
    while (ptr != NULL)
    {
        printf("%d\t",ptr->data);
        ptr = ptr->next;
    }

}
 
int main()
{
    createlist();
}