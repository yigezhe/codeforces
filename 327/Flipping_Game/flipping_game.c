//为什么一定是很烦的时候，才打游戏？
/*interface*/
/*interface implementation*/
/*client*/
#include<stdio.h>
#define N 100
int main() {
    int n;
    scanf("%d",&n);
    int a[N];
    int tmp[N];
    int i;
    for(i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }
    int j,k;
    int max=0;
    for(i=0; i<n; i++) {
        for(j=i; j<n; j++) {
            for(k=0; k<n; k++) {
                tmp[k]=a[k];
            }
            int counter=0;
            for(k=i; k<=j; k++) {
                tmp[k]=1-tmp[k];
	    }
            for(k=0; k<n; k++) {
                if(tmp[k]==1) counter++;
            }
            if(counter>max) max=counter;
        }
    }
    printf("%d\n",max);
    return 0;
}
