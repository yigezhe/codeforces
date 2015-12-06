/*interface*/
#include<stdio.h>
#define N 300
/*interface implementation*/
/*client*/
int main() {
    int p,n;
    scanf("%d%d",&p,&n);
    int x[N];
    int happen[N+1];
    int i;
    for(i=0; i<=N; i++) {
        happen[i]=0;
    }
    for(i=0; i<n; i++) {
        scanf("%d",&x[i]);
    }
    /*
    for(i=0; i<n; i++) {
        printf(" %d",x[i]);
    }
    printf("\n");
    */

    int find=0;
    for(i=1; i<=n; i++) {
        int h=x[i-1]%p;//这里的减一是必须的！我的for循环是从1开始
	//但是数组元素是从零开始！
        if(happen[h]==0) {
            happen[h]=1;
        } else {
            printf("%d\n",i);
            find=1;
            break;
        }
    }
    if(!find) printf("-1\n");
    return 0;
}
