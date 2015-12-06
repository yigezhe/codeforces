#include<stdio.h>
#define N 100+1
int main() {
    char a[N];
    int i;
    for(i=0; i<N; i++) {
        char c=getchar();
        if(c=='\n') break;
        else a[i]=c;
    }
    //printf("i=%d\n",i);
    int j;
    for(j=0; j<i; j++) {
        char c=getchar();
        if(c==EOF) break;
        else {
            if(c!=a[j]) printf("1");
            else printf("0");
        }
    }
    printf("\n");
    return 0;
}
