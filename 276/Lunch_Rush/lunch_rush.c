//lunch rush紧急吃饭！
//grab some lunch蹭饭！
//三个兔子
//每一个队有k个单位时间来吃饭！
//ti吃饭的时刻！
//2 5 两个餐馆，5个时间单元
//3 3 3没有超过5，joy＝3
//4 5 5没有超过5，joy＝4
//最大joy＝4
//4 6 四个餐馆，6个时间单元
//5 8 8超过6，joy＝5-（8-6）＝3
//3 6 6不超过6，joy=3
//2 3 3不超过6，joy＝3
//2 2 2不超过6，joy＝2
//最大joy＝3
//1 5 一个餐馆，5个单位时间
//1 7 7超过5，joy＝1-（7-5）＝－1
/*interface*/
/*interface implementation*/
/*client*/
#define N 1000000001
#include<stdio.h>
int main() {
	int n,k;
	scanf("%d%d",&n,&k);
	int i;
	int max=(-N);
	for(i=0;i<n;i++) {
		int f,t;
		scanf("%d%d",&f,&t);
		int joy;
		if(t>k)joy=f-(t-k);
		else joy=f;
		if(joy>max) max=joy;
	}
	printf("%d\n",max);
	return 0;
}
