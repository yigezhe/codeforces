//mole是盲人！
/*interface*/
/*interface implementation*/
/*client*/
#define N 1000001
#include<stdio.h>
int main() {
    int n;
    scanf("%d",&n);
    int i;
    int label[N];
    for(i=0; i<n; i++) {
        label[i]=-1;
    }
    int l=0;
    for(i=0; i<n; i++) {
        int a;
        scanf("%d",&a);
        int j;
        for(j=l; j<l+a; j++) {
            label[j]=i;
        }
        l=l+a;
    }
    /*
    for(i=0; i<l; i++) {
        printf(" %d",label[i]);
    }
    printf("\n");
    */

    //1 2 //0 1
    //3 9 //2 8
    int m;
    scanf("%d",&m);
    for(i=0; i<m; i++) {
        int q;
        scanf("%d",&q);
        printf("%d\n",label[q-1]+1);
    }
    return 0;
}
