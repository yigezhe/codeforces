//判断奇偶数之间的差别？
//evenness是奇偶性的意思？
//平整度是什么？数组的平整度是什么？
/*interface*/
int abs(int  ) ;
/*interface implementation*/
int abs(int a) {
	if(a<0) return -a;
	else return a;
}
/*client*/
#include<stdio.h>
int main() {
	//统计有多少个奇数，有多少个偶数，相减就可以！
	int n;
	scanf("%d",&n);
	int even=0;
	int odd=0;
	int i;
	for(i=0;i<n;i++) {
		int a;
		scanf("%d",&a);
		if(a%2==0) even++;
		else odd++;
	}
	printf("%d\n",abs(even-odd));

	return 0;
}
