//直接实现就可以！
//直接实现有可能超时,而且还有一个问题100000位的整数是无法在long long数据类型中保存的！
//想法二就是找零就可以！找到第一个零，然后去掉它就可以！
/*interface*/
/*interface implementation*/
/*client*/
#define N 100000+1
#include<stdio.h>

void print(char *a,int n) {
    int i;
    for(i=0; i<n; i++) {
        printf("%c",a[i]);
    }
}
long long value(char * a,int n) {
    int i;
    long long product=0;
    for(i=0; i<n; i++) {
        product=product*2+(a[i]-'0');
    }
    return product;
}
int main() {
    char binary[N];
    int n=0;
    while(1) {
        char ch=getchar();
        if(ch==EOF || ch=='\n') break;
        else {
            binary[n]=ch;
            n++;
        }
    }
    char max_binary[N];
    long long max=-1;
    int i,j,k;
    for(i=0; i<n; i++) {
        char new_binary[N];
        k=0;
        for(j=0; j<n; j++) {
            if(j!=i) {
                new_binary[k]=binary[j];
                k++;
            }
        }
        //print(new_binary,k);
        long long v= value(new_binary,k);
        //printf("------%lld\n",v);
        if(v>max) {
            max=v;
            for(j=0; j<k; j++) {
                max_binary[j]=new_binary[j];
            }
        }
        //print(max_binary,k);
	//printf("\n----------\n");
    }
    if(max==0) printf("0\n");
    else {
        for(i=0; i<n-1; i++) {
            printf("%c",max_binary[i]);
        }
        printf("\n");
    }
    return 0;
}
