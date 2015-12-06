//我不知道point 1，2，3，4hold是什么意思，
//不过问题已经解决了！
/*interface*/
#include<stdio.h>
#define N 100
#define M 100
#define MAX 100+1
/*interface implementation*/
/*client*/
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    int a[N];
    int i;
    int max_a=0;
    int min_a=MAX;
    for(i=0; i<n; i++) {
        scanf("%d",&a[i]);
        if(a[i]>max_a) max_a=a[i];
        if(a[i]<min_a) min_a=a[i];
    }
    int b[M];
    int min_b=MAX;
    for(i=0; i<m; i++) {
        scanf("%d",&b[i]);
        if(b[i]<min_b) min_b=b[i];
    }
    if(max_a>=min_b) printf("-1\n");
    else {
        int find=0;
        for(i=max_a; i<=min_b-1; i++) {
            if(i/2>=min_a) {
                printf("%d\n",i);
                find=1;
                break;
            }
        }
        if(!find) printf("-1\n");
    }
    return 0;
}
