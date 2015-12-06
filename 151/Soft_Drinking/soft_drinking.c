//做力所能及的事情非常重要！
//这一个过程中是你自信心扎实积累的过程！
/*interface*/
/*interface implementation*/
int min(int a,int b) {
	if(a>b) return b;
	else return a;
}
int min3(int a,int b,int c) {
	return min(min(a,b),c);
}
/*client*/
#include<stdio.h>
int main() {
	int n,k,l,c,d,p,nl,np;
	scanf("%d%d%d%d%d%d%d%d",&n,&k,&l,&c,&d,&p,&nl,&np);
	//n 朋友的个数
	//k 饮料的瓶数！
	//l 每一瓶饮料液体的容量
	//c 长条形面包的个数
	//d 一个面包被切成的片数
	//p 盐的重量
	//nl 每一个吐司需要的液体量
	//每一个吐司还需要一片面包！
	//np 每一个吐司需要的盐的重量！
	//k*l / nl
	//c*d / 1
	//p/np
	//min(k*l / nl, c*d / 1, p/np)
	int total=min3((k*l)/nl,c*d,p/np);
	int each=total/n;
	printf("%d",each);
	return 0;
}
