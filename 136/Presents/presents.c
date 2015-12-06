#include<stdio.h>
#define N 100+5
int main() {
    int n;
    scanf("%d",&n);
    int i;
    // the i-th number is pi — the number of a friend who gave a gift to friend number i.
    int p2i[N];
    for(i=1; i<=n; i++) {
        scanf("%d",p2i+i);
    }
    int i2p[N];
    for(i=1; i<=n; i++) {
        i2p[p2i[i]]=i;
    }
    for(i=1; i<=n; i++) {
        printf("%d ",i2p[i]);
    }
    printf("\n");



    return 0;
}
