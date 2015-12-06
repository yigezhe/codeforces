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
    for(i=0; i<n; i++) {
        int l,r;
        scanf("%d%d",&l,&r);
        for(j=l; j<=r; j++) {
            movie[j]=1;
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

    int start,end;
    i=1;
    while(i<N) {
        start=i;
        while(movie[i]==0 && i<N) {
            i++;
        }
        end=i;
        if(movie[end]==1 && i<N) {
		//这里还是模仿了我第一个成功的例子！
		//这个由后往前推是可靠的！
            j=(end-start)%x;
            while(j>0) {
                watch[end-j]=1;
                j--;
            }
            while(movie[i]==1 && i<N) {
                watch[i]=1;
                i++;
            }
        } else {
            break;
        }
    }
    counter=0;
    for(i=0; i<N; i++) {
        if(watch[i]==1) counter++;
    }
    printf("%d\n",counter);
    return 0;
}
