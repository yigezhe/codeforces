#include<stdio.h>
#define N 100+5
int main() {
    char sum[N];
    scanf("%s",sum);
    char num[N];
    int i,j=0,k;
    for(i=0; sum[i]!='\0'; i++) {
        if(sum[i]!='+') {
            num[j]=sum[i];
            j++;
        }
    }
    //对num进行排序！
    /*
    for(i=0; i<j; i++) {
	    printf("%2c",num[i]);
    }
    printf("\n");
    */
    for(i=0; i<j; i++) {
        for(k=i+1; k<j; k++) {
            if(num[i]>=num[k]) {
                int tmp=num[i];
                num[i]=num[k];
                num[k]=tmp;
            }
        }
    }
    /*
    for(i=0; i<j; i++) {
	    printf("%2c",num[i]);
    }
    printf("\n");
    */
    k=0;
    for(i=0; sum[i]!='\0'; i++) {
        if(sum[i]!='+') {
            sum[i]=num[k];
            k++;

        }
    }
    printf("%s\n",sum);
    return 0;
}
