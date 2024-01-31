#include<stdio.h>
#include<stdlib.h>


void dfs(int start,int n,int a[n][n],int v[]){
    if(v[start]!=1){
        printf("%d ",start);
        v[start]=1;
        for(int i=0;i<n;i++){
            if(a[start][i]==1 && v[i]==0){
                dfs(i,n,a,v);
            }
        }
    }
}

void main(){
    int n,start;
    printf("Enter the number of nodes : ");
    scanf("%d",&n);
    int a[n][n],v[n];
    printf("Enter the adjaceny matrix \n");
    for(int i=0;i<n;i++){
        v[i]=0;
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    printf("Enter the starting node (0-%d) : ",(n-1));
    scanf("%d",&start);
    printf("DFS Traversal is : ");
    dfs(start,n,a,v);
}


// 0 1 1 1 0
// 1 0 1 0 0
// 1 1 0 0 1
// 1 0 0 0 0
// 0 0 1 0 0

//output = 0 1 2 4 3
