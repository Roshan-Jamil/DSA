#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;
void createlist(int n)
{
    struct node *ptr = NULL;
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
}

void display()
{
    struct node *ptr;
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d\t",ptr->data);
        ptr = ptr->next;
    }
    
}
void delete_end()
{
    //printf("\n1\n");
    struct node  *ptr ;
    struct node *temp = head ;
    //struct node *prev;
 
    //printf("\n2\n");
    while(temp->next!= NULL)
    {
        //printf("\n3\n");
        ptr=temp;
        temp = temp -> next;
        //printf("\n4\n");
    }
    //printf("\n5\n");

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
        return 0;
}
