//有很多俄罗斯背景！
//warriors士兵，魔兽争霸中就有这种！
//可能我以后都没有时间玩游戏了！
//但如果有时间，我会玩一下正版的魔兽争霸！
//第一感觉这是一个图论问题！
//我用广度优先搜索来处理
/*interface*/
/*interface implementation*/
/*client*/
#include<stdio.h>
#define N 4000+1
int triple[3];
int n,m;
int map[N][N];
int used[N];
void dfs(int pos) {
    int i;
    if(pos==0) {
	    //初始阶段所有的都没有用过！
        for(i=0; i<n; i++) {
            triple[pos]=i;
	    used[i]=1;
            dfs(pos+1);
            triple[pos]=0;
	    //used[i]=0;
        }
    } else if(pos>=3) {
        //这里总是可以有很多有趣的创造！加油！何伟伟！
        for(i=0; i<3; i++) {
            printf(" %d",triple[i]);
        }
        printf("\n");

    } else {
        for(i=0; i<n; i++) {
            if(!used[i] && map[triple[pos-1]][i]==1) {
                triple[pos]=i;
		used[i]=1;
                dfs(pos+1);
                triple[pos]=0;
		//used[i]=0;
            }
        }
    }
}
int main() {
    scanf("%d%d",&n,&m);
    int i,j;
    for(i=0; i<N; i++) {
	    used[i]=0;
    }
    for(i=0; i<N; i++) {
        for(j=0; j<N; j++) {
            map[i][j]=0;
        }
    }
    for(i=0; i<m; i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        map[a][b]=1;
        map[b][a]=1;
    }

    dfs(0);
    return 0;
}
