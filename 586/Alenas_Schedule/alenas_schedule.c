/*interface*/
#include<stdio.h>
#define N 100
/*interface implementation*/
/*client*/
int main() {
    int n;
    scanf("%d",&n);
    int a[N];
    int i;
    for(i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }
    i=0;
    while(i<n && a[i]==0) i++;
    int counter=0;
    while(1) {
        while(i<n && a[i]==1) {
            counter++;
            i++;
        }
        if(i==n) break;
        int zeros=0;
        while(i<n && a[i]==0) {
            i++;
            zeros++;
        }
        if(zeros==1) {
            if(i!=n) counter++;
        }
        if(i==n) break;
    }
    printf("%d\n",counter);
    return 0;
}
