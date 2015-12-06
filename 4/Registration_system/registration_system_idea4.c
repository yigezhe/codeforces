//把string变换一下，便于查找！
/*interface*/
/*interface implementation*/
#include<stdio.h>
#include<string.h>
#define C 33+5
#define N 100001
char database[N][C];
int n;
int hash(char *name) {
	int D=100000;
	int i,sum=0;
	for(i=0;i<n;i++) {
		sum+=(int)name[i];
	}
	return sum%D;
}
void search(char * name, char *result,int size) {
    int i;
    int same=0;
    for(i=0; i<size-1; i++) {
        if(hash(name)==hash(database[i])) {
		same++;
        }
    }
    if(same==1) {
        strcpy(result,"OK");
    } else {
        strcpy(result,name);
        char digit[C];
        sprintf(digit,"%d",same);
        strcat(result,digit);
    }
}
/*client*/
int main() {
    scanf("%d",&n);
    int i;
    for(i=0; i<n; i++) {
        scanf("%s",database[i]);
        char result[C];
        search(database[i],result,i);
        printf("%s\n",result);
    }

    return 0;
}
