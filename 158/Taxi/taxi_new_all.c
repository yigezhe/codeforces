#include<stdio.h>
#define N 100000+5
int main() {
    int n;
    scanf("%d",&n);
    int s[N];
    int i,j;
    int count=0;
    for(i=0; i<n; i++) {
        scanf("%d",&s[i]);
    }

    for(i=0; i<n; i++) {
        printf("%2d",s[i]);
    }
    printf("\n");
    //先拍一个序！
    for(i=0; i<n; i++) {
        for(j=i+1; j<n; j++) {
            if(s[j]>s[i]) {
                int tmp=s[i];
                s[i]=s[j];
                s[j]=tmp;
            }
        }
    }
    for(i=0; i<n; i++) {
        printf("%2d",s[i]);
    }
    printf("\n");

    printf("去掉4，并统计\n");
    for(i=0; i<n; i++) {
        if(s[i]==4) {
            s[i]=0;
            count++;
        }
    }
    for(i=0; i<n; i++) {
        printf("%2d",s[i]);
    }
    printf("\n");

    //把所有的1，3对取消！
    for(i=0; i<n; i++) {
        for(j=i+1; j<n; j++) {
            if(s[i]!=0 && s[j]!=0) {
                if(s[i]==3 && s[j]==1) {
                    s[i]=0;
                    s[j]=0;
                    count++;
                }
            }
        }
    }
    printf("去掉3,1，并统计\n");
    for(i=0; i<n; i++) {
        printf("%2d",s[i]);
    }
    printf("\n");

    //剩下的3已经无法配对了！
    for(i=0; i<n; i++) {
        if(s[i]!=0 && s[i]==3) {
            s[i]=0;
            count++;
        }

    }
    printf("去掉3，并统计\n");
    for(i=0; i<n; i++) {
        printf("%2d",s[i]);
    }
    printf("\n");

    //把所有的2，2对取消！
    for(i=0; i<n; i++) {
        for(j=i+1; j<n; j++) {
            if(s[i]!=0 && s[j]!=0) {
                if(s[i]==2 && s[j]==2) {
                    s[i]=0;
                    s[j]=0;
                    count++;
                }
            }
        }
    }

    printf("去掉2,2，并统计\n");
    for(i=0; i<n; i++) {
        printf("%2d",s[i]);
    }
    printf("\n");
    //把所有的1,1，2对取消！
    int k;
    for(i=0; i<n; i++) {
        for(j=i+1; j<n; j++) {
            for(k=j+1; k<n; k++) {
                if(s[i]!=0 && s[j]!=0 && s[k]!=0) {
                    if(s[i]==2 && s[j]==1 && s[k]==1) {
                        s[i]=0;
                        s[j]=0;
                        s[k]=0;
                        count++;
                    }
                }
            }
        }
    }
    printf("去掉2,1,1，并统计\n");
    for(i=0; i<n; i++) {
        printf("%2d",s[i]);
    }
    printf("\n");

    //把2，1配对
    for(i=0; i<n; i++) {
        for(j=i+1; j<n; j++) {
            if(s[i]!=0 && s[j]!=0) {
                if(s[i]==2 && s[j]==1) {
                    s[i]=0;
                    s[j]=0;
                    count++;
                }
            }
        }
    }
    printf("去掉2,1，并统计\n");
    for(i=0; i<n; i++) {
        printf("%2d",s[i]);
    }
    printf("\n");

//剩下的2已经无法配对了！
    for(i=0; i<n; i++) {
        if(s[i]!=0 && s[i]==2) {
            s[i]=0;
            count++;
        }

    }

    printf("去掉2，并统计\n");
    for(i=0; i<n; i++) {
        printf("%2d",s[i]);
    }
    printf("\n");

    int times=0;
    for(i=0; i<n; i++) {
        if(s[i]==1) {
            s[i]=0;
            times++;
        }
        if(times==4) {
            count++;
            times=0;
        }
    }
    printf("去掉1，并统计\n");
    for(i=0; i<n; i++) {
        printf("%2d",s[i]);
    }
    printf("\n");


    if(times!=0) count++;
    printf("%d\n",count);
    return 0;
}
