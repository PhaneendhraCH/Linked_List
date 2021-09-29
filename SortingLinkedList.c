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

void sort_asc(){
    
    struct node *node_first,*node_second,*non_repeat;
    int hold_val;
    
    for(node_first=head;node_first!=NULL;node_first=node_first->link){
        
        for (node_second=node_first->link;node_second!=NULL;node_second=node_second->link){
            
            if (node_second->data < node_first->data){
                
                hold_val = node_first->data;
                node_first->data = node_second->data;
                node_second->data = hold_val;
            }
        }
        
    }
}

int main()
{
    insert(20);  
    insert(40);
    insert(30);
    insert(10);
    insert(5);
    printf("\nBefore Sorting: ");
    display();
    printf("\nAfter Sorting : ");
    sort_asc();
    display();
}
