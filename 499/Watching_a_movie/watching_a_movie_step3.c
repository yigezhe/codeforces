//现实的问题都可以汇集在编程竞赛问题中！
//这个问题有一些类似！
//因为有x的限制，所以会多看！
//我的想法是用染色方式来处理！
/*interface*/
/*interface implementation*/
/*client*/
#include<stdio.h>
#define N 100000+100
int main() {
    int n,x;
    scanf("%d%d",&n,&x);
    int i,j;
    int movie[N];
    int watch[N];
    int counter;
    for(i=0; i<N; i++) {
        movie[i]=0;
        watch[i]=0;
    }
    int last=0;
    for(i=0; i<n; i++) {
        int l,r;
        scanf("%d%d",&l,&r);
        //保证电影判断从零开始！
	if(i==n-1) last=r;
        for(j=l; j<=r; j++) {
            movie[j-1]=1;
        }
    }
    /*
    for(i=0; i<13; i++) {
        if(movie[i]==1) {
            printf("*");
        } else {
            printf(".");
        }
    }
    printf("\n");
    */

    i=0;
    int start;
    int find;
    while(i<last) {
        //printf("i=%d\n",i);
        //不感兴趣的部分需要跳过，但是
        //只能x个长度地跳过！
        //x个长度x个长度地处理！
        counter=0;
        find=0;
        start=i;
        for(i=start; i<start+x && i<last; i++) {
            if(movie[i]==1) {
                find=1;
                break;
            }
            counter++;
        }
        if(counter<x) {
            if(find) {
                for(j=start; j<start+x && j<last; j++) {
                    watch[j]=1;
                }

            }
        }
        while(movie[i]==1 && i<last) {
            watch[i]=1;
            i++;
        }
    }
    counter=0;
    for(i=0; i<last; i++) {
        if(watch[i]==1) counter++;
    }
    printf("%d\n",counter);

    return 0;

}
