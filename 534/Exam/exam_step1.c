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
void non_adjacent_permutation(int which,int size) {
    if(which==size) {
        print(perm,size);
	exit(0);
        //return ;

    }
    int i;
    for(i=0; i<size; i++) {
        if(!used[i+1]) {
            perm[which]=i+1;
            used[i+1]=1;
            non_adjacent_permutation(which+1,size);
            perm[which]=0;
            used[i+1]=0;
        }

    }
}
/*client*/
int main() {
    int n;
    scanf("%d",&n);
    non_adjacent_permutation(0,n);
    return 0;
}
