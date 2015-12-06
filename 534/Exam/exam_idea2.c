//用一个递归函数打印出一种可能！
/*interface*/
/*interface implementation*/
#include<stdio.h>
#include<stdlib.h>
#define N 5000
void swap(int *a,int *b) {
    int tmp=*a;
    *a=*b;
    *b=tmp;
}
void print(int *a,int n) {
    int i;
    for(i=0; i<n; i++) {
        printf(" %d",a[i]);
    }
    printf("\n");
}
/*client*/
int main() {
    int n;
    scanf("%d",&n);
    int perm[N];
    int max_perm[N];
    int i,j,k;
    int max=0;
    //N*N*N=5000*5000*5000=125*10^9=10^11的复杂度！
    //如果是这个复杂度，问题不会在1秒内解决！
    //我猜我的算法是N*N的复杂度！
    for(k=0; k<n; k++) {
	    //以不同数字开头的一个简单排列！
        for(i=0; i<n; i++) {
            perm[i]=(k+i)%n+1;
        }
        //print(perm,n);
	//虽然是两个循环，但是i是单循环推进的。
        for(i=0; i<n-1; i++) {
            int can=0;
            int last=n-1;
            while(1) {
                if(abs(perm[i]-perm[i+1])==1) {
                    can=0;
                    if(last==i+1) {
                        break;
                    } else {
                        swap(&perm[i+1],&perm[last]);
                        last--;
                    }
                } else {
                    can=1;
                    break;
                }
            }
            if(!can) {
                break;
            }
        }
        int h=1;
        for(i=0; i<n-1; i++) {
            if(abs(perm[i]-perm[i+1])==1) {
                break;
            } else {
                h++;
            }
        }
        if(h>max) {
            max=h;
            for(i=0; i<n; i++) {
                max_perm[i]=perm[i];
            }

        }
    }
    printf("%d\n",max);
    for(j=0; j<max; j++) {
        printf(" %d",max_perm[j]);
    }
    printf("\n");
    return 0;
}
