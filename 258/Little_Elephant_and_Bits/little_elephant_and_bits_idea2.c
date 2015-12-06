//直接实现就可以！
//直接实现有可能超时
//想法二就是找零就可以！找到第一个零，然后去掉它就可以！
/*interface*/
/*interface implementation*/
/*client*/
#define N 100000+1
#include<stdio.h>
int main() {
    char binary[N];
    int n=0;
    while(1) {
        char ch=getchar();
        if(ch==EOF) break;
        else {
            binary[n]=ch;
            n++;
        }
    }
    //这里的binary中最后一个元素是\n！
    int i=0;
    while(binary[i]=='0') {
        i++;
    }
    if(i>=1) {
        //n-1就是剪掉后面的那个换行符！
        //printf("i=%d\n",i);
        if(i==n-1) {
            //全部都是零！
            printf("0\n");
        } else {
            int j;
            for(j=i; j<n; j++) {
                printf("%c",binary[j]);
            }
            //printf("\n");
        }
    } else {
        int find=0;
        for(i=0; i<n; i++) {
            if(binary[i]=='0') {
                find=1;
                break;
            }
        }
        if(find) {

            int first=1;
            for(i=0; i<n; i++) {
                if(first && binary[i]=='0') {
                    //对出现的第一个零不打印就可以！
                    first=0;
                } else {
                    printf("%c",binary[i]);
                }
            }
        } else {
		//考虑到有换行符，所以这里是n-2,而不是n-1
            for(i=0; i<n-2; i++) {
                printf("1");
            }
            printf("\n");
        }
    }
    return 0;
}
