#include<stdio.h>
//这个转换遇到阻碍！
void n2AA(int n) {
	//n=26ok!
	//n=52 B
	//n=52 AZ
	//AZ,BZ,CZ,26+26,26*2+26,26*3+26
    while(1) {
        int a=n%26;
	//a=0;b=2
	if(a>0) {
            printf("%c",a-1+'A');
        }else {
		//a==0;
		//if(b==1) { printf("Z"); break;}
		printf("Z");
		n=n-26;
        }
        n=n/26;
		if(n==0) break;
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
