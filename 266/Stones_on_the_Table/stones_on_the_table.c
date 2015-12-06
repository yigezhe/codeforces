#include<stdio.h>

#define N 50+5
int main() {
    int n;
    scanf("%d",&n);
    char stones[N];
    scanf("%s",stones);
    int takes=0;
    int i;
    for(i=0; i<n-1; i++) {
        if(stones[i]==stones[i+1]) {
            takes++;
        }
    }
    printf("%d\n",takes);
    return 0;
}
