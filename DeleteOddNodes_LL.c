/*

Deleting nodes containing odd values

*/
#include <stdio.h>
#include <stdlib.h>

struct node{
    
    int data;
    struct node *link;
    
}*head;

     struct  node *currentnode;
    struct  node *newnode;

void insert(int number){
    
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
        //newnode->link = head;
        
    }
}

void delete_odd(){

    struct node *new_head,*tmp,*new_head1;
    
    new_head = head;
    while(new_head!=NULL){
        
        if((new_head->data)%2!=0){
            new_head = new_head->link;
        }
        else
            break;
    }

  head =  new_head;
  if (new_head == NULL){
        //printf("\nAll nodes deleted");
        return;
  }
  new_head1 = new_head;
  tmp = new_head1->link;
  
  while(tmp!=NULL){

    if ((tmp->data)%2!=0){
        new_head1->link = tmp->link;
    }
    else{
        new_head1 = new_head1->link;
    }
    tmp = tmp->link;
  }
}

void display()
{
    struct node *disp;
    disp = head;
    
    if (disp==NULL){
        printf("\nNo nodes");
        return;
    }
        
    while (disp!=NULL){

        printf("%d\t",disp->data);
        disp = disp->link;
     
    }
}

int main()
{
insert(11);
insert(21);
insert(37);
insert(35);
insert(39);
display();

delete_odd();

printf("\nAfter Deletion of Odd Nodes : ");
display();
free(head);
}