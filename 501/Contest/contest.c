//还是不要参加codeforces的比赛项目，因为我晚上真的没有精力去比赛！
//我会这样一直坚持训练下去！
/*interface*/
/*interface implementation*/
/*client*/
int max(int a,int b) {
    if(a>b) return a;
    else return b;
}
int points(int p,int t) {
    return max(3*p/10,p-(p/250)*t);
}
#include<stdio.h>
int main() {
    int a,b,c,d;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    //a表示misha获得的分数
    //b表示vasya获得的分数
    //misha花了c分钟解决问题
    //vasya花了d分钟解决问题
    //现在的程序需要更多的结构化编程！
    int misha=points(a,c);
    int vasya=points(b,d);
    if(misha>vasya) {
	    printf("Misha\n");
    }else if(misha<vasya) {
	    printf("Vasya\n");
    }else {
	    //紧咬在一起就是平分！
	    printf("Tie\n");
    }
    return 0;
}
