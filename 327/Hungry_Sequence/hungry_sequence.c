/*interface*/
#include<stdio.h>
#include<stdlib.h>
#define N 100000+1
/*interface implementation*/
int is_prime(int n) {
    int i;
    for(i=2; i*i<=n; i++) {
        if(n%i==0) return 0;
    }
    return 1;
}
void print(int *a,int n) {
    int i;
    for(i=0; i<n; i++) {
        printf(" %d",a[i]);
    }
    printf("\n");
}
void sort(int* a,int length) ;
void merge_sort(int *a, int * tmp, int left, int right) ;
void merge(int * a, int * tmp, int left, int right, int right_end ) ;
void sort(int* a,int length) {
    int *tmp = malloc(sizeof(int)*length);
    if(tmp==NULL) {
        printf("没有分配到足够的内存\n");
    }
    //有一个备用数组！就是存储空间增加了一倍，
    //应该选择不需要备用数组的归并排序！
    merge_sort(a, tmp,  0, length - 1);
}

void merge_sort(int *a, int * tmp, int left, int right) {
    if( left < right ) {
        int center = (left + right) / 2;
        merge_sort(a, tmp, left, center);
        merge_sort(a, tmp, center + 1, right);
        merge(a, tmp, left, center + 1, right);
    }
}

void merge(int * a, int * tmp, int left, int right, int right_end ) {
    //这一部分代码还没有看懂，但是先用！
    int left_end = right - 1;
    int k = left;
    int num = right_end - left + 1;

    while(left <= left_end && right <= right_end)
        if(a[left]<=a[right]) {
            tmp[k] = a[left];
            k++;
            left++;
            //就是左边小就取左边的！
        } else {
            tmp[k] = a[right];
            k++;
            right++;
            //右边小取右边！
        }
    //上面处理之后有两种情况
    //1.左边取完了，右边没有取完
    //1.右边取完了，左边没有取完
    while(left <= left_end)    // Copy rest of first half
        tmp[k++] = a[left++];

    while(right <= right_end)  // Copy rest of right half
        tmp[k++] = a[right++];

    // Copy tmp back
    int i;
    for(i = 0; i < num; i++, right_end--)
        a[right_end] = tmp[right_end];
}
/*client*/
int main() {
    int n;
    scanf("%d",&n);
    //我的探索是10000以内的整数中
    //大约有625个素数
    //我们取出450个素数，
    //两两相乘，得到一个全部不相互整除的数组！
    int p[4000];
    int np=0;
    int i;
    for(i=2; i<4000; i++) {
        if(is_prime(i)) {
            p[np]=i;
            np++;
        }
    }
    //printf("np=%d\n",np);
    int j;
    int counter=0;
    int stop=0;
    int a[N];
    for(i=0; i<np && !stop; i++) {
        for(j=i+1; j<np && !stop; j++) {
            a[counter]=p[i]*p[j];
            counter++;
            if(counter==n) stop=1;
        }
    }
    sort(a,n);
    print(a,n);
    return 0;
}
