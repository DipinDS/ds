#include<stdio.h>
#include<stdlib.h>  
#define MAX_SIZE 5
int queue[MAX_SIZE];  
int front = -1;  
int rear = -1;  
void enqueue() {  
    int element;
    printf("Enter the element : ");
    scanf("%d", &element);
    if (rear == MAX_SIZE - 1) {  
        printf("Queue is full");  
        return;  
    }  
    if (front == -1) {  
        front = 0;  
    }  
    rear++;  
    queue[rear] = element;  
}  
  
int dequeue() {  
    if (front == -1 || front > rear) {  
        printf("Queue is empty");  
        return -1;  
    }  
    int element = queue[front];  
    front++;  
    printf("\nDequeued element %d ", element);
}  

int display() {
    int i;
    if(front == -1) {
        printf("empty!");
        return 0;
    }
    printf("Queue elements : ");
    for ( i = front ; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
}  

int main() {  
    int choice;
    while (1) {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\nEnter your choice : ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                enqueue();
                break;
            case 2 :
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid Syntax !");
        }
    }
}  
