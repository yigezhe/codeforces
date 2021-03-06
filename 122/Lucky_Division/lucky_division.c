#include<stdio.h>
int is_lucky(int n) {
    while (n>0) {
        if(n%10==4 || n%10==7) {
            n=n/10;
        } else {
            return 0;
        }
    }
    return 1;
}
int main() {
    int n;
    scanf("%d",&n);
    int i;
    if(is_lucky(n)) {
        printf("YES\n");
        return 0;
    } else {
	    //用i＝4
	    //比用i＝1能节省几次检查！
        for(i=4; i<n; i++) {
            if(is_lucky(i)) {
                if(n%i==0) {
                    printf("YES\n");
                    return 0;
                }
            }
        }
    }
    printf("NO\n");
    return 0;
}
