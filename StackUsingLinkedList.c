/*
    Implement stack using linked list

*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    
    int data;
    struct node *link;
    
}*head;

void insert(int num){
    
    struct node *temp = malloc(sizeof(struct node));
    temp->data = num;
    
    if (head == NULL){
        head = temp;
        return;
    }
    
    temp->link = head;
    head = temp;
    return;
}

void pop(){
    
    struct node *temp;
    temp = head;
    head = head->link;
    free(temp);
    return;
}

void display(){
    struct node *temp;
    temp = head;
    
    while(temp){
        printf("%d ",temp->data);
        temp = temp->link;
    }
}

void IsEmpty(){
    if (head == NULL)
        printf("Yes, Stack in Empty\n");

    printf("No, Stack is not Empty\n");
    return;
}

void peek(){
    if (head == NULL){
        printf("Stack is Empty\n");
        return;
    }
    
    printf("Top element in stack : %d\n",head->data);
    return;
}

int main()
{
    insert(10);         // push num into stack 
    insert(20);
    insert(30);
    insert(40);
    insert(50);
    pop();              // pop element from stack
    display();
    peek();             // print top element from stack
    IsEmpty();          // Check is stack empty or not
    
    return 0;
}
