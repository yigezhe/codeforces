//从小到大排列，然后，优先取最小的！
/*interface*/
void sort(int *,int);
void insertion_sort(int *,int);
void print(int *,int);
/*interface implementation*/
#include<stdio.h>
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
#define N 100
int main() {
	int n,k;
	scanf("%d%d",&n,&k);
	int a[N];
	int i;
	for(i=0;i<n;i++) {
		scanf("%d",&a[i]);
	}
	sort(a,n);
	int instrument=0;
	int time=0;
	int learn[N];
	for(i=0;i<n;i++) {
		if(time+a[i]<=k) {
			time+=a[i];
			learn[instrument]=a[i];
			instrument++;
		}else {
			break;
		}
	}
	printf("%d\n",instrument);
	for(i=0;i<instrument;i++) {
		if(i==instrument-1) printf("%d\n",learn[i]);
		else printf("%d ",learn[i]);
	}
	return 0;
}
