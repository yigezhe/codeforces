#include<stdio.h>
#define N 100+1
int main() {
    int n,p,q;
    scanf("%d",&n);
    scanf("%d",&p);

    int level[N];
    int i;
    for(i=0; i<N; i++) {
        level[i]=0;
    }
    for(i=0; i<p; i++) {
        int a;
        scanf("%d",&a);
        level[a]=1;
    }
    scanf("%d",&q);
    for(i=0; i<q; i++) {
        int a;
        scanf("%d",&a);
        level[a]=1;
    }
    for(i=1; i<=n; i++) {
        if(level[i]==0) {
            printf("Oh, my keyboard!\n");
            return 0;
        }
    }
    printf("I become the guy.\n");
    return 0;
}
