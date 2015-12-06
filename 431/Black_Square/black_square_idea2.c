//submit ok!
//没时间参加比赛，我觉得还是坚持好早上的练习。
//等我有时间参加比赛了，我一定会取得更好的成绩！
//触屏手机，就是直接翻译的！
//四条竖着的条子！
//算法也可以检测游戏的可玩性。不要超过人的反应极限！
//这些竖着的条子里会出现黑色的小方格！
//在一秒之内点黑色的方格，让其消失！
//每一次点击消耗ai卡路里能量，在第i条子上！
//这相当于不同条子上有不同的移动距离，要完成不同的工作，完成这些都需要消耗能量！
/*interface*/
/*interface implementation*/
/*client*/
#include<stdio.h>
int main() {
	int a[5];
	scanf("%d%d%d%d",&a[1],&a[2],&a[3],&a[4]);
	//getchar();//去掉换行符号！//这个不需要了！
	//不需要建立数组的方式！
	int calories=0;
	while(1){
		char ch=getchar();
		if(ch==EOF) break;
		//这个处理是必须的！有次可以推断，服务器上的文件应该是\nEOF结尾方式！
		if(ch=='\n') continue;
		int num=ch-'0';
		calories+=a[num];
	}
	printf("%d\n",calories);
	return 0;
}
