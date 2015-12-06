//竞赛中的问题，还可以处理操作系统问题，
//不局限于数学问题，很好，这样一来我解决的问题越多，
//我的知识面就越广！
//现在看来我只在合适的时间参加比赛，其他时间就积极训练。
//我不追求参加比赛的次数，
//我如果训练扎实，我一次可以解决整个比赛的所有问题！
//这是我扎实训练的目标！
//我的一个想法是用一个字符串数组来处理目录！
//directory[0]="/";
//directory[1]="first";
/*interface*/
#include<stdio.h>
#include<string.h>
#define N 200+2
char path[2*N];
int path_n;
void print_path() {
    printf("%s\n",path);
}
//会不会有/home/../sis形式的命令，有，我就需要改变！
void change_path(char *directory) {
    if(directory[0]=='/') {
        //copy
        printf("copy\n");
        int i;
        int k=0;
        for(i=0; directory[i]!='\0'; i++) {
            path[k]=directory[i];
            k++;
        }
        path[k]='/';
        k++;
        path[k]='\0';
        path_n=k;
    } else  {
        int k=0,j;
        while(directory[k]!='\0') {
            printf("k=%d\n",k);
            if(directory[k]=='/') {
                k++;
            } else if(directory[k]=='.') {
                for(j=path_n-2; j>=0; j--) {
                    if(path[j]=='/') {
                        j++;
                        path[j]='\0';
                        path_n=j;
                        break;
                    }
                }
                k+=2;
            } else {
                j=path_n;
                while(directory[k]=='\0') {
                    if(directory[k]=='/') {
                        break;
                    }
                    path[j]=directory[k];
                    k++;
                    j++;
                }
            }
            path[j]='/';
            j++;
            path[j]='\0';
            path_n=j;
            break;
        }
    }
}
/*interface implementation*/
/*client*/
//没有从根目录返回父目录的情况出现！
//cd后面的目录都是存在的！
//两个／不能相邻出现！
//cd 后面的文件名不以／结尾！除非它是根目录！
//可以有相同的名字！
//我要建立一个树的结构，然后用查找树的方法来处理这个问题？
//但是我还没有掌握树，所以无法运用！
//
void get_line(char *line) {
    int i=0;
    while(1) {
        char ch=getchar();
        if(ch=='\n' || ch==EOF) {
            line[i]='\0';
            break;
        } else {
            line[i]=ch;
            i++;
        }
    }
}
int main() {
    int n;
    scanf("%d",&n);
    //printf("n=%d\n",n);
    getchar();
    char command[N];
    char directory[N];
    path[0]='/';
    path[1]='\0';
    path_n=1;
    int i;
    for(i=0; i<n; i++) {
        get_line(command);
        //printf("%d: %s\n",i,command);
        if(strcmp(command,"pwd")==0) {
            //printf("path = ");
            print_path();
        } else {
            int k=0;
            int j;
            for(j=3; command[j]!='\0'; j++) {
                directory[k]=command[j];
                k++;
            }
            directory[k]='\0';
            //printf("directory=%s\n",directory);
            change_path(directory);
        }
    }
    return 0;
}
