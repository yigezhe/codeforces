//laptops，lap膝盖?
//distinct严格不同！
//n^2=10^10危险！
/*interface*/
/*interface implementation*/
/*client*/
#include<stdio.h>
#define N 100000+1
int main() {
    int n;
    scanf("%d",&n);
    int a[N];
    int b[N];
    int i;
    for(i=0; i<n; i++) {
        scanf("%d%d",&a[i],&b[i]);
    }
    int j;
    for(i=0; i<n; i++) {
        for(j=i+1; j<n; j++) {
            if((a[i]<a[j] && b[i]>b[j]) || (a[i]>a[j] && b[i]<b[j]) ){
                printf("Happy Alex");
                return 0;
            }
        }
    }
    printf("Poor Alex");
    return 0;
}
