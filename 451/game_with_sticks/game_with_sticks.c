#include<stdio.h>
int min(int a,int b) {
	if (a>b) {
		return b;
	} else {
		return a;
	}
}
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    int x=min(m,n);
    if(x%2==0) {
        printf("Malvika\n");
    } else {
        printf("Akshat\n");
    }
    return 0;
}
