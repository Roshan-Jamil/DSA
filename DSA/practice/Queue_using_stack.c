#include <stdio.h>
//#include <stdlib.h>
#define max 5

int stack1[max];
int stack2[max];
int top1 = -1;
int top2 = -1;
int count = 0;

void push1(int data)
{
    if (top1 == max -1)
    {
        printf("\nOverflow ");
    }
    else
    {
        top1++;
        stack1[top1]=data;
    }
}

int pop1 ()
{
    return stack1[top1--];
}

void push2(int data)
{
    if (top2 == max -1)
    {
        printf("\nOverflow ");
    }
    else
    {
        top2++;
        stack2[top2]=data;
    }
}

int pop2 ()
{
    return stack2[top2--];
}

void enqueue(int value)
{
    push1(value);
    count ++;
}

void dequeue()
{
    if(top1 == -1 && top2 == -1)
    {
        printf("\nUnderflow\n");
    }
    else
    {
        for (int i = 0 ; i < count ; i++)
        {
            push2(pop1());
        }
        count--;
        for (int i = 0 ; i< count ; i++)
        {
            push1(pop2());
        }
    }
}

void display ()
{
    for (int i = 0 ; i <= top1 ; i++)
    {
        printf("%d\t",stack1[i]);
    }
}

int main()
{
    int data;
    int choice;
    do
    {
        printf("\npress 1. enqueue \npresss 2. dequeue \npress 3. display\npress 4. extit\nchoose : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 : 
            {
                printf("\nEnter the data in Queue : ");
                scanf("%d",&data);
                enqueue(data);
                break;
            }
            case 2 : 
            {
                dequeue();
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