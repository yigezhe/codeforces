//submit ok!
#include <stdio.h>

int a, b, n, k, i;

int main() {
    scanf( "%d%d", &n, &k );
    //全局变量，默认初值是0？
    i=0;
    while(1) {
        i++;
        if( i > n ) break;
        scanf( "%d", &a );
	//遇到n就不统计了！
        if( a <= 0 ) break;
	//b没有给予初值就使用，不好！
        if( i == k ) b = a;
	//放在后面好一点！
	//继续统计与第k个数相同的，如果比第k个数小，就停止统计！
        if( i > k && a < b ) break;
    }
    printf( "%d\n", i - 1 );
    return 0;
}
