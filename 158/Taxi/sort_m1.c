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
        for(j=i+1; j<n; j++) {
            if(s[i]<s[j]) {
                int tmp=s[i];
                s[i]=s[j];
                s[j]=tmp;
            }
        }
    }
    for(i=0; i<n; i++) {
        printf(" %d",s[i]);
    }
    printf("\n");

    return 0;
}
