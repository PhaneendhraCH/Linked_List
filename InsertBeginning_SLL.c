/*
	
	Insert nodes at beginning of a Single Linked List
	Author : Phaneendhra

*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    
    int data;
    struct node *link;
    
}*head;


struct node *insert_first(struct node *root,int number){
    
    struct node *new;
    new = malloc(sizeof(struct node));
    new->data = number;
    new->link=root;
    root = new;
    
    return root;
    
}

void display(struct node *root)
{
    struct node *disp;
    disp = root;
    while (disp!=NULL){
        printf("%d\t",disp->data);
        disp = disp->link;
    }
}


int main()
{
    head = insert_first(head,10);
    head = insert_first(head,25);
    head = insert_first(head,35);
    head = insert_first(head,45);
    head = insert_first(head,65);
    display(head);
    return 0;
}
