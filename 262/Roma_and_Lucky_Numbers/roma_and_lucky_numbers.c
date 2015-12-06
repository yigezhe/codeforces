/*interface*/
#include<stdio.h>
/*interface implementation*/
int lucky(int a) {
    int counter=0;
    while(a>0) {
        if(a%10==4 || a%10==7) counter++;
        a=a/10;
    }
    return counter;
}
/*client*/
int main() {
    int n,k;
    scanf("%d%d",&n,&k);
    int i;
    int counter=0;
    for(i=0; i<n; i++) {
        int a;
        scanf("%d",&a);
        if(lucky(a)<=k) counter++;
    }
    printf("%d\n",counter);
    return 0;
}
