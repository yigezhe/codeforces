//这里打算用二分法来实现！
//这里看不需要二分法！
//这里没有处理得分为零的情况，现在补充处理！
#include<stdio.h>
#define MAX_N 50+1
int a[MAX_N];
int main() {
    int n,k;
    scanf("%d%d",&n,&k);
    int i;
    for (i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }
    if (a[k-1]==0) {
        i=k-2;
        while (i>=0 && a[i]==a[k-1]) {
            i--;
        }

        printf("%d\n",i+1);
        return 0;
    } else {
        i=k;
        while (a[i]==a[k-1]) {
            i++;
        }
        printf("%d\n",i);
    }
    return 0;
}
