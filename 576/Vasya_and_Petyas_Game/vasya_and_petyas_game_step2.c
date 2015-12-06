/*interface*/
#include<stdio.h>
#define N 1000
/*interface implementation*/
int is_prime(int n) {
    int i;
    for(i=2; i*i<=n; i++) {
        if(n%i==0) return 0;
    }
    return 1;
}
/*client*/
int main() {
    int y[N+1];
    int i;
    for(i=0; i<=N; i++) {
        y[i]=0;
    }
    int n;
    scanf("%d",&n);
    for(i=2; i<=n; i++) {
        if(is_prime(i)) {
		//必须是素数，才可以进行下面的操作！
            y[i]=1;
            int j=i;
            while(j*i<=n) {
                y[j*i]=1;
                j=j*i;
            }
        }
    }
    int counter=0;
    for(i=0; i<=N; i++) {
        if(y[i]==1) counter++;
    }
    printf("%d\n",counter);
    for(i=0; i<=N; i++) {
        if(y[i]==1) printf(" %d",i);
    }
    printf("\n");

    /*
    if(is_prime(36)) printf("36 is prime\n");
    else printf("36 is not prime\n");
    */
    return 0;
}
