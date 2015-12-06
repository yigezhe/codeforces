#include<stdio.h>
#define N 1000+5
int abs(int a) {
    if(a<0) return -a;
    else return a;
}
int main() {
    int n;
    scanf("%d",&n);
    char origin[N];
    scanf("%s",origin);
    char secret[N];
    scanf("%s",secret);
    int i;
    int moves=0;
    for(i=0; i<n; i++) {
        //printf("i=%d\n",i);
        int a=origin[i]-'0';
        int b=secret[i]-'0';
        int each=0;
        each=abs(b-a);
        if(10-each<each) {
		//这是一种观察！
            each=10-each;
        }
        //printf("each=%d\n",each);
        moves+=each;
        //printf(" ========= \n");
    }
    printf("%d\n",moves);
    return 0;
}
