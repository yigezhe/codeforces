//现金系统,currency system
//如果banknotes有1，那么返回－1
//如果banknotes没有一，我可以用深度优先来搜索最小的！
//这个测试数据很糟糕！
/*interface*/
#include<stdio.h>
#define N 1000+1

/*interface implementation*/
/*client*/
int n;
int banknote[N];
int find(int sum,int unfortunate) {
    if(sum==unfortunate) return 1;
    int i;
    for(i=0; i<n; i++) {
        if(banknote[i]+sum<unfortunate) {
            return find(sum+banknote[i],unfortunate);
        } else if(banknote[i]+sum==unfortunate) {
            return 1;
        }
    }
    return 0;
}
int main() {
    scanf("%d",&n);
    int i;
    for(i=0; i<n; i++) {
        scanf("%d",&banknote[i]);
        if(banknote[i]==1) {
            printf("%d\n",-1);
            return 0;
        }
    }
    int unfortunate=1;
    while(1) {
        if(find(0,unfortunate)) unfortunate++;
        else  {
            printf("%d\n",unfortunate);
            break;
        }
    }

    return 0;
}
