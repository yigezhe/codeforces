#include<stdio.h>
//这个转换遇到阻碍！
void n2AA(int n,char* AA,int* size) {
    //n=26ok!
    //n=52 B
    //n=52 AZ
    //AZ,BZ,CZ,26+26,26*2+26,26*3+26
    while(1) {
        int a=n%26;
        //a=0;b=2
        if(a>0) {
            //printf("%c",a-1+'A');
            //添加这个字符！
	    int i;
            for(i=(*size); i>0; i--) {
                *(AA+i)=*(AA+i-1);
            }
            AA[0]=a-1+'A';
            (*size)++;
            AA[*size]='\0';
        } else {
            //a==0;
            //if(b==1) { printf("Z"); break;}
            //printf("Z");
	    int i;
            for(i=(*size); i>0; i--) {
                *(AA+i)=*(AA+i-1);
            }
            AA[0]='Z';
            (*size)++;
            AA[*size]='\0';

            n=n-26;
        }
        n=n/26;
        if(n==0) break;
    }
}
int main() {
    int n;
    char AA[1000];
    for(n=1; n<=1000; n++) {
	    if(n%8==0) printf("\n");
        printf(" %d: ",n);
    int size=0;
    AA[size]='\0';

        n2AA(n,AA,&size);
    printf("%s",AA);
    }

    return 0;
}
