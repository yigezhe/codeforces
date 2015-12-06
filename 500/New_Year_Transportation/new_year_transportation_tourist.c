#include<stdio.h>
#define MAX 30010
int a[MAX];

int main() {
    int n, t,i;
    scanf("%d %d", &n, &t);
    for (i = 1; i < n; i++) {
        scanf("%d", a + i);
    }
    int x = 1;
    while (x < t) {
        x += a[x];
    }
    puts(x == t ? "YES" : "NO");
    return 0;
}
