//dumb笨！
//n节课，每一章花费x小时
//第i节课，有ci章！
//先排序后学习！
/*interface*/
#include<stdio.h>
#define N 100000+1
void sort(long long *,int);
void insertion_sort(long long *,int);
void print(int *,int);

/*interface implementation*/
void sort(long long *data,int length) {
    insertion_sort(data,length);
}
void insertion_sort(long long *data,int length) {
    //感觉作者写的有点复杂了！
    int i;
    for (i = 0; i < length; i++) {
        int j = i;
        //在i左边的比i大的元素
        //i=1,不会进入while循环！
        while (j > 0 && data[i] < data[j - 1])
            j--;
        long long tmp = data[i];
        int k;
        //把比i大的元素都向右统一移动一位！
        for (k = i; k > j; k--)
            data[k] = data[k - 1];
        //把i放在比他大的最左边的那个元素的位置上！
        data[j] = tmp;
    }
}
void print(int *data,int length) {
    int i;
    for(i=0; i<length; i++) {
        printf(" %d",data[i]);
    }
    printf("\n");
}
/*client*/
int main() {
    int n;
    long long x;
    scanf("%d%lld",&n,&x);
    long long time=0;
    long long c[N];
    int i;
    for(i=0; i<n; i++) {
        scanf("%lld",&c[i]);
    }
    sort(c,n);

    for(i=0; i<n; i++) {
        if(x>1) {
            //保证与time相加的数字都是long long型！
            time+=c[i]*x;
            x--;
        } else if(x==1) {
            time+=c[i]*x;
        }
    }
    printf("%lld\n",time);
    return 0;
}
