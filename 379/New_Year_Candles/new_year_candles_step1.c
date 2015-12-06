#include<stdio.h>
int main() {
	int a,b;
	scanf("%d%d",&a,&b);
	//策略很简单，一个蜡烛一个蜡烛地烧，
	//凑够b个蜡烛，总蜡烛就加一，直到所有的总蜡烛烧完！
	int count=a;
	while(a!=0) {
		count+=(a/b);
		a=a/b;
	}
	printf("%d\n",count);
	return 0;
}
