#include<stdio.h>
int main() {
    long long n;
    scanf("%lli",&n);
    int count=0;
    while(n!=0) {
	    //先统计出所有的幸运数字有多少个！
	    //这里4和7是幸运数字！
        if(n%10==4) {
		count++;
        }
	if(n%10==7) {
		count++;
        }
	n=n/10;
    }
    if(count==0) {
	printf("NO\n");
		return 0;
    }
    //看看count是不是幸运数字！
    while(count!=0) {
	    //先统计出所有的幸运数字有多少个！
	    //这里4和7是幸运数字！
        if(count%10==4) {
		count=count/10;
        }else if(count%10==7) {
		count=count/10;
        } else {
		printf("NO\n");
		return 0;
	}
    }

    printf("YES\n");
    return 0;
}

