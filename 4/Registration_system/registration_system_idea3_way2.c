//用链表来表达！
/*interface*/
/*interface implementation*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define C 33+5
#define N 100001
struct node {
    char name[C];
    struct node *next;
};
struct node *root;
void search_and_record(char *name, char *result) {
    //printf("search_and_record(%s,%s)\n",name, result);
    //每次搜索前先打印链表！
    struct node * conductor=NULL;
    struct node * needed_conductor = NULL;
    conductor = root;
    /*
    printf(">>>>>>>>>\n");
    while ( conductor != NULL ) {
        printf( "%s,", conductor->name );
        conductor = conductor->next;
    }
    printf("\n------------\n");
    */
    struct node *new_node=malloc(sizeof(struct node));
    if(new_node==NULL) {
        printf("没有分配到内存，工作无法进展\n");
        exit(1);
    }
    strcpy(new_node->name,name);
    //printf("要加入的新元素：%s==%s\n",name,new_node->name);
    new_node->next=NULL;
struct node * insert_position=NULL;

    if(root==NULL) {
        //printf("出现了第一个元素\n");
        root=new_node;
    } else {
        //printf("我按字典序添加元素\n");
        conductor = root;
        needed_conductor=NULL;

        while(1) {
            //取消needed_conductor，如果相等，我们可以添加在后面，
            //如果小于，我们可以添加在前面
            if(strcmp(conductor->name,name)>0) {
                needed_conductor=conductor;
            } else break;
            if(conductor->next!=NULL) conductor=conductor->next;
            else break;
        }
        //printf("我们要把新元素插入这个元素的后面%s\n",needed_conductor->name);
        //插入一个元素！
        if(needed_conductor==NULL) {
            insert_position=root;
            root=new_node;
            root->next=insert_position;
        } else {
            insert_position=needed_conductor->next;
            needed_conductor->next=new_node;
            new_node->next=insert_position;
        }
    }
    int same=0;
    conductor = new_node;
    while ( conductor != NULL ) {
        if(strcmp(name,conductor->name)==0) {same++;}
        conductor = conductor->next;
    }
    //printf("%s的相同项的个数是%d\n",name,same);
    if(same==1) {
        strcpy(result,"OK");
    } else {
        strcpy(result,name);
        char digit[C];
        sprintf(digit,"%d",same-1);
        strcat(result,digit);
    }
}
/*client*/
int main() {
    int n;
    scanf("%d",&n);
    int i;
    for(i=0; i<n; i++) {
        char name[C];
        scanf("%s",name);
        //printf("%d: %s",i,name);
        char result[C];
        search_and_record(name,result);
        printf("%s\n",result);
    }

    return 0;
}
