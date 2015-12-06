#include<stdio.h>
#include<stdlib.h>
//为qsort准备的比较函数！
int cmp(const void *a,const void *b) {
    //把a，b先由一般形式 void *，转化为我们需要的int ＊形式！
    //const是为了保证我们不去修改它！
    return *(int *)a-*(int *)b;
}
int main() {
    int n,w;
    //n代表有n个男孩，也代表有n个女孩！
    //w代表茶壶的总容量！
    scanf("%d%d",&n,&w);
    int i;
    //我们创建一个2n长度的数组a！
    long long *a=malloc(2*n*sizeof(a[0]));
    if(a==NULL) {
        printf("a don't get memory\n");
    }
    //读取数据a[i]表示第i个茶杯的容量！
    for(i=0; i<2*n; i++) {
        scanf("%lld",&a[i]);
    }
    /*
    for(i=0; i<2*n; i++) {
        printf(" %lld",a[i]);
    }
    printf("\n");
    */

    //我利用系统自带的排序函数qsort来快速实现一个排序！
    qsort(a,2*n,sizeof(a[0]),cmp);
    /*
    for(i=0; i<2*n; i++) {
        printf(" %lld",a[i]);
    }
    printf("\n");
    printf("a0=%lld,a%d=%lld\n",a[0],n,a[n]);
    */

    //a[n]>=2*a[0]
    //a0~an-1 an~a2n-1
    //女孩子最大拿a0, 这样男孩子要拿2*a0,这里必须保证an至少是2*a0
    //即an》＝2*a0
    //这时的最大茶水容量是n*a0+2*a0*n=3*n*a0
    //男孩子最多拿an，这样女孩子要拿an/2,这样a0至少是an／2，
    //即a0>=an/2
    //这时的最大茶水容量是n*an/2+an*n=3/2*n*an
    double res=0.0;
    if(a[n]>=2*a[0]) {
        res=3.0*n*a[0];
    } else {
        res=3.0*n*a[n]/2.0;
    }
    if(res>w) res=w;
    printf("%f\n",res);
    free(a);
    return 0;
}
