#include<stdio.h>
#define MAX_N 30000
int main() {
	int n,t;
	int i;
	int a[MAX_N];
	//30000*30000*4byte=3-600-000-000byte=3.6G
	scanf("%d%d",&n,&t);
	t=t-1;//我从零开始计算，题目中从一开始计算，这里算是做出一个转换！
	//printf("n=%d,t=%d\n",n,t);
	for(i=0;i<n-1;i++) {
		scanf("%d",&a[i]);
		//printf("%d->%d\n",i,i+a[i]);
	}
	//我用广度优先搜索
	int queue[2*MAX_N];
	int visited[MAX_N];
	int start=0;int end=0;
	queue[end]=0;
	//一加入就代表已经访问过了！
	visited[queue[end]]=1;
	end++;
	while(start<end) {
		//这里我可以实时查看queue的内容！
		/*
		for(i=start;i<end;i++) {
			printf(" %d",queue[i]);
		}
		printf("\n");
		*/
		int top=queue[start];
		start++;
		if (top==t) {
			printf("YES");
			return 0;
		}
		for(i=0;i<n;i++) {
			if(i==top && !visited[i+a[i]]){
				queue[end]=i+a[i];
				visited[queue[end]]=1;
				end++;
			}
		}
	}
	printf("NO");
	return 0;
}
