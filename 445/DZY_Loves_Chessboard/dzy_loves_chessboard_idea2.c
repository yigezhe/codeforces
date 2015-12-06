//另一个思路是，全部先bw间隔放好，之后把－添加进去！
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
    char chess2[MAX][MAX];
    for(i=0; i<n; i++) {
        for(j=0; j<m; j++) {
                if((i+j) % 2 == 0 ) {
                    chess2[i][j]='B';
                } else {
                    chess2[i][j]='W';
                }
        }
    }
    /*
    for(i=0; i<n; i++) {
        for(j=0; j<m; j++) {
            printf("%c",chess2[i][j]);
        }
        printf("\n");
    }
    */

    for(i=0; i<n; i++) {
        for(j=0; j<m; j++) {
            if (chess[i][j]=='-') {
                chess2[i][j]='-';
            }
        }
    }

    for(i=0; i<n; i++) {
        for(j=0; j<m; j++) {
            printf("%c",chess2[i][j]);
        }
        printf("\n");
    }

    return 0;
}
