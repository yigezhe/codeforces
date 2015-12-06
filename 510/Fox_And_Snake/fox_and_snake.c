#include<stdio.h>
int main() {
    //1,3,5,7等行都是＃
    //2,4,6,8等行是第一个和最后一个可能是＃，其他都是.
    //2/2=1,最后一个是＃，其他是.
    //2/4=2,第一个是＃，其他是.
    //2/2=3,最后一个是＃，其他是.
    //2/4=4,第一个是＃，其他是.
    int n,m;
    scanf("%d%d",&n,&m);
    //整个计算中，我不从零开始，而是从1开始！
    int i,j;
    for(i=1; i<=n; i++) {
        for(j=1; j<=m; j++) {
            if(i%2==1) {
                printf("#");
            } else {
                int i2=i/2;
                if(i2%2==1) {
                    if(j==m) printf("#");
                    else printf(".");
                } else {
                    if(j==1) printf("#");
                    else printf(".");
                }
            }
        }
	printf("\n");
    }
    return 0;
}
