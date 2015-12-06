//我有点感受到了，竞赛的好处！
#include<stdio.h>
#include<string.h>
#define D 6+1
int main() {
    char digit[D];
    //以字符串的形式读入整数！
    scanf("%s",digit);
    //printf("digit = %s\n",digit);
    int digit_n=strlen(digit);
    //printf("digit n = %d\n",digit_n);
    int count[D];
    int count2[D];
    int i;
    for(i=0; i<digit_n; i++) {
        count[i]=digit[i]-'0';
    }
    /*
    for(i=0; i<digit_n; i++) {
        printf(" %d",count[i]);
    }
        printf("\n");
    */

    //这里计算数量！
    int counter=0;
    for(i=0; i<digit_n; i++) {
        count2[i]=count[i];
    }
    while(1) {
        //找到最小的！
        int min=10;
        for(i=0; i<digit_n; i++) {
            if(count2[i]!=0 && count2[i]<min) {
                min=count2[i];
            }
        }
        if(min==10) break;
        else {
            counter+=min;
        }
        for(i=0; i<digit_n; i++) {
            if(count2[i]!=0) {
                count2[i]-=min;
            }
        }

    }
    printf("%d\n",counter);

    while(1) {
        //找到最小的！
        int min=10;
        for(i=0; i<digit_n; i++) {
            if(count[i]!=0 && count[i]<min) {
                min=count[i];
            }

        }
        //printf("min = %d\n",min);
        if(min==10) break;
        else {
            int start=0;
            //把前面的零忽略掉！
            while(start<digit_n && count[start]==0) {
                start++;
            }
            //printf("start = %d\n",start);
            for(i=0; i<min; i++) {
                int j;
                printf(" ");
                for(j=start; j<digit_n; j++) {
                    if(count[j]>0) {
                        printf("1");
                    } else {
                        printf("0");
                    }
                }
            }
            for(i=0; i<digit_n; i++) {
                if(count[i]!=0) {
                    count[i]-=min;
                }
            }
        }
    }
    return 0;
}//太棒了，何伟伟你的发现很出色，程序给我展示了一个格外不同的世界。
//继续加油何伟伟！
