/*interface*/
#include<stdio.h>
#define N 20000
/*interface implementation*/
/*client*/
int main() {
    int n;
    scanf("%d",&n);
    int i;
    int t[N];
    for(i=0; i<n; i++) {
        scanf("%d",&t[i]);
    }
    int res=0;
    for(i=0; i<n; i++) {
        res += t[i];
    }
    printf("res=%d\n",res);
    int nn=n;
    int add=1;
    while(nn>4 && nn%2==0) {
        add*=2;
        int a;
        for(a=1; a<=add; a++) {
            int sum=0;
            for(i=a; i<n; i+=add) {
                sum+=t[i-1];
            }
	    printf("sum=%d\n",sum);
            if(sum>res) res=sum;
        }
        nn=nn/2;
    }
    printf("%d\n",res);

    return 0;
}
