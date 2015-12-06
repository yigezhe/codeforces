#include<stdio.h>
#define MAX 200
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    char chess[MAX][MAX];
    int i,j;
    for(i=0; i<n; i++) {
        scanf("%s",chess[i]);
    }
    for(i=0; i<n; i++) {
        for(j=0; j<m; j++) {
            printf("%c",chess[i][j]);
        }
        printf("\n");
    }

    return 0;
}
