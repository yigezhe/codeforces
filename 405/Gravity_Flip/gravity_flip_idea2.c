//这个问题很有物理创意！
//submit ok!
/*interface*/
/*interface implementation*/
/*client*/
#include<stdio.h>
#define N 100
int main() {
    int n;
    scanf("%d",&n);
    int i,j;
    int a[N][N];
    int b[N][N];
    for(i=0; i<N; i++) {
        for(j=0; j<N; j++) {
            a[i][j]=0;
            b[i][j]=0;
        }
    }
    int max_high=0;
    for(i=0; i<n; i++) {
        int high;
        scanf("%d",&high);
        if(high>max_high) max_high=high;
        for(j=0; j<high; j++) {
            a[i][j]=1;
        }
    }
    /*
    for(i=0; i<n; i++) {
        for(j=0; j<max_high; j++) {
            if(a[i][j]==1)printf("#");
            else printf(" ");
        }
        printf("\n");
    }
    */

    /* #
     * ## #
     * ####*/
    //接下来统计每一行有多少个元素！
    int bn[N];
    for(i=0; i<N; i++) {
        bn[i]=0;
    }
    for(i=0; i<max_high; i++) {
        for(j=0; j<n; j++) {
            if(a[j][i]==1) bn[i]++;
        }
    }

    /*
    for(i=0; i<max_high; i++) {
        printf(" %d",bn[i]);
    }
    printf("\n");
    */

    for(i=0; i<max_high; i++) {
        int high=bn[i];
        for(j=n-1; j>=n-high; j--) {
            b[j][i]=1;
        }
    }
    /*
    for(i=0; i<n; i++) {
        for(j=0; j<max_high; j++) {
            if(b[i][j]==1)printf("#");
            else printf(" ");
        }
        printf("\n");
    }
    for(i=0; i<n; i++) {
        int high=0;
        for(j=0; j<max_high; j++) {
            if(b[i][j]==1)high++;
        }
        printf(" %d",high);
    }
    printf("\n");
    */
    for(i=0; i<n; i++) {
        int high=0;
        for(j=0; j<max_high; j++) {
            if(b[i][j]==1)high++;
        }
        if(i==0)
		printf("%d",high);
	else
		printf(" %d",high);
    }
    printf("\n");



    return 0;
}
