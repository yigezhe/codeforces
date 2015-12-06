//现在的想法是看看可以找到一个数学公式不！
#include<stdio.h>
#include<string.h>
#include<math.h>
#define N 1000000000
//#include<math.h>
int main() {
    int n;
    scanf("%d",&n);
    n=n-1;
    //1<=n<=10^9,n没有超过int的范围！
    //printf("%f\n",pow(2,31));
    char name[5][8];
    strcpy(name[0],"Sheldon");
    strcpy(name[1],"Leonard");
    strcpy(name[2],"Penny");
    strcpy(name[3],"Rajesh");
    strcpy(name[4],"Howard");
    //把0，1，2，3，4放入队列而不是把这些名字放入队列，把名字放入队列太费时间！
    //把n减到很小！
    //for(n=0;n<20;n++) {
    //n=40;
    int i=0;
    int last=0;
    int dn=0;
    //printf("n=%d\n",n);
    while(1){
	    //printf("dn=%d\n",dn);
	    dn+= (int)pow(2,i)*5;
	    i++;
	    if(dn<=n) { last=dn; }
	    else {break;}
    }
    n=n-last;
    //printf("n=%d\n",n);
    //printf("i-1=%d\n",i-1);

    int m=(int)pow(2,i-1);
    //printf("%d,%d\n",n,m);
    int namei=n/m;
    printf("%s\n",name[namei]);
    //我们最终需要的是
    //012340011122334400001111222233334444
    //n%5可以产生012340123401234
    //n/2%5可以产生00112233440011223344
    //n/3%5可以产生000111222333444000111222333444
    //n/4%5可以产生0000111122223333444400001111222233334444

    //012340011122334400001111222233334444
    //0~4,01234 n%5
    //5~15-1,0011223344 n/2%5 
    //15~35-1,00001111222233334444 n/4%5
    //35~75-1,0000000011111111222222223333333344444444 n/8%5
    //n在以上区间，用不同的公式就可以！
    //这里的％5可以取消！

    return 0;
}
