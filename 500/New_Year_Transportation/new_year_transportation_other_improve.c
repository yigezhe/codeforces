#include<stdio.h>
int main() {
    int n,t;
    scanf("%d%d",&n,&t);
    int i=1;
    while(i<t) {
        int a;
        scanf("%d",&a);
        i=i+a;
	printf("i=%d\n",i);
    }
    if(i==t) {
        printf("YES");
    } else {
        printf("NO");
    }
    return 0;
}
