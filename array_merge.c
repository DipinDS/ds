#include <stdio.h>
int main()
{
    int n1, n2, n3, arr1[100], arr2[100], arr3[100], i, j;
    printf("Enter the no of elemnts in the first array:");
    scanf("%d", &n1);

    printf("Enter the elemts in first array:");
    for (i = 0; i < n1; i++)
    {
        scanf("%d", &arr1[i]);
    }
    printf("Enter the no of elemets in the second array:");
    scanf("%d", &n2);

    printf("Enter array elements : ");
    for (i = 0; i < n2; i++)
    {
        scanf("%d", &arr2[i]);
    }
    for (i = 0; i < n1; i++)
    {
        arr3[i] = arr1[i];
    }
    for (j = 0; j < n2; j++)
    {
        arr3[i + j] = arr2[j];
    }
    n3 = n1 + n2;
    printf("Merged Array : ");
    for (i = 0; i < n3; i++)
    {
        printf("%d ", arr3[i]);
    }
    return 0;
}