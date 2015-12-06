//太棒了，太出色了！
//结构太好了！
/*interface*/
#include<stdio.h>
#define N 200
/*interface implementation*/
/*client*/
int main() {
    int n;
    scanf("%d",&n);
    int x[N],y[N];
    int i;
    int up[N],down[N],left[N],right[N];
    for(i=0; i<n; i++) {
        scanf("%d%d",&x[i],&y[i]);
        up[i]=0;
        down[i]=0;
        left[i]=0;
        right[i]=0;
    }
    int j;
    for(i=0; i<n; i++) {
        for(j=i+1; j<n; j++) {
            if(x[i]==x[j]) {
                if(y[i]>y[j]) {
                    down[i]=1;
                    up[j]=1;
                } else if(y[i]<y[j]) {
                    down[j]=1;
                    up[i]=1;
                }
            }
            if(y[i]==y[j]) {
                if(x[i]>x[j]) {
                    left[i]=1;
                    right[j]=1;
                } else if(x[i]<x[j]) {
                    left[j]=1;
                    right[i]=1;
                }
            }
        }
    }
    int counter=0;
    for(i=0; i<n; i++) {
        if(up[i] && down[i] && left[i] && right[i]) {
            //printf("(%d,%d)\n",x[i],y[i]);
            counter++;
        }
    }
    printf("%d\n",counter);
    return 0;
}
