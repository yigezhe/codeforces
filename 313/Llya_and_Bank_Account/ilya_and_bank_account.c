//这里有很多俄式英语！
//一个聪明的狮子，有自己的银行账户！
//这个狮子可以不删除自己的账户中的末尾和倒数第二位！
//对负债，删除数字是好的！
/*interface*/
/*interface implementation*/
/*client*/
#include<stdio.h>
int main() {
    int n;
    scanf("%d",&n);
    if(n>=0) {
        printf("%d\n",n);
    } else {
        int n1=n/10;
        int n2=(n/100)*10+n%10;
	//printf("%d %d\n",n1,n2);
        if(n1>n2) printf("%d\n",n1);
        else printf("%d\n",n2);
    }
    return 0;
}
