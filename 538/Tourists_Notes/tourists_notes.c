#include<stdio.h>
//#define N 100000000+5
#define N 100+5
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    int i,j;
    int high[N];
    for(i=0; i<N; i++) {
        high[i]=-1;
    }
    for(i=0; i<m; i++) {
        int d,h;
        scanf("%d%d",&d,&h);
        if(high[d]==-1)
            high[d]=h;
        else if(h>high[d]) {
            printf("IMPOSSIBLE\n");
            return 0;
        }else {
            high[d]=h;
	}
        //向左边上升！

    for(j=1; j<=n; j++) { printf("%d",high[j]); } printf("\n");
        for(j=d-1; j>=1; j--) {
            if(high[j]==-1)
                high[j]=high[j+1]+1;
            //小的话，可以留下！
            //大的话，就不要更新，立刻中断！
            else if(high[j+1]+1<high[j]) {
                high[j]=high[j+1]+1;
            } else {
                break;
            }
        }

    for(j=1; j<=n; j++) { printf("%d",high[j]); } printf("\n");
        //向右上升！
        for(j=d+1; j<=n; j++) {
            //if(high[j]==-1)// 向右上升可以什么都不用管！
                high[j]=high[j-1]+1;
        }

    for(j=1; j<=n; j++) { printf("%d",high[j]); } printf("\n");
    printf("\n");
    }
    int max=0;
    for(i=1; i<=n; i++) {
        printf("%d",high[i]);
        if(high[i]>max) max=high[i];
    }
    printf("\n");
    printf("%d\n",max);

    return 0;
}
