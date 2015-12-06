/*http://codeforces.com/blog/openCoder*/
#include <stdio.h>

int main()
{

     int n, m, a;

     //这里我觉得没有必要在％d之间留出空格！
     scanf("%d%d%d", &n, &m, &a);

     //作者的表达有一种对称的整洁！
     int x = n % a == 0 ? n/a : n/a + 1;
     int y = m % a == 0 ? m/a : m/a + 1;
     long long z = (long long)x * (long long)y;


     printf("%lld\n", z);
     return 0;
}

