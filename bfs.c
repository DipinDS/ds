#include<stdio.h>
int rear = -1;
int front = -1;
#define max 10
int array[max];
int enqueue(int value) {
    if (rear == max - 1) {
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear ++;
    array[rear] = value;
}

int dequeue() {
    if(front == -1) {
        return -1;
    }
    int v = array[front];
    front++;
    return v;
}
int main() {
    int n,i,j, start;
    printf("Enter the number of nodes : ");
    scanf("%d", &n);
    int a[n][n], v[n];
    printf("Enter the adjacency matrix : ");
    for ( i = 0 ; i < n ; i++) {
        v[i] = 0;
        for ( j = 0 ; j < n ; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    printf("Enter the starting node : ");
    scanf("%d", &start);
    enqueue(start);
    v[start] = 1;
    while (front <= rear) {
        start = dequeue();
        printf("%d ", start);
        for(i = 0; i < n ; i++) {
            if(a[start][i] == 1 && v[i] == 0) {
                enqueue(i);
                v[i] = 1;
            }
        }
    }
}

// output

// 0 1 1 1 0 
// 1 0 1 0 0
// 1 1 0 0 1  
// 1 0 0 0 0
// 0 0 1 0 0