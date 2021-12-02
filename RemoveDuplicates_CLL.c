/*
	Remove Duplicates in a Circular Linked List 
	
	Author : Phaneendhra
*/



#include <stdio.h>
#include <stdlib.h>

struct node{
    
    int data;
    struct node *link;
    
}*head,*currentnode;


void remove_duplicate()
{
   struct node *current = head;
   
   struct node *next;
   
   while (current){
       
       next = current;
       
       while(next->link!=current){
         
             
           if (current->data == next->link->data)
           {
               next->link = next->link->link;
           }
           else{
           next = next->link;
           }
       
       }
       
       current = current->link;
       if (current == head)
            break;
   }
   return;
}


void insert(int number){
    struct  node *newnode;
    newnode = malloc(sizeof(struct node));
    newnode->data = number;
    newnode->link = NULL;
    
    if (head==NULL){
    head = newnode;
    currentnode = newnode;
    }
    else{
    
        currentnode->link = newnode;
        currentnode = newnode;
        newnode->link = head;
        
    }
}

void display()
{
    struct node *disp;
    disp = head;
    while (disp!=NULL){

        printf("%d\t",disp->data);
        disp = disp->link;
        if (disp==head)
        	break;
    }
}

int main()
{
    
insert(10);
insert(20);
insert(30);
insert(40);

insert(20);             // duplicate node
insert(30);             // duplicate node
insert(40);             // duplicate node


remove_duplicate();     // remove duplicates in Circular Linked List

display();
}