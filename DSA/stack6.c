#include<stdio.h>
#include<stdlib.h>
#define max 5

int top = -1;
int stack [max];

void push (int data)
{
    int i;
    top++;
    if(top == max -1)
    {
        printf("stack is overflow ");
    }
    else
    {
        stack[top] = data;
    }
}

void pop ()
{
    if(top == -1)
    {
        printf("stack is underflow");
    }
    else
    {
        stack[0];
        for(int i = 0 ; i>top ; i++)
        {
            stack[i] = stack [i+1];
        }
        top--;
    }
}

void display()
{
    if(top == -1)
    {
        printf("stack is underflow ");
    }
    else
    {
        for(int i = top ; i>=0 ; i--)
        {
            printf("%d\n",stack[i]);
        }
    }
}

int main()
{
    push(2);
    push(4);
    push(6);
    push(8);
    pop();
    display();
}