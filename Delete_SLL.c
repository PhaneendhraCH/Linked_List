/*

	Delete Entire Single Linked List 
	
	Author : Phaneendhra
*/


#include <stdio.h>
#include <stdlib.h>

struct node{
    
    int data;
    struct node *link;
    
}*head;

struct node *insert(struct node *root,int number){
   
   if (root == NULL){
        
       struct node *newnode;
       newnode = malloc(sizeof(struct node));
       newnode->data = number;
       newnode->link = NULL;
   
       root = newnode;
       return root;
   }
   
   if (root->link!=NULL){
       return  insert(root->link,number);
   }
   else{
       
        struct node *newnode;
        newnode = malloc(sizeof(struct node));
        newnode->data = number;
        newnode->link = NULL;
        
        root->link = newnode;
       
   }
   
   //return root;
}

void delete_linkedlist(struct node **root){
     
    struct node *current = *root;
    
    struct node *next;
    
    while(current){
        next = current->link;
        free(current);
        current = next;
    }
  *root = NULL;
 
   printf("\nLinked List Destroyed\n");
}

void display()
{
    struct node *disp;
    disp = head;
    while (disp!=NULL){
        printf("%d\t",disp->data);
        disp = disp->link;
    }
}

int main()
{
head = insert(head,10);
insert(head,20);
insert(head,30);
insert(head,40);
insert(head,20);

display();

delete_linkedlist(&head);
display();
}