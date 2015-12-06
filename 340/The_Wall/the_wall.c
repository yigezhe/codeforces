#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main() {
    int x,y,a,b;
    scanf("%d%d%d%d",&x,&y,&a,&b);
    int i;
    int counter=0;
    for(i=a; i<=b; i++) {
        if(i%x==0 && i%y==0) counter++;
    }
    printf("%d\n",counter);
    return 0;
}
