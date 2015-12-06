
/*interface*/
/*interface implementation*/
struct string_list {
	char *string;
	int same;
	struct string_list * next;
};
/*client*/
#define C 33+5
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main() {
	char *name=malloc(C*sizeof(char));
	struct string_list *slist=malloc(sizeof(struct string_list));
	strcpy(name,"abc");
	slist->string=name;
	slist->same=1;
	slist->next=NULL;
	printf("string list is (%s,%d,%x)\n",slist->string,slist->same,(unsigned int)(slist->next));
	return 0;
}
