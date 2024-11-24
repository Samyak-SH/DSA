#include "stdio.h"


void DFS(int n, int a[10][10], int source, int s[10]){
    printf("%d ", source);
    s[source]=1;//set node as visited
    for(int i=1; i<=n; i++){
        //traverse through node if its not visited (s[i]==0) and has connection with adjacent node (a[source][i]==1)
        if(s[i]==0 && a[source][i]==1){
            DFS(n, a, i, s);//send the adjacent node as source
        }
    }
}
int main()
{   
    int n, a[10][10],s[10], source;
    printf("Enter number of nodes : ");
    scanf("%d", &n);

    printf("Enter adjacent matrix : \n");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n; j++){
            scanf("%d", &a[i][j]);
        }
    }

    for(int i = 1;i<=n;i++){
        s[i]=0;
    }
    printf("Enter source : ");
    scanf("%d", &source);
    printf("DFS results : \n");
    DFS(n, a, source, s);   

}

