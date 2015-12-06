#include <stdio.h>
#define MAX 30010;
int N, T, A[MAX];
int main() {
    scanf("%d%d", &N, &T);
    int i;
    for(i = 1; i < N; i++) {
        scanf("%d", &A[i]);
    }
    A[N] = 1;
    int cur;
    for(cur = 1; cur <= N; cur += A[cur]) {
        if(cur == T) return 0 & puts("YES");
    }

    puts("NO");
    return 0;
}
