/*interface*/
#include<stdio.h>
/*interface implementation*/
/*client*/
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    int i=1;
    while(1) {
        if(i==n+1) i=1;
        if(m>=i) {
            m=m-i;
            i++;
        } else {
            printf("%d\n",m);
            break;
        }
    }
    return 0;
}
