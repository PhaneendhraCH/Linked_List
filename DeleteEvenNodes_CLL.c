/*

Deleting nodes containing even values

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
        newnode->link = head;
        
    }
}

void delete_even(){

    struct node *new_head,*tmp,*new_head1;
    
    new_head = head;
    while(new_head!=NULL){
        
        if((new_head->data)%2==0){
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
      if(tmp==head)
            break;

    if ((tmp->data)%2==0){
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

        printf("%d  ",disp->data);
        disp = disp->link;
        if(disp==head)
            break;
     
    }
}

int main()
{
insert(10);
insert(21);
insert(32);
insert(35);
insert(40);
display();

delete_even();

printf("\nAfter Deletion of Even Nodes : ");
display();
free(head);
}