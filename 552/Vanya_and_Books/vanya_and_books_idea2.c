/*interface*/
/*interface implementation*/
/*client*/
int sum_to_n(int n) {
    return n*(n+1)/2;
}
int digit_n(int n) {
    int digits=0;
    while(n>0) {
        digits++;
        n=n/10;
    }
    return digits;
}

#include<stdio.h>
int main() {
    int n;
    scanf("%d",&n);
    int i;
    int all_digits=0;
    for(i=1;i<=n;i++) {
	    all_digits+=digit_n(i);
    }
printf("%d\n",all_digits);
    return 0;
}
