/*interface*/
//其实寻找最少更换是一个很有难度的问题，以后有能力了可以解决！
//现在只关注当前问题的解决！
//我是按最低要求做的！
#include<stdio.h>
#define N 3000
/*interface implementation*/
/*client*/
int main() {
    int n,a[N];
    int swap_a[N];
    int swap_b[N];
    scanf("%d",&n);
    int i;
    for(i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }
    int j;
    int k=0;
    for(i=0; i<n; i++) {
        int min=i;
        for(j=i+1; j<n; j++) {
            if(a[j]<a[min]) min=j;
        }
        swap_a[k]=min;
        swap_b[k]=i;

        int tmp=a[min];
        a[min]=a[i];
        a[i]=tmp;

        k++;
    }
    printf("%d\n",k);
    for(i=0; i<k; i++) {
        printf("%d %d\n",swap_a[i],swap_b[i]);
    }
    return 0;
}
