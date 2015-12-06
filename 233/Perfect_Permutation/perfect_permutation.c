//adores尊敬！
//探索的结论是：n是偶数时，总有解。
//n是奇数时没有解！
/*interface*/
#include<stdio.h>
#define N 100+1
/*interface implementation*/
/*client*/
int main() {
    int n;
    scanf("%d",&n);
    if(n%2==1) {
        printf("-1\n");
    } else {
        int p[N];
        int i;
        for(i=0; i<n; i++) {
            p[i]=i+1;
        }
        for(i=0; i<n; i+=2) {
            int tmp=p[i];
            p[i]=p[i+1];
            p[i+1]=tmp;
        }
        for(i=0; i<n; i++) {
            printf(" %d",p[i]);
        }
        printf("\n");
    }
    return 0;
}
