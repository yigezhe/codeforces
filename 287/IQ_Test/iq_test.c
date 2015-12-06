#include<stdio.h>
int main() {
  char s[4][5];
  int i,j;
  for(i=0;i<4;i++) {
    scanf("%s",s[i]);
  }
  int find=0;
  for(i=0;i<3 && !find; i++) {
    for(j=0;j<3 && !find; j++) {
      int dot=0;
      int pound=0;
      if(s[i][j]=='.') dot++;
      else pound++;
      if(s[i+1][j]=='.') dot++;
      else pound++;
      if(s[i][j+1]=='.') dot++;
      else pound++;
      if(s[i+1][j+1]=='.') dot++;
      else pound++;
      if(dot>2 || pound>2) find=1;
      }
  }
  if(find) printf("YES\n");
  else printf("NO\n");
  
  return 0;
}