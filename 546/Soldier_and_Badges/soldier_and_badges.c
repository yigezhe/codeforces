//例子二，让2变为4也可以！
//想法一找到相同项，
//在相同项两边找到缺失项，
//把相同项调整到缺失项所用的步子，就是我们要花的钱！
//1 3 1 4,相同项是1，最近的缺失项是2，把1调到2就可以！
//1 2 3 2 5，相同项是2，缺失项是4，把2调整到4就可以！
#include<stdio.h>
//极端情况是3000个数都是3000，那么我需要增加到6000去！
#define N (3000+1)*2
int main() {
    int n;
    scanf("%d",&n);
    int a[N];
    int i;
    for(i=0; i<N; i++) {
        a[i]=0;
    }
    for(i=0; i<n; i++) {
        int coolness;
        scanf("%d",&coolness);
        a[coolness]++;
    }
    int j;
    int coins=0;
    for(i=1; i<N; i++) {
        if(a[i]>1) {
            for(j=i+1; j<N; j++) {
                if(a[i]>1 && a[j]==0) {
                    coins+=(j-i);
                    a[j]=1;
                    a[i]--;
                }
            }
        }
    }
    printf("%d\n",coins);
    return 0;
}
