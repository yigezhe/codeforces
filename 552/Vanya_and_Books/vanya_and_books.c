//10^9不允许我用数组来区分不同的书！
//1 ... 9 --- 1
//10 ... 99 --- 2
//100 ... 999 --- 3
//1000 ... 9999 --- 4
//1 1
//2 2
//3 3
//4 4
//5 5
//6 6
//7 7
//8 8
//9 9
//10 11=10+1
//11 13=11+2
//12 15=12+3
//13 17=13+4
//14 19=14+5
//15 21=15+6
//16 23=16+7
//17 25=17+8
//18 27=18+9
//19 29=19+10
//20 31=20+11
//99 189=99+99-10+1
//100 189+3=192=100+92=100+91+1
//101 195=100+95=100+93+2
//102 198=100+98=100+95+3
//103 201=100+101=100+97+4
//感觉规律出现了！
//if(n<10) return n;
//else if(n<100) return n+n-10+1;
//else if(n<1000) return 2*n+n-100+2;

//(digit_n-1)*n+n-10...0+digit_n-1;
/*interface*/
/*interface implementation*/
/*client*/
int sum_to_n(int n) {
    return n*(n+1)/2;
}
#include<stdio.h>
int main() {
    int n;
    scanf("%d",&n);
    //printf("n=%d\n",n);
    int digit_n=0;
    int tmp_n=n;
    int tens=1;
    while(tmp_n>0) {
        digit_n++;
        tens*=10;
        tmp_n=tmp_n/10;
    }
    //printf("digit n = %d\n",digit_n);
    //printf("ten n = %d\n",tens);
    if(n>10) {
        printf("%d\n",(digit_n-1)*n+n-(tens/10)+(digit_n-1));
        //printf("%d\n",digit_n*n-tens/10+(digit_n-1));
        //printf("%d\n",digit_n*(n+1)-tens/10+-1);
    } else {
        printf("%d\n",n);
    }
    return 0;
}
