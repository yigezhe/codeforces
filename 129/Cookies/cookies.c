/*interface*/
#include<stdio.h>
/*interface implementation*/
/*client*/
int main() {
    int n;
    scanf("%d",&n);
    int i;
    int odd=0;
    for(i=0; i<n; i++) {
        int a;
        scanf("%d",&a);
        if(a%2==1) odd++;
    }
    //他要偷走所有奇数包
    if(odd%2==1) {
	    //只能偷奇数包！
        printf("%d\n",odd);
    } else {
	    //只能偷偶数包！
        printf("%d\n",n-odd);
    }
    return 0;
}
