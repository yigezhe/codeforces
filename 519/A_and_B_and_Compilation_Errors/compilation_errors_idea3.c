//submit not ok,because insert sort is not fast!
//编译器要记录你上一次编译中的错误吗？
//就是先显示上一次未解决的错误，在显示新的错误，
//还有一点就是直接按照错误出现在哪一行，按行数从小到大排列！
//因为只有你解决了前面的错误，你才可以解决后面的错误！
//想法一，直接线性查找！
//改进思路是，先排序，后二分查找！
//n^2的时间消费，10^10的计算量！
//虽然消耗时间，但是先实现一下！
//想法三则是把三个数组都排序，然后从头往前依次找，找到不同项，就是我们需要的那个值！
//我优先实现想法三！
/*interface*/
#include<stdio.h>
void sort(int *,int);
void insertion_sort(int *,int);
void print(int *,int);
/*interface implementation*/
void sort(int *data,int length) {
    insertion_sort(data,length);
}
void insertion_sort(int *data,int length) {
	//感觉作者写的有点复杂了！
     int i;
     for (i = 0; i < length; i++) {
          int j = i;
          //在i左边的比i大的元素
	  //i=1,不会进入while循环！
          while (j > 0 && data[i] < data[j - 1])
               j--;
          int tmp = data[i];
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
#include<stdio.h>
#define N 100000
int main() {
    int n;
    int a[N],b[N],c[N];
    scanf("%d",&n);
    int i;
    for(i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }
    sort(a,n);
    for(i=0; i<n-1; i++) {
        scanf("%d",&b[i]);
    }
    sort(b,n-1);
    for(i=0; i<n-2; i++) {
        scanf("%d",&c[i]);
    }
    sort(c,n-2);
    /*
    print(a,n);
    print(b,n-1);
    print(c,n-2);
    */
    int find=0;
    for(i=0; i<n-1; i++) {
	    if(a[i]!=b[i]) {
		    find=1;
		    printf("%d\n",a[i]);
		    break;
	    }
    }
    if(!find) printf("%d\n",a[n-1]);
    find=0;
    for(i=0; i<n-2; i++) {
	    if(b[i]!=c[i]) {
		    find=1;
		    printf("%d\n",b[i]);
		    break;
	    }
    }
    if(!find) printf("%d\n",b[n-2]);


    return 0;
}
