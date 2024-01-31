#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head=NULL;
struct node *temp;

int size=0;

struct node *addnode(){
    struct node *newnode =(struct node *)malloc(sizeof(struct node));
    printf("Enter the data : ");
    scanf("%d",&newnode->data);
    newnode->prev=NULL;
    newnode->next=NULL;
    return newnode;
    
}

void insert_beg(){
    struct node *newnode=addnode();
    if(head==NULL){
        head=newnode;
    }else{
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
    }
    size++;
}

void insert_end(){
    struct node *newnode=addnode();
    if(head==NULL){
        head=newnode;
    }else{
        temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->prev=temp;
    }
    size++;
}

void insert_pos(){
    int pos;
    printf("Enter the position : ");
    scanf("%d",&pos);
    if(pos<0 || pos>size+1){
        printf("\nInvalid position");
    }else{
        struct node *newnode=addnode();
        if(pos==1){
            newnode->next=head;
            head->prev=newnode;
            head=newnode;
        }else{
            int i=1;
            struct node *demo;
            temp=head;
            while(i<pos-1){
                temp=temp->next;
                i++;
            }
            demo=temp->next;
            newnode->next=demo;
            newnode->prev=temp;
            temp->next=newnode;
            demo->prev=newnode;

        }
    }
    size++;
}


void display(){
    if(head==NULL){
        printf("Empty linked list");
    }else{
        temp=head;
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
}

int main(){
    int ch;
    while(1){
        printf("\nEnter choice : ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                insert_beg();
                break;
            case 2:
                insert_end();
                break;
            case 3:
                insert_pos();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
        }


    }
    
    return 0;
}
