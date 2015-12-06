#include<stdio.h>
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    int teams=0;
    while(1) {
        if(n>=1 && m>=2) {
            n-=1;
            m-=2;
            teams++;
        } else {
            if(n>=2 && m==1) {
            n-=2;
            m-=1;
                teams++;
            }
	    else {
		    break;
	    }
        }
    }
    printf("%d\n",teams);
    return 0;
}
