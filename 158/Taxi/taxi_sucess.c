#include<stdio.h>
#include<stdio.h>
#define MAX_N 100000
//最终还是用数学的办法解决了这个问题！
int main() {
    int n;
    scanf("%d",&n);
    int i;
    //想法来了，统计出4有多少个
    //1有多少个，2有多少个，3有多少个！然后只对剩下的进行处理！
    int s1=0;
    int s2=0;
    int s3=0;
    int s4=0;
    for(i=0; i<n; i++) {
        int s;
        scanf("%d",&s);
        if (s==1) s1++;
        else if (s==2) s2++;
        else if (s==3) s3++;
        else if (s==4) s4++;
    }
    int taxis=0;
    //printf("4:%d 3:%d 2:%d 1:%d taxis:%d\n",s4,s3,s2,s1,taxis);
    //4个的直接放入一个出租车内！
    taxis+=s4;
    s4=0;
    //printf("4:%d 3:%d 2:%d 1:%d taxis:%d\n",s4,s3,s2,s1,taxis);
    //3个的，就要配1
    taxis+=s3;
    if(s3>=s1) s1=0;
    else s1=s1-s3;
    s3=0;
    //printf("4:%d 3:%d 2:%d 1:%d taxis:%d\n",s4,s3,s2,s1,taxis);

    taxis+=s2/2;
    if(s2%2==1) {
        if(s1>=2) {
            taxis+=1;
            s2=0;
            s1=s1-2;
        } else {
            taxis+=1;
            s2=0;
            s1=0;
        }
    }

    taxis+=s1/4;
    if (s1%4!=0) {
        taxis+=1;
    }
    //这可能是个数学问题！
    printf("%d\n",taxis);
    return 0;
}
