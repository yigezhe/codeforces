#include<stdio.h>
#include<math.h>
#include<string.h>
int main() {
    int n;
    scanf("%d",&n);
    int i;
    char word[150][150];
    for(i=0; i<n; i++) {
        scanf("%s",word[i]);
        int size=strlen(word[i]);
        if (size>10) {
            char short_word[150];
            short_word[0]=word[i][0];
            short_word[1]='\0';
            int mid=size-2;
            char mid_char[10];

            int mid_size=1+(int)log10(mid);
            //printf("mid size = %d\n",mid_size);
            int j;
            for (j=0; j<mid_size; j++) {
                mid_char[mid_size-1-j]='0'+mid%10;
                mid = mid / 10;
            }
            mid_char[mid_size]='\0';
            //printf("number char array = %s\n",mid_char);
            strcat(short_word,mid_char);
            int next=strlen(short_word);
            short_word[next]=word[i][size-1];
            short_word[next+1]='\0';
	    printf("%s\n",short_word);
        } else {
        printf("%s\n",word[i]);
	}
    }
    return 0;
}
