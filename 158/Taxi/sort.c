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
    int order=0;
    for(i=0; i<n && !order; i++) {
	    int change=0;
        for(j=n-1; j>i; j--) {
		//后面的比前面的大，就更换一次！
            if(s[j]>s[j-1]) {
		    change=1;
                int tmp=s[j];
                s[j]=s[j-1];
                s[j-1]=tmp;
            }
        }
	if (!change) {
		//这里也可以用break，不过我这里想表明的是，如果没有改变说明数组已经排列好了，我们可以退出循环了！
		order=1;
	}
    }
    for(i=0; i<n; i++) {
        printf(" %d",s[i]);
    }
    printf("\n");

    return 0;
}
