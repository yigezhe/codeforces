//第一，我们的hash table的大小是n，就是按照书中给出的数据规模来处理。
//第二，就是我们的冲突处理方式是，纪录下具有相同hash值的字符串，
//在查找时，多查找一次！
//这里我不用关心hash table的长度，我要给出的是最大长度！
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define C 33+5
#define N 100001

struct string_list {
    char *string;
    int same;
    struct string_list * next;
};
struct string_list *hash_table[N];
int n;
int hash(char *name) {
    int h=0;
    while(*name) {
        h+=(int)(*name);
        name++;
    }
    //printf("n==%d\n",n);
    return h % n;
}
void search_and_add(char * name, char *result) {
    int hash_number=hash(name);
    //printf("\n-------------\n");
    //printf("%s = %d\n",name,hash_number);
    //有hash记录的名字，查找有没有相同项！
    //也就是有没有冲突项！
    if( hash_table[hash_number]!=NULL) {
        //printf("已经有hash number\n");
        int find=0;
        struct string_list *current;
        current=hash_table[hash_number];
        //printf("name = %s\n",current->string);
        while(current!=NULL) {
            if(strcmp(current->string,name)==0) {
                //printf("相同hash number下找到了该名字\n");
                (current->same)++;
                find=1;
                strcpy(result,name);
                char digit[C];
                sprintf(digit,"%d",current->same);
                strcat(result,digit);
                break;
            } else {
                current=current->next;
            }
        }
        if(!find) {
            //没找到就在相同的hash下添加一个新元素!
            //printf("相同hash number下没有找到该名字\n");
            struct string_list *slist=malloc(sizeof(struct string_list));
            char *new_name=malloc(C*sizeof(char));
            strcpy(new_name,name);
            slist->string=new_name;
            slist->same=0;
            slist->next=NULL;
            current=hash_table[hash_number];
            while(current->next!=NULL) {
                current=current->next;
            }
            current->next=slist;
            strcpy(result,"OK");
        }
    } else {
        //printf("还没有hash number\n");
        struct string_list *slist=malloc(sizeof(struct string_list));
        char *new_name=malloc(C*sizeof(char));
        strcpy(new_name,name);
        slist->string=new_name;
        slist->same=0;
        slist->next=NULL;
        //把hash数作为下标可以加速查找！
        hash_table[hash_number]=slist;
        strcpy(result,"OK");
    }
}
/*client*/
int main() {
    scanf("%d",&n);
    int i;
    for(i=0; i<n; i++) {
        hash_table[i]=NULL;
    }
    for(i=0; i<n; i++) {
        char name[C];
        scanf("%s",name);
        //printf("%s--%lld\n",name,hash(name));
        char result[C];
        search_and_add(name,result);
        /*
            int j;
            for(j=0; j<hash_table_length; j++) {
                printf(" (%lld,%d)",hash_table[j],same_table[j]);
            }
            printf("\n");
        */

        printf("%s\n",result);
    }

    return 0;
}
