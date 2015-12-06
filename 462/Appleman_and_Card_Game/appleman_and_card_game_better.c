/*interface*/
#include<stdio.h>
#define N 256
/*interface implementation*/
/*client*/
int main() {
    int n,k;
    scanf("%d%d",&n,&k);
    int i;
    getchar();
    int times[N];
    for(i=0; i<N; i++) {
        times[i]=0;
    }
    for(i=0; i<n; i++) {
        char card=getchar();
        times[(int)card]++;
    }
    long long coins=0;
    while(1) {
        int max_i='A';
        int max=times['A'];
        for(i='B'; i<='Z'; i++) {
            if(times[i]>max) {
                max_i=i;
                max=times[i];
            }
        }
        if(max>=k) {
		//说明可以分配完了！
            long long k2=(long long)k;
            //两个10^5相乘就出界了！
            long long kk=k2*k2;
            coins=coins+kk;
            break;
        } else {
            times[max_i]=0;
            long long max2=(long long)max;
            long long mmax=max2*max2;
            coins=coins+mmax;
            k=k-max;
        }
    }
    printf("%lld\n",coins);
    return 0;
}
