//我会利用好我的时间做好当前最重要的事情！
//这是一个实际问题，
//但是有一点就是现实中，没有人愿意互换位置！
//想法一，排一个序，统一个计就可以！
/*interface*/
#include<stdio.h>
#define N 100000+1
#include<stdlib.h>
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
    //10^5*10^9=10^14属于longlong的范围！
    scanf("%d",&n);
    int i;
    int t[N];
    long long total=0;
    for(i=0; i<n; i++) {
        scanf("%d",&t[i]);
        total+=(long long) t[i];
    }
    //print(t,n);
    //这个编程的节奏太好了！
    //思路很清晰！
    sort(t,n);
    //排序之后是一个挑选构造的过程！
    //print(t,n);
    int disappointed=0;
    long long waits=0;
    i=0;
    while(i<n) {
        if(waits<=(long long)t[i]) {
            //这其中的发现和探索过程让我兴奋！
            //printf("t[%d]=%d\n",i,t[i]);
            disappointed++;
            waits+=(long long)t[i];
            i++;
        } else {
            while(i<n && waits>(long long)t[i]) {
                i++;
            }
            if(i==n) {
                break;
            }
        }
    }
    printf("%d\n",disappointed);
    return 0;
}
