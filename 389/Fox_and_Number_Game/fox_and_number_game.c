/*interface*/
#include<stdio.h>
/*interface implementation*/
int gcd(int m,int n) {
    while(1) {
        if(n==0) {
            return m;
            break;
        }
        int tmp=m%n;
        //m,n
        //n,m%n
        m=n;
        n=tmp;

    }
}
/*client*/
int main() {
    int n;
    scanf("%d",&n);
    int i;
    int g;
    scanf("%d",&g);
    for(i=0; i<n-1; i++) {
        int x;
        scanf("%d",&x);
        g=gcd(g,x);
    }
    printf("%d\n",g*n);
    return 0;
}
