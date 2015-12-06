/*interface*/
#include<stdio.h>
#define N 100
/*interface implementation*/
//我快速独立实现了一个nn级别的排序算法！
void sort(char *a,int size) {
    int i,j;
    for(i=0; i<size; i++) {
        for(j=i+1; j<size; j++) {
            if(a[i]>a[j]) {
                char tmp=a[i];
                a[i]=a[j];
                a[j]=tmp;
            }
        }
    }
}
/*client*/
int main() {
    int n;
    scanf("%d",&n);
    char digit[2*N+1];
    char first[N+1];
    char second[N+1];
    scanf("%s",digit);
    int i;
    for(i=0; i<n; i++) {
        first[i]=digit[i];
        second[i]=digit[n+i];
    }
    sort(first,n);
    sort(second,n);
    int counter1=0,counter2=0;
    for(i=0; i<n; i++) {
        if(first[i]>second[i]) counter1++;
        if(first[i]<second[i]) counter2++;
    }
    if(counter1==n || counter2==n) printf("YES\n");
    else printf("NO\n");

    return 0;
}
