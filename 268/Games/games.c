#include<stdio.h>
#define N 30
int main() {
    int home[N];
    int guest[N];
    int n;
    scanf("%d",&n);
    int i,j;
    for(i=0; i<n; i++) {
        scanf("%d%d",&home[i],&guest[i]);
    }
    int count=0;
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            if(i!=j && home[i]==guest[j]) {
                count++;
            }
        }
    }
    printf("%d\n",count);
    return 0;
}
