/*interface*/
#include<stdio.h>
/*interface implementation*/
int is_lucky(int n) {
    if(n<0) n=-n;
    while(n>0) {
        if(n%10==8) return 1;
        n=n/10;
    }
    return 0;
}
/*client*/
int main() {
    int a;
    scanf("%d",&a);
    int i=1;
    while(1) {
        if(is_lucky(a+i)) {
            printf("%d\n",i);
            break;
        }
        i++;
    }
    return 0;
}
