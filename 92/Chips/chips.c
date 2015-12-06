/*interface*/
#include<stdio.h>
/*interface implementation*/
int sum(int n) {
    return n*(n+1)/2;
}
/*client*/
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    m=m%sum(n);
    int i;
    for(i=1; i<=n; i++) {
        if(m<sum(i)) {
            printf("%d\n",m-sum(i-1));
            break;
        }
    }
    return 0;
}
