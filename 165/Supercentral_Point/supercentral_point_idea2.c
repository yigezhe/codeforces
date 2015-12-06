//太棒了，太出色了！
//结构太好了！
/*interface*/
#include<stdio.h>
#define N 200
int n;
int x[N],y[N];
/*interface implementation*/
int is_supercentral(int i) {
    int k;
    int right=0;
    int left=0;
    int up=0;
    int down=0;
    for(k=0; k<n; k++) {
        if(k!=i) {
            if(y[k]==y[i]) {
                if(x[k]>x[i]) {
                    right=1;
                }
                if(x[k]<x[i]) {
                    left=1;
                }
            }
            if(x[k]==x[i]) {
                if(y[k]>y[i]) {
                    up=1;
                }
                if(y[k]<y[i]) {
                    down=1;
                }
            }
        }
    }
    if(left && right && up && down) return 1;
    else return 0;
}

/*client*/
int main() {
    scanf("%d",&n);
    int i;
    for(i=0; i<n; i++) {
        scanf("%d%d",&x[i],&y[i]);
    }
    int counter=0;
    for(i=0; i<n; i++) {
        if(is_supercentral(i)) {
            counter++;
        }
    }
    printf("%d\n",counter);

    return 0;
}
