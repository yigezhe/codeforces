#include<stdio.h>
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    int day=n;
    int tmp=n;
    while(tmp>=m) {
	    day+=tmp/m;
	    tmp=tmp/m+tmp%m;
    }
    printf("%d\n",day);
    return 0;
}
