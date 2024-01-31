#include<stdio.h>
int main() {
    int n,i,arr[100],pos;
    printf("Enter the number of elements in the array : ");
    scanf("%d", &n);
    printf("Enter the array elements : ");
    for(i = 0 ; i < n ; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the position of element you want to delete : ");
    scanf("%d", &pos);
    for ( i = pos - 1; i < n - 1 ; i++ ) {
        arr[i] = arr[i+1];
    }
    printf("Array elements after Deletion : ");
    for (i = 0 ; i < n - 1; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}