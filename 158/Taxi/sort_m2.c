#include<stdio.h>
int main() {
    int i,j;
    int s[5];
    s[0]=1;
    s[1]=5;
    s[2]=2;
    s[3]=3;
    s[4]=4;
    int n=5;
    for(i=0; i<n; i++) {
        printf(" %d",s[i]);
    }
    printf("\n");
    for(i=0; i<n; i++) {
        for(j=n-1; j>i; j--) {
		//后面的比前面的大，就更换一次！
            if(s[j]>s[j-1]) {
                int tmp=s[j];
                s[j]=s[j-1];
                s[j-1]=tmp;
            }
        }
    }
    for(i=0; i<n; i++) {
        printf(" %d",s[i]);
    }
    printf("\n");

    return 0;
}
