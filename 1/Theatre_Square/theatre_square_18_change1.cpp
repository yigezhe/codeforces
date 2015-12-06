#include <cstdio>
int main() {
    unsigned long long a, b, c;
    //while(scanf("%I64u%I64u%I64u",&a,&b,&c)!=EOF)
    scanf("%I64u%I64u%I64u",&a,&b,&c);
    printf("%I64u\n",(a/c+(a%c!=0))*(b/c+(b%c!=0)));
    return 0;
}
