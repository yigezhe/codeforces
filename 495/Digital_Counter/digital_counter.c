/*interface*/
#include<stdio.h>
/*interface implementation*/
/*client*/
int main() {
	char number[3];
	scanf("%s",number);
	int good[10];
	//这是我总结出来的！
	good[0]=2;
	good[1]=7;
	good[2]=2;
	good[3]=3;
	good[4]=3;
	good[5]=4;
	good[6]=2;
	good[7]=5;
	good[8]=1;
	good[9]=2;
	printf("%d\n",good[number[0]-'0']*good[number[1]-'0']);
	return 0;
}
