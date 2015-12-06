//前一个比后一个高，他将获取能量
//前一个比后一个低，他需要花费能量
//前一个和后一个相等，他不用花费，也无法获取！
//-2+1+1-2
//我的思考时，例子一只需花3个美元就可以？
//这里还有一个隐含高度0
//0 3 4 3 2 4
//-3 -1 1 1 -2
//想法一，模拟，想法二，相加就可以！
/*interface*/
/*interface implementation*/
/*client*/
#include<stdio.h>
#define N 100001
int main() {
	int n;
	scanf("%d",&n);
	int i;
	int h[N];
	for(i=0;i<n;i++) {
		scanf("%d",&h[i]);
	}
	//这里实现想法二！
	int height_sum=0;
	height_sum+=(0-h[0]);
	for(i=0;i<n-1;i++) {
		height_sum+=(h[i]-h[i+1]);
	}
	if(height>=0) printf("0\n");
	else printf("%d\n",-height_sum);

	return 0;
}
