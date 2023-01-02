#include <stdio.h>
#include <stdlib.h>
#define max 5

int stack1[max];
int stack2[max];
int top1 = -1;
int top2 = -1;
int count = 0;

void push1(int data)
{
    if (top1 == max - 1)
    {
        printf("Overflow\n");
    }
    else
    {
        stack1[++top1] = data;
    }
}

int pop1()
{
    return (stack1[top1--]);
}

void push2(int data)
{
    if (top2 == max - 1)
    {
        printf("Overflow\n");
    }
    else
    {
        stack1[++top2] = data;
    }
}

int pop2()
{
    return (stack2[top2--]);
}

void enqueue(int value)
{
    push1(value);
    count++;
}

void dequeue()
{
    int a, b, i;
    if (top1 == -1 && top2 == -1)
    {
        printf("Queue is underflow\n");
    }
    else
    {
        for (i = 0; i < count; i++)
        {
            push2(pop1());
        }
        b = pop2();
        printf("Deleting element is %d\n", b);
        count--;
        for (i = 0; i < count; i++)
        {
            push1(pop2());
        }
    }
}

void display()
{

    for (int i = 0; i <= top1; i++)
    {
        printf("%d\n", stack1[i]);
    }
}

int main()
{
    enqueue(5);
    enqueue(4);
    enqueue(3);
    enqueue(2);
    enqueue(1);
    display();
    dequeue();
    display();
}