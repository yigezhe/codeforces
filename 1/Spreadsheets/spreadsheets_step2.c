#include<stdio.h>
//这个转换遇到阻碍！
void n2AA(int n) {
    while(1) {
        int a=n%26;
        int b=n/26;
	if(a>0) {
            printf("%c",a-1+'A');
        }else {
		//a==0;
		if(b==1) printf("Z");
		if(b==0) break;
        }
	n=b;
    }
    printf("\n");
}


int main() {
    int n;
    for(n=1; n<=100; n++) {
        printf("%d: ",n);
        n2AA(n);
    }

    return 0;
}
