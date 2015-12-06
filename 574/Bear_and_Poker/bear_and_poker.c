//
/*interface*/
/*interface implementation*/
/*client*/

int gcd(int m,int n) {
    int rem;
    while(n>0) {
        rem=m%n;
        m=n;
        n=rem;
    }
    return m;
}

#include<stdio.h>
#define N 100000+1
int main() {
    //75,150,75,50
    //25*3,25*6,3*25,2*25
    //3,6,3,2
    //100 150 250
    //2*50 3*50 5*50
    int n;
    scanf("%d",&n);
    int a[N];
    int i;
    for(i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }
    int g=gcd(a[0],a[1]);
    for(i=2; i<n; i++) {
        g=gcd(g,a[i]);
    }
    for(i=0; i<n; i++) {
        a[i]=a[i]/g;
    }
    /*
    printf("g=%d\n",g);
    for(i=0; i<n; i++) {
        printf(" %d",a[i]);
    }
    printf("\n");
    */

    int equal=1;
    for(i=0; i<n; i++) {
        while(a[i]%2==0) {
            a[i]=a[i]/2;
        }
        while(a[i]%3==0) {
            a[i]=a[i]/3;
        }
	//去除2，3后应该全部是1
        if(a[i]!=1) {
            equal=0;
            break;
        }
    }
    if(equal==1) {
	    printf("Yes\n");
    }else {
	    printf("No\n");
    }
    return 0;
}
