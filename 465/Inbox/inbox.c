//inbox就是在邮箱盒子里！
//这就是一个实际的邮箱使用问题！
//先任选一个，再回到主界面，再任选一个,对相邻的需要三次操作，对不相邻的需要三次操作！
//先任选一个，向前翻一个,这对相邻的只需两次操作！对不相邻的，由不相邻的距离决定！
//如果距离是n，则需要n+1次操作！
//这样看来要让操作数最小，
//则分成两种情况处理
//第一对相邻未读邮件，采取办法二，用下一个或上一个来操作
//第二对不相邻未读邮件，采取办法一，采用回到主界面办法处理！
/*interface*/
/*interface implementation*/
/*client*/
#include<stdio.h>
#define N 1000+1
int main() {
    int n;
    scanf("%d",&n);
    int letter[N];
    //1代表未读
    //0代表已读
    int i;
    for(i=0; i<n; i++) {
        scanf("%d",&letter[i]);
    }
    i=0;
    //前面的0不用统计
    while(letter[i]==0 && i<n) {
        i++;
    }
    int new_n=n-1;
    //后面的0不用统计
    while(letter[new_n]==0 && new_n>=0) {
        new_n--;
    }
    //printf("%d %d\n",i,new_n);

    int operator=0;
    while(i<=new_n) {
        while(letter[i]==1 && i<=new_n) {
            i++;
            operator++;
        }
        int is_read=0;
        while(letter[i]==0 && i<=new_n) {
            is_read=1;
            i++;
        }
        if(is_read)operator++;
	else break;
        while(letter[i]==1 && i<=new_n) {
            i++;
            operator++;
        }
    }
    printf("%d\n",operator);
    return 0;
}
