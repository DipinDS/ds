#include<stdio.h>
#include<stdlib.h>
#define max 5
int rear = -1;
int front = -1;
int queue[max];
int enqueue();
int dequeue();
int display();
int main() {
    
    int choice;
    while (1) {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\nEnter Your Choice : ");
        scanf("%d", &choice);
        switch(choice) {
            case 1 :
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
            default :
                printf("Invalid syntax");
        }
    }


}

int enqueue() {
    int element;
    printf("Enter the element : ");
    scanf("%d", &element);
    if (rear == max - 1) {
        printf("Queue overflow !");
        return 0;
    }
    if (front == -1) {
        front = 0;
    }
    rear = rear + 1;
    queue[rear] = element;
}

int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue empty !");
        return 0;
    }
    int d = queue[front];
    printf("Deleted element : %d " , d);
    front = front + 1;
}

int display() {
    if ( rear == -1 && front == -1) {
        printf("Queue underflow!");
        return 0;
    } 
    for ( int i = front ; i <= rear ; i++) {
        printf("%d ", queue[i]);
    }
}
