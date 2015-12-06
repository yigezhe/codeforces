#include<stdio.h>
int is_lucky(int n) {
    while (n>0) {
        if(n%10==4 || n%10==7) {
            n=n/10;
        } else {
            return 0;
        }
    }
    return 1;
}
int main() {
    int a[]= {4,7,47,774,4,5,17,467,16,78};
    printf("%lu\n",sizeof(a));
    printf("%lu\n",sizeof(int));
    printf("%lu\n",sizeof(a)/sizeof(int));
    int size=sizeof(a)/sizeof(int);
    int i;
    for(i=0; i<size; i++) {
        if(is_lucky(a[i])) {
            printf("%d is lucky\n",a[i]);
        } else {
            printf("%d\n",a[i]);
        }
    }
    return 0;
}
