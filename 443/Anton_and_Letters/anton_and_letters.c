#include<stdio.h>
#define N 256+1
int main() {
    int count[N];
    int i;
    for(i=0; i<N; i++) {
        count[i]=0;
    }
    while(1) {
        char a=getchar();
        if(a=='}') {
            break;
        } else if(a=='{') {
        } else if(a==',') {
        } else if(a==' ') {
        } else {
            count[(int)a]=1;
        }
    }
    int distinct=0;
    for(i=0; i<N; i++) {
        if(count[i]==1) {
            distinct++;
        }
    }
    printf("%d\n",distinct);
    return 0;
}
