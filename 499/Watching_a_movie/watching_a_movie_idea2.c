//现实的问题都可以汇集在编程竞赛问题中！
//这个问题有一些类似！
//因为有x的限制，所以会多看！
//我的想法是用染色方式来处理！
/*interface*/
/*interface implementation*/
/*client*/
#include<stdio.h>
#define N 100000+1
int main() {
    int n,x;
    scanf("%d%d",&n,&x);
    //printf("n=%d,x=%d\n",n,x);
    int i;
    int counter=0;
    int unwatch=1;
    //把问题想得越简单越好，把恋爱想得越简单越好！
    //你不爱我，我找另一个就可以！
    //因为我需要的是恋爱，而不是专门的某一个人，只要
    //那个人可以给我爱恋的经历与体验就可以！
    for(i=0; i<n; i++) {
        int l,r;
        scanf("%d%d",&l,&r);
        //printf("l=%d,r=%d\n",l,r);
        counter+=((l-unwatch)%x);
        counter+=(r-l+1);
        unwatch=r+1;
    }
    printf("%d\n",counter);

    return 0;
}
