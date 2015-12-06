#include<stdio.h>
int main() {
    int n,k;
    scanf("%d%d",&n,&k);
    int odds=0;
    int evens=0;
    while(1) {
        int a;
        if(scanf("%d",&a)==EOF) {
            break;
        } else {
            if(a%2==0) {
                evens++;
            } else {
                odds++;
            }
        }
    }
    printf("2s=%d\n",evens);
    printf("1s=%d\n",odds);
    if((n-k)%2==0) {
        evens-=(n-k)/2;
        odds-=(n-k)/2;
	if(evens<0) odds+=evens;
	if(odds<0) evens+=odds;
    } else {
        evens-=((n-k)/2+1);
        odds-=(n-k)/2;
	if(evens<0) odds+=evens;
	if(odds<0) evens+=odds;
    }
    printf("2s=%d\n",evens);
    printf("1s=%d\n",odds);

    if(odds%2==0) {
	    printf("Daenerys\n");
    }else {
	    printf("Stannis\n");
    }
    return 0;
}
