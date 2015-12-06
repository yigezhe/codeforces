//In the name of God
#include <stdio.h>

int main() {
    char inp[10];
    int n,ans=0;
    scanf("%d",&n);
    //n,n-1,1可以进入，0无法进去！
    //也就实现了n次循环！
    while(n--) {
        scanf(" %s",inp);
        if(inp[1]=='+')
            ans++;
        else
            ans--;
    }
    printf("%d\n",ans);
    return 0;
}
