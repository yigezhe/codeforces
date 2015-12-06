//题目描述有点长！
//和佩佩在一起的生活一定是充满未知和奇妙的！
//有n个人参加比赛！
//每一个学生都有一个diploma
//分成三个等级！
/*interface*/
/*interface implementation*/
/*client*/
#include<stdio.h>
int main() {
    int n;
    scanf("%d",&n);
    int max1,min1;
    int max2,min2;
    int max3,min3;
    scanf("%d%d",&min1,&max1);
    scanf("%d%d",&min2,&max2);
    scanf("%d%d",&min3,&max3);
    int min_sum=min1+min2+min3;
    if(min_sum==n) {
        printf("%d %d %d\n",min1,min2,min3);
    } else if(min_sum<n) {
        int diff1=n-min_sum;
        if(diff1<=max1-min1) {
            printf("%d %d %d\n",min1+diff1,min2,min3);
        } else {
            //int diff2=n-min_sum-max1+min1;
            int diff2=diff1-max1+min1;
            if(diff2<=max2-min2) {
                printf("%d %d %d\n",max1,min2+diff2,min3);
            } else {
                //int diff3=n-min_sum-max1+min1-max2+min2;
                int diff3=diff2-max2+min2;
                if(diff3<=max3-min3) {
                    printf("%d %d %d\n",max1,max2,min3+diff3);
                } else {
                    printf("还有多余的没有分配出去\n");
                }

            }
        }
    } else {
        printf("这一种情况题目中保证不出现\n");
    }
    return 0;
}
