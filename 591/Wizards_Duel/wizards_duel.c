/*interface*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
/*interface implementation*/
/*client*/
int main() {
	//he young wizard isn't good at math, so he asks you to calculate the distance from his position to the place of the second meeting of the spell impulses
	//这个问题有问题。
	//我计算的是从哈利波特的位置出发得到的距离而不是从哈利波特的对手
	//出发得到的距离！
	//output要求
	// the distance from the end of the corridor, where Harry is located, to the place of the second meeting of the spell impulses. 
	// 两个要求不统一！
    int l,p,q;
    scanf("%d%d%d",&l,&p,&q);
    printf("%f",1.0*p*l/(p+q));
    return 0;
}
