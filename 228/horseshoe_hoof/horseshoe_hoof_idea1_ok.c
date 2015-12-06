#include<stdio.h>
int main() {
    int s1,s2,s3,s4;
    scanf("%d%d%d%d",&s1,&s2,&s3,&s4);
    if(s1==s2) {
        if(s3==s4) {
            if(s1==s3) {
                //s1==s2, s3==s4, s1==s3
                //1 1 1 1
                printf("3\n");
            } else {
                //s1==s2, s3==s4, s1!=s3
                //1 1 2 2
                printf("2\n");
            }
        } else {
            if(s1==s3) {
                //s1==s2, s3!=s4, s1==s3
                //1 1 1 2
                printf("2\n");
            } else {
                if(s1==s4) {
                    //s1==s2, s3!=s4, s1!=s3, s1==s4
                    //1 1 2 1
                    printf("2\n");
                } else {
                    //s1==s2, s3!=s4, s1!=s3, s1!=s4
                    //1 1 2 3
                    printf("1\n");
                }
            }
        }
    } else {
        if(s3==s4) {
            if(s1==s3) {
                //s1!=s2, s3==s4, s1==s3
                //1 2 1 1
                printf("2\n");
            } else {
                if(s2==s3) {
                    //s1!=s2, s3==s4, s1!=s3, s2==s3
                    //1 2 2 2
                    printf("2\n");
                } else {
                    //s1!=s2, s3==s4, s1!=s3, s2!=s3
                    //1 2 3 3
                    printf("1\n");
                }
            }
        } else {
            if(s1==s3) {
                if(s2==s4) {
                    //s1!=s2, s3!=s4, s1==s3, s2==s4
                    //1 2 1 2
                    printf("2\n");
                } else {
                    //s1!=s2, s3!=s4, s1==s3, s2!=s4
                    //1 2 1 3
                    printf("1\n");
                }
            } else {
                if(s2==s4) {
                    //s1!=s2, s3!=s4, s1!=s3, s2==s4
                    //1 2 3 2
                    printf("1\n");
                } else {
                    if(s1==s4) {
                        if(s2==s3) {
                            //s1!=s2, s3!=s4, s1!=s3, s2!=s4, s1==s4, s2==s3
                            //1 2 2 1
                            printf("2\n");
                        } else {
                            //s1!=s2, s3!=s4, s1!=s3, s2!=s4, s1==s4, s2!=s3
                            //1 2 3 1
                            printf("1\n");
                        }
                    } else {
                        if(s2==s3) {
                            //s1!=s2, s3!=s4, s1!=s3, s2!=s4, s1!=s4, s2==s3
                            //1 2 2 3
                            printf("1\n");
                        } else {
                            //s1!=s2, s3!=s4, s1!=s3, s2!=s4, s1!=s4, s2!=s3
                            //1 2 3 4
                            printf("0\n");
                        }
                    }
                }
            }
        }
    }
    return 0;
}
