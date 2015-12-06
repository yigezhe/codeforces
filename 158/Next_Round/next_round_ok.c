#include<stdio.h>
#define MAX_N 50+5
int a[MAX_N];
int main() {
    int n,k;
    scanf("%d%d",&n,&k);
    int i;
    for (i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }
    //大于等于第k位的成绩！
    //a[k-1]就是第k位的成绩！
    if (a[k-1]==0) {
        //处理第k位是零的情况
        i=k-2;
        while (i>=0 && a[i]==0) {
            i--;
        }
        //取消所有k位之前还为零的成员，只留下分数大于零的成员

        printf("%d\n",i+1);
        return 0;
    } else {
        //看看k位之后，还有多少位与k位相同！
        i=k;
        while (a[i]==a[k-1]) {
            i++;
        }
        printf("%d\n",i);
    }
    return 0;
}
