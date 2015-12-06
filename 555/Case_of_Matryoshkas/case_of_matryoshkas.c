/*这道题重在一个分析的过程
 * 先找出ai数组中从1到i的数组，因为1到i不需要再拆开
 * 第二步就是把所有的元素都拆开！
 *需要m1-i,m2-1,m3-1,...,mk-1因为顺序不是最重要的，所以我把1到i放在m1的位置！
 总和就是(m1-i)+(m2-1)+(m3-1)+...+(mk-1)=m1+m2+m3+...+mk-i+k-1=n-i+k-1
 第三步是合并
 拆分出 m1-i,m2,m3,...,mk个元素！两两合并，需要总个数减一步！
 就是m1-i+m2+m3+...+mk=n-i
 所以总的操作是：(n-i+k-1)+(n-i)
 * */
/*interface*/
#include<stdio.h>
#define N 100000
/*interface implementation*/
/*client*/
int main() {
    int n,k;
    scanf("%d%d",&n,&k);
    int i,j;
    int m[N];
    int a[N];
    int chain=0;
    for(i=0; i<k; i++) {
        scanf("%d",&m[i]);
        for(j=0; j<m[i]; j++) {
            scanf("%d",&a[j]);
        }
        /*
            for(j=0; j<m[i]; j++) {
                printf(" %d",a[j]);
            }
        printf("\n");
        */
        int counter=0;
        for(j=0; j<m[i]; j++) {
            if(a[j]==j+1) {
                counter++;
            } else {
                break;
            }
        }
        if(counter>chain) chain=counter;
    }
    //printf("chain=%d\n",chain);
    printf("%d\n",2*n-2*chain+1-k);
    return 0;
}
