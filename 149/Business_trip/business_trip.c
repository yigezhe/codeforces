//我需要不断提高自己解决问题的速度与能力。
//一次工作，我不满足只解决一个问题。
//而是去解决两个，三个，直至一口气，解决5个问题。
//真正把自己的能力培养起来！
//商务旅行中，父母把孩子丢在了家里！
//这是一个硬币问题！可以用硬币问题的方法解决，但这个问题又与硬币问题有差别
//就是几个硬币的和只要大于等于总和就可以，不一定刚好等于总和！
/*interface*/
#include<stdio.h>
void sort(int *,int);
void swap(int *,int *);
void print(int *,int);
/*interface implementation*/
void swap(int *a,int *b) {
    int tmp=*a;
    *a=*b;
    *b=tmp;
}
//这里需要从大到小排列！
void sort(int *data,int length) {
    int i,j;
    for(i=0; i<length; i++) {
        //把最小的移动到最后一位！
        for(j=0; j<length-1; j++) {
            if(data[j]<data[j+1]) {
                swap(&data[j],&data[j+1]);
            }
        }
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
#include<stdio.h>
#define M 12
int main() {
    //我的思路是，先拍序，之后前几个相加，
    //只要和大于等于k停止，并统计加了几项，然后打印几！
    int k;
    scanf("%d",&k);
    int i;
    int a[M];
    for(i=0; i<M; i++) {
        scanf("%d",&a[i]);
    }
    //print(a,M);
    sort(a,M);
    //print(a,M);
    int sum=0;
    if(0==k) {
        printf("%d\n",0);
        return 0;
    }
    int find=0;
    for(i=0; i<M; i++) {
        sum+=a[i];
        if(sum>=k) {
		find=1;
		break;
	}
    }
    if(find)printf("%d\n",i+1);
    else printf("%d\n",-1);
    return 0;
}
