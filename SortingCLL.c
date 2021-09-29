#include <stdio.h>
#include <stdlib.h>

//Circular Linked List

struct node {
    int data;    // value which each node holds
    struct node *link;  // self referential struct
}*head;

struct node *currentnode;

void insert(int num){
    
    struct node *newnode = malloc(sizeof(struct node));  // new node
    newnode->data = num;                                // newnode ->data = num
    
    if (head==NULL){
        head = newnode;
        currentnode = newnode;
    }
    else{
        
        currentnode->link = newnode;  //currentnode address of first node , firstnode->link = newnode, currentnode = newnode,
        currentnode = newnode;
        newnode->link = head; // newnode->link = head. 
        }
}

void display(){
    struct node *temp;
    temp = head;
    while(temp!=NULL){
        
        printf("%d  \n",temp->data);
        temp = temp->link;
        
        if (temp==head)
            break;
    }
}

void sort_asc(){
    
    struct node *node_first,*node_second;
    int hold_val;
    
    for(node_first=head;node_first->link!=head;node_first=node_first->link){
        
            
        for (node_second=node_first->link;node_second!=head;node_second=node_second->link){
            
            if (node_second->data < node_first->data){
                
                hold_val = node_first->data;
                node_first->data = node_second->data;
                node_second->data = hold_val;
            }
        }
    }
}

int main() {
    
    insert(20);  
    insert(40);
    insert(30);
    insert(10);
    insert(5); 
    printf("Before Sorting: \n");
    display();
    printf("After sorting: \n ");
    sort_asc();
    display();
    
}