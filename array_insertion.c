#include<stdio.h>
int main() {
    int n,i,arr[100],pos, value;
    printf("Enter the number of elements in the array : ");
    scanf("%d", &n);
    printf("Enter the array elements : ");
    for(i = 0 ; i < n ; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the position of element you want to insert : ");
    scanf("%d", &pos);
    printf("Enter the array element you want to insert : ");
    scanf("%d", &value);
    for ( i = n - 1; i >= pos - 1; i--) {
        arr[i + 1] = arr[i];
    }
    arr[pos - 1] = value;
    printf("Array elements after insertion : ");
    for (i = 0 ; i <= n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}