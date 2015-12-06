
/*interface*/
#include<stdio.h>
#define N 100000
/*interface implementation*/
/*client*/
int main() {
    int n;
    scanf("%d",&n);
    int i;
    int a[N],p[N];
    for(i=0; i<n; i++) {
        scanf("%d%d",&a[i],&p[i]);
    }
    i=0;
    int money=0;
    while(i<n) {
        int buy=a[i];
        int j=i+1;
        while(j<n && p[j]>=p[i]) {
            buy+=a[j];
            j++;
        }
        money+=buy*p[i];
        i=j;
    }
    printf("%d\n",money);
    return 0;
}
