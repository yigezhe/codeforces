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
    int i,j;
    for(i=0; i<n; i++) {
        perm[i]=i+1;
    }
    for(i=0; i<n-1; i++) {
        //print(perm,n);
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
    int k=1;
    for(j=0; j<n-1; j++) {
	    if(abs(perm[j]-perm[j+1])==1) {
		    break;
	    }else {
		    k++;
	    }
    }
    printf("%d\n",k);
    for(j=0; j<k; j++) {
        printf(" %d",perm[j]);
    }
    printf("\n");
    return 0;
}
