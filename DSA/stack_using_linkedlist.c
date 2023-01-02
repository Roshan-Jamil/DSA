#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
} *top = NULL;

void push(int data)
{
    struct node *newnode = (struct node *) malloc (sizeof(struct node));
    if(newnode == NULL)
    {
        printf("stack overflow ");
        exit(1);
    }
    newnode -> data = data;
    newnode -> link = NULL;
    newnode -> link = top;
    
    top = newnode;
}

void display()
{
    struct node *temp;
    temp = top;
    printf("The elements are : ");
    while(temp)
    {
        printf("%d\t",temp -> data);
        temp = temp-> link;
    }
    printf("\n");
}

int main()
{
    int choice , data ;
    while(1)
    {
        printf("\n1. push");
        printf("\n2. print");
        printf("\n3. exit\n");
        printf("Enter the choice [1/2/3] : ");
        scanf("%d",&choice);

        switch (choice)
        {
            case 1 :
            
                scanf("%d", &data);
                push(data);
                break;
            
            case 2:
            
                display();
                break;
            
            case 3 :
            
                exit(1);
            

            default :
                printf("Enter a valid choice : ");
                break;
            

            
        }
    }
    return 0;
}