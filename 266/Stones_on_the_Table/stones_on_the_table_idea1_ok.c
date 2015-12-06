#include<stdio.h>

#define N 50+5
int main() {
    int n;
    scanf("%d",&n);
    char stones[N];
    scanf("%s",stones);
    int takes=0;
    int current=0,after=current+1;
    while(after<n) {
        while (stones[current]==stones[after]) {
            takes++;
            if(after<n) after++;
            else {
                printf("%d\n",takes);
                return 0;
            }
        }
        current=after;
        after=current+1;
    }

    printf("%d\n",takes);
    return 0;
}
