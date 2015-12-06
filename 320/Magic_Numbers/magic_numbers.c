//首先有一个1，接下来是0个，一个，两个4
/*interface*/
/*interface implementation*/
/*client*/
#include<stdio.h>
int main() {
    int n;
    scanf("%d",&n);
    //从头开始处理，
    //需要建立一个数组来保存这个整数的各个数位！
    //从尾巴开始处理，我们需要先统计4，再统计1,可以不需要建立数组！
    //两种方法我都处理一下！
    int is_magic=1;
    while(n>0 ) {
        int counter=0;
        while(n%10==4 && n>0) {
            n/=10;
            counter++;
        }
        if(counter>2) {
            is_magic=0;
            break;
        }

	//printf("n=%d\n",n);
        if(n>0 && n%10!=1) {
            is_magic=0;
            break;

        }
	counter=0;
        while(n%10==1 && n>0) {
            n/=10;
	    counter++;
        }
	//4前面至少有一个1
	if(counter==0) {
            is_magic=0;
            break;
	}
	/*
	 *取消这个检查是合适的！
	//printf("n=%d\n",n);
        if(n>0 && n%10!=4) {
            is_magic=0;
            break;
        }
	*/
    }
    if(is_magic) printf("YES\n");
    else printf("NO\n");
    return 0;
}
