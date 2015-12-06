//用一个递归函数打印出一种可能！
/*interface*/
/*interface implementation*/
#include<stdio.h>
#include<stdlib.h>
#define N 5000
int used[N];
int perm[N];
void print(int *a,int n) {
    int i;
    for(i=0; i<n; i++) {
        printf(" %d",a[i]);
    }
    printf("\n");
}
//第一步先不考虑相邻数，而是打印出一种排列！
int non_adjacent_permutation(int which,int size,int max) {
//printf("non_adjacent_permutation(%d,%d)\n",which,size);
    if(which>=max) {
        print(perm,max);
        //printf("why?");
        return 1;
        //return ;

    }
    int i;
    int can=0;
    for(i=0; i<size; i++) {
        if(!used[i+1]) {
            if(which>0) {
                if(perm[which-1]-(i+1)!=1 && perm[which-1]-(i+1)!=-1 ) {
                    can=1;
                    perm[which]=i+1;
                    used[i+1]=1;
                    non_adjacent_permutation(which+1,size,max);
                    perm[which]=0;
                    used[i+1]=0;
                }
            } else {
                can=1;
                perm[which]=i+1;
                used[i+1]=1;
                non_adjacent_permutation(which+1,size,max);
                perm[which]=0;
                used[i+1]=0;
            }

        }

    }
    if(!can) {
        return 0;
    }else {
	    return 1;
    }
}
/*client*/
int main() {
    int n;
    scanf("%d",&n);
    int max=n;
    non_adjacent_permutation(0,n,max);
    non_adjacent_permutation(0,n,max--);
    return 0;
}
