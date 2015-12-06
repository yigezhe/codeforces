//有很多俄罗斯背景！
//warriors士兵，魔兽争霸中就有这种！
//可能我以后都没有时间玩游戏了！
//但如果有时间，我会玩一下正版的魔兽争霸！
//第一感觉这是一个图论问题！
//我用广度优先搜索来处理
//可能时间超时了！
/*interface*/
/*interface implementation*/
/*client*/
#include<stdio.h>
#define N 4000+1
#define MIN 3*N
int triple[3];
int min_triple[3];
int min;
int n,m;
int map[N][N];
int used[N];
int recognition(int a,int b,int c) {
    int i;
    int counter=0;
    for(i=0; i<n; i++) {
        if(i!=a && i!=b && map[c][i]==1) {
            counter++;
        }
    }
    for(i=0; i<n; i++) {
        if(i!=a && i!=c && map[b][i]==1) {
            counter++;
        }
    }
    for(i=0; i<n; i++) {
        if(i!=b && i!=c && map[a][i]==1) {
            counter++;
        }
    }
    return counter;
}
void dfs(int pos) {
    int i;
    if(pos==0) {
        //初始阶段所有的都没有用过！
        for(i=0; i<n; i++) {
            triple[pos]=i;
            used[i]=1;
            dfs(pos+1);
            triple[pos]=0;
            used[i]=0;
        }
    } else if(pos>=3) {
        //这里总是可以有很多有趣的创造！加油！何伟伟！
	/*
        for(i=0; i<3; i++) {
            printf(" %d",triple[i]);
        }
        printf("\n");
	*/
        int rec=recognition(triple[0],triple[1],triple[2]);
	if(rec<min) {
		min=rec;
		min_triple[0]=triple[0];
		min_triple[1]=triple[1];
		min_triple[2]=triple[2];
	}

    } else if(pos==1) {
        for(i=0; i<n; i++) {
            //当前的士兵要认识前一个已经选择的士兵
            if(!used[i] && map[triple[pos-1]][i]==1) {
                triple[pos]=i;
                used[i]=1;
                dfs(pos+1);
                triple[pos]=0;
                used[i]=0;
            }
        }
    } else if(pos==2) {
        for(i=0; i<n; i++) {
            //当前的士兵要认识前一个已经选择的前两个士兵
            if(!used[i] && map[triple[pos-1]][i]==1 && map[triple[pos-2]][i]==1) {
                triple[pos]=i;
                used[i]=1;
                dfs(pos+1);
                triple[pos]=0;
                used[i]=0;
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

    min=MIN;
    dfs(0);
    if(min==MIN) {
	    printf("-1\n");
    }else {
	    //printf("(%d,%d,%d)-",min_triple[0],min_triple[1],min_triple[2]);
	    printf("%d\n",min);
    }
    return 0;
}
