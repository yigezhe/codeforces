#include<stdio.h>
#define N 100000+5
int main() {
    int k,l,m,n,d;
    scanf("%d%d%d%d%d",&k,&l,&m,&n,&d);
    int damage[N];
    int i;
    for(i=0; i<N; i++) {
        damage[i]=0;
    }
    for(i=1; i<=d; i++) {
        if(i%k==0) {
            damage[i]=1;
        }
        if(i%l==0) {
            damage[i]=1;
        }
        if(i%m==0) {
            damage[i]=1;
        }
        if(i%n==0) {
            damage[i]=1;
        }
    }
    int count=0;
    for(i=1; i<=d; i++) {
        if(damage[i]==1) {
            count++;
        }
    }
    printf("%d\n",count);
    return 0;
}
