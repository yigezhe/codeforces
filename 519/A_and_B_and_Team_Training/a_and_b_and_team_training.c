//莫名奇妙地成功了！
#include<stdio.h>
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    //用21，12互调的方式来分配nm相等的情况！
    int teams=(n+m)/3;
    if(n>=2*m) {
        teams=m;
    }
    if(m>=2*n) {
        teams=n;
    }
    //分情况处理，
    //n,m,m是n的两倍及其以上，就需要采用21分配！,是n个队！
    //n,m,n是m的两倍及其以上，就需要采用21分配！,是m个队！
    //任何时候出现双倍关系，都要这样处理！
    printf("%d\n",teams);
    return 0;
}
