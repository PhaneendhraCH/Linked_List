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
        
    }
}

void reverse(){
    struct node *current,*next,*prev;
    prev = NULL;
    current = head;
    
    while (current!=NULL){
        next = current->link;   // next = 10->link
        current->link = prev;   // 10->link = null
        prev = current;         // prev = add of current
        current = next;         // current = address of next
    }
    head = prev;
    
}

void display()
{
    struct node *disp;
    disp = head;
    while (disp!=NULL){
        printf("%d\t",disp->data);
        disp = disp->link;
    }
    //printf("Last node is : %d\n",disp->data);
}


int main()
{
insert(10);
insert(20);
insert(30);
insert(40);
insert(50);
insert(60);
printf("Initial List : ");
display();
printf("\n");
printf("Reverse List : ");
reverse();
display();

}
