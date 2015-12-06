//删掉一个ak，其他ak应该还留着！
//这里的策略是尽可能删除孤立元素！
//例子二，删除3和1
//例子一，删除2的到2分，1也会消失！
//3+3
//1+3+3
//2+2+2+2+2=10
//可以排序！
//这个问题是递归式的，我先给出递归的解答。
//当然这个问题的规模使得递归变得速度很慢，但是
//我的想法是先实现这个最慢的想法，看看它在哪些数据面前超时，
//之后，我再想办法提高速度！
//想法一，应该是先给出所有的处理组合，看每一个组合下得到的分数
//找出最大的那个组合就可以！
/*interface*/
void recurision(int count) ;
/*interface implementation*/
void recurision(int count) {
    int i,j;
    for(i=0; i<n; i++) {
        //消除ai＋1，ai－1
        if(a[i]!=0) {
            int tmp=a[i];
	    int aj1[N];
	    int h1=0;
	    int aj2[N];
	    int h2=0;

            for(j=0; j<n; j++) {
                if(a[j]==a[i]+1) {
			aj1[h1]=j;
			h1++;
                    a[j]=0;
                }
                if(a[j]==a[i]-1) {
			aj2[h2]=j;
			h2++;

                    a[j]=0;
                }
            }

            a[i]=0;

            recurision(count+1);
	    //如何恢复？
            a[i]=tmp;
	    for(j=0;j<h1;j++) {
		    a[aj1[j]]=tmp+1;
	    }
	    for(j=0;j<h2;j++) {
		    a[aj2[j]]=tmp-1;
	    }

        }

    }

}
/*client*/
#include<stdio.h>
#define N 100000
int main() {
    int n;
    scanf("%d",&n);
    int a[N];
void recurision(int count) {

    return 0;
}
