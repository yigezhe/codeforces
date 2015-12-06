//在中国68是吉利数字，4不是吉利数字！
//我能够快速实现了！ 加油！
/*interface*/
/*interface implementation*/
/*client*/
#include<stdio.h>
#define N 50+1
int main() {
    //n是偶数？
    //想法直接按要求实现就可以！
    int n;
    scanf("%d",&n);
    char ticket[N];
    scanf("%s",ticket);
    int i;
    int sum_left=0;
    int lucky_left=1;
    for(i=0; i<n/2; i++) {
        if(ticket[i]=='4' || ticket[i]=='7') {
            sum_left+=ticket[i];
        } else {
            lucky_left=0;
            break;
        }
    }
    int sum_right=0;
    int lucky_right=1;
    for(i=n-1; i>=n/2; i--) {
        if(ticket[i]=='4' || ticket[i]=='7') {
            sum_right+=ticket[i];
        } else {
            lucky_right=0;
            break;
        }
    }
    if(lucky_left && lucky_right && sum_left==sum_right) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}
