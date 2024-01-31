#include<stdio.h>
int c;
int main() {
    int n,i,j;
    printf("Enter the number of Nodes : ");
    scanf("%d", &n);
    int a [n][n], v[n];
    printf("Enter the adjacency matrix : \n");
    for (i = 0 ; i < n ; i++) {
        v[i] = 0;
        for (j = 0 ; j < n ; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    printf("\n Topological Sorting : ");
    for ( i = 0 ; i < n ; i++) {
        c = 0;
        if ( v[i] == 0) {
            for ( j = 0 ; j < n ; j++) {
                if (a[j][i] != 0) {
                    c = 1;
                    break;
                }
            }
            if( c == 0) {
                v [i] = 1;
                printf("%d ==> ", i);
                for ( j = 0 ; j < n ; j++) {
                    a[i][j] = 0;
                }
                i = -1;
            }
        }
    }
}

// 5
// 0 1 0 1 0
// 0 0 1 0 1
// 0 0 0 0 0
// 0 0 1 0 1
// 0 0 0 0 0 

    


    

