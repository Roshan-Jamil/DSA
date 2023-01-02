#include<stdio.h>
//#include <stdlib.h>
#define max 5

int stack [max];
int rear = -1 ;
int front = -1;

void push(int value)
{
    if(front == -1 && rear == -1)
    {
        front = rear = 0;
        stack [rear] = value;
    }
    else 
    {
        rear ++;
        stack [rear] = value ;
    }
}

void pop ()
{
    if (front == -1 && rear == -1)
    {
        printf("\nStack is empty : ");
    }
    else
    {
        printf("\nDeleting elelment is : %d",stack[rear]);
        rear--;
    }
}
void display()
{
    if(front == -1 && rear == -1)
    {
        printf("\nstack is empty \n");
    }
    else
    {
        int i = rear;
        for (int j = i ; j>= front ; j--)
        {
            printf("%d\t",stack[j]);
        }
    }
    
}

int main()
{
    int data;
    int choice;
    do
    {
        printf("\npress 1. push \npresss 2. pop \npress 3. display\npress 4. extit\nchoose : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 : 
            {
                printf("\nEnter the data in stack : ");
                scanf("%d",&data);
                push(data);
                break;
            }
            case 2 : 
            {
                pop();
                break;
            }
            case 3 : 
            {
                display();
                break;
            }
            case 4 : 
            {
                break;
            }
            default :
            {
                printf("\nEntered choice is invalid\n");
                break;
            }
        }
    }
    while(choice != 4);
    return 0 ;
}