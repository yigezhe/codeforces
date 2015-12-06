//lanterns路灯！
/*interface*/
void sort(int *,int);
void print(int *,int);
int compare(const void *,const void *);

/*interface implementation*/
#include<stdio.h>
#include<stdlib.h>
int compare(const void *a,const void *b) {
    int *x = (int *) a;
    int *y = (int *) b;
    return *x - *y;
}
void sort(int *data,int length) {
    //qsort (data, sizeof(data)/sizeof(*data), sizeof(*data), compare);
    qsort (data, length, sizeof(int), compare);
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
#define N 1002
int main() {
    //double eps=1e-9;
    int n,l;
    scanf("%d%d",&n,&l);
    int i;
    int a[N];
    for(i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }
    //先排序，之后再找到相邻路灯的距离的一半的最大值就是我们想要的结果！
    //print(a,n);
    sort(a,n);
    //print(a,n);
    //第一个路灯能照到的地方！
    double max=0.0;
    double half=a[0]-0;
    //最后一个路灯能照到的地方！
    if(half>max) max=half;
    half=l-a[n-1];
    if(half>max) max=half;
    //内部相邻路灯能照到的地方！
    for(i=0; i<n-1; i++) {
	    half=(a[i+1]-a[i])/2.0;
	    if(half>max) max=half;
    }

    printf("%lf\n",max);

    return 0;
}
