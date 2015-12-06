#include<stdio.h>
#include<math.h>
int main() {
     int n,m,a;
     scanf("%d %d %d",&n,&m,&a);
     /*
        printf("%d %d %d",n,m,a);
        测试结果是，类型转换优先于除法运算！
        printf("m/a=%f\n",ceil(((double)m)/a));
        printf("n/a=%f\n",ceil(((double)n)/a));
        printf("m/a=%f\n",ceil((double)m/a));
        printf("n/a=%f\n",ceil((double)n/a));

        printf("%f\n",(ceil((double)m/a)*ceil((double)n/a)));
        %g以整数的形式打印浮点数，但是对较大的浮点数，其打印结果不是整数！
        printf("%g\n",(ceil((double)m/a)*ceil((double)n/a)));
	Input
	1000000000 1000000000 192
	Output
	2.71267e+013
	Answer
	27126743055556
      */
     printf("%lli\n",(long long)(ceil((double)m/a)*(long long)ceil((double)n/a)));
     /*
        printf("ceil 1 = %f\n",ceil(1));
        printf("ceil 1.5 = %f\n",ceil(1.5));
      */
     return 0;
}
