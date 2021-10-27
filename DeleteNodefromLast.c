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

void deletefirst(){
    
    struct node *newhead,*linked;
    newhead = head;
    head = newhead->link;
    free(newhead);
}



void deletelast(){
    
     struct node *temp,*bfl;
     temp = head;
     
     while(temp!=NULL){
         bfl = temp ->link;
         if(bfl->link == NULL){
             temp->link = NULL;
             free(bfl);
             break;
         }
         else{
            temp = temp->link;   
         }
     }
}


void delete_node(int position){
    
    if (position == 1){
        deletefirst();
        return;
    }
    else if (position == count()){
        deletelast();
        return;
    }
    
    else{
        int count_node = 1;
        struct node *first,*second;
        
        first = head;
        second = first->link;
        
        while(count_node<(position-1)){
            count_node++;
            first = first->link;
            second = second->link;
        }
        first->link = second->link;
    }
    return;
    
}

void delete_n_last(int position){

    int pos = count()-position+1;   // Formula to delete nth node from last
                                    // Total Nodes - position of node from end + 1
    
    //printf("pos =  %d\n",pos);
    
    if (pos>0 && pos<=count()){
            delete_node(pos);
            printf("\nNode deleted\n");
            return;
    } 
    printf("Cannot delete the node\n");
    return;
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

int count()
{
    struct node *disp;
    int count = 0;
    disp = head;
    while (disp!=NULL){
        ++count;
        disp = disp->link;
    }
    return count;
}

int main()
{
insert(10);
insert(20);
insert(30);
insert(40);
insert(50);
insert(60);

display();
delete_n_last(2);   // Delete 2nd node from last
display();

}