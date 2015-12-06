//精力不够，该睡觉了！
//这个问题，要求对实现的细节做出精确的处理！
//厉害，这有可能是一个寻找边界的算法！
/*interface*/
/*interface implementation*/
/*client*/
#include<stdio.h>
#define N 100000+4
int n;
int h[N];
int destroy() {
    //不需要再去破坏了！
    int find=0;
    for(i=0; i<=n; i++) {
        if(h[i]!=0) {
            find=1;
            break;
        }
    }
    if(!find) return 0;

    int first=0;
    int second=-1;
    //这里一个first和一个second就形成了一个山！
    //我们需要一个山一个山地处理！
    while(first<=n) {
        first=second+1;
        int i;
        for(i=second+1; i<=n; i++) {
            if(h[i]!=0) {
                first=i;
                break;
            }
        }
        second=first+1;
        for(i=second; i<=n; i++) {
            if(h[i]==0) {
                second=i-1;
                break;
            }
        }
        if(first<=second) {
            for(i=first; i<last-1; i++) {
                if(h[i]>=h[i+1]) h[i+1]=h[i+1]-1;
                else h[i+1]=h[i]-1;
            }
            h[first]=0;
            h[second]=0;
            return 1;
        }
    }
}
void print(int *a,int size) {
    int i;
    for(i=0; i<size; i++) {
        printf(" %d",a[i]);
    }
    printf("\n");
}
int main() {
    scanf("%d",&n);
    //我去建立一个map[10^5][10^9]不现实，
    //如果可以建立，我就可以在map中寻找边界，删除边界！
    //第一座塔肯定没有内部元素！
    //第二座塔如果高度为1，则没有内部元素，如果高度为2，
    //那么第一座塔的高度决定了第二座塔有多少个内部元素！
    //h1>=h2,则第二座塔有h2-1个内部元素！
    //h1<h2,则第二座塔有h1-1个内部元素！
    //最后一个塔没有内部元素！
    //有思路了！
    int i;
    for(i=0; i<n; i++) {
        scanf("%d",&h[i+1]);
    }
    h[0]=0;
    h[n]=0;
    int counter=0;
    while(destroy()==1) {
        print(h,n);
        counter++;
    }
    printf("%d",counter);

    return 0;
}
