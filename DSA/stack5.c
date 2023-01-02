#include<stdio.h>
#include<stdlib.h>
#define max 5

int top = -1;
int stack [max];

void push(int data)
{
    int i;
    top++;
    if(top == max-1)
    {
        printf("stack is overflow \n");
    }
    else
    {
        for(i=top ; i>0 ; i--)
        {
            stack[i] = stack [i-1];
        }
        stack[0] = data;
    }
}

void display()
{
    int i;
    if(top == -1)
    {
        printf("stack is underflow ");
    }
    else
    {
        for(i = 0 ; i <= top ; i++)
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
    display();
}