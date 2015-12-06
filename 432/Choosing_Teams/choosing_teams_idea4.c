//submit ok!
//这个思路太漂亮，太简洁了！
//把题意理解了，一起共同参加k次，而不是总共达到k次！
//想法三是给整个数组加k，然后统计有多少个小于等于5的！
//就是所有继续参加k次比赛，总比赛数还小于等于5次的所有队员召集在一起来分组！
//从这一点看，我建立队伍时，不用考虑谁参加比赛多，谁参加比赛少，只要符合上面条件的，
//我们就随机组合！
#include<stdio.h>
#define N 2000
int main() {
    int n,k;
    scanf("%d%d",&n,&k);
    int i;
    int y[N];
    int count=0;
    for(i=0; i<n; i++) {
        scanf("%d",&y[i]);
	y[i]+=k;
	if(y[i]<=5) count++;
    }
    int team=count/3;
    printf("%d\n",team);

    return 0;
}
