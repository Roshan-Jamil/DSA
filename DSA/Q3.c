#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * next;
    //struct Node * pre;
};
void linkedlist1(struct Node *ptr){
    while(ptr != NULL){
    printf("Element : %d\n",ptr->data);
    ptr= ptr-> next;
    }
}

// void linkedlist2(struct Node *ptr){
//     while(ptr!=NULL)
//     printf("Element : %d",ptr);
//     ptr= ptr-> pre;

//}

int main()
{
    struct Node *head;
    struct Node *second;    
    struct Node *third;    
    struct Node *fourth;    
    struct Node *fifth;

    head = (struct Node*) malloc (sizeof(struct Node));
    second = (struct Node*) malloc (sizeof(struct Node));
    third = (struct Node*) malloc (sizeof(struct Node));
    fourth = (struct Node*) malloc (sizeof(struct Node));
    fifth = (struct Node*) malloc (sizeof(struct Node));

    head-> data = 84;
    head-> next = second;
    //head-> pre = NULL;

    second -> data= 34;
    second -> next = third;
    //second -> pre = fourth;

    third ->data = 9;
    third -> next = fourth;
   // third -> pre= third;
    
    fourth -> data = 3;
    fourth -> next = fifth;
    //fourth -> pre= second;

    fifth -> data = 4;
    fifth-> next = NULL;
   // fifth-> pre = head;

    linkedlist1(head);

    return 0;
}