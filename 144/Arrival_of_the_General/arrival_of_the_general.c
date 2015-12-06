#include<stdio.h>
#define N 100
int main() {
    int n;
    scanf("%d",&n);
    int i;
    int a[N];
    //我完全按照题目设置的条件取值！
    int min_a=100+1;
    int min_i=0;
    int max_a=0;
    int max_i=0;
    for(i=0; i<n; i++) {
        scanf("%d",&a[i]);
	//这里的等号很重要可以保证我取到最靠右边的最小值！
        if(min_a>=a[i]) {
            min_a=a[i];
            min_i=i;
        }
	//这里的没有等号也很重要可以保证我取到最靠左边的最小值！
        if(max_a<a[i]) {
            max_a=a[i];
            max_i=i;
        }
    }
    //min_i到n-1需要几秒！ n-1-min_i秒！
    //max_i到0需要几秒！ max_i-0秒！
    int seconds=(n-1-min_i) + (max_i-0);
    if(max_i>min_i) {
	    //这种情况下，把最大的先挑换到最左边的过程中，会让最小的向右提前一步，这时把最小的向后挑换的步骤就会减一，这就是这个语句的作用！
	    seconds--;
    }
    //printf("%d---%d\n",max_i,min_i);
    printf("%d\n",seconds);
    return 0;
}
