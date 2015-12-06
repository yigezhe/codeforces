#include<stdio.h>
#include<string.h>
#define N 100
#define M 100+5
int main() {
    int n;
    scanf("%d",&n);
    int i,j;
    char file_name[M][N];
    //获取文件名
    for(i=0; i<n; i++) {
        scanf("%s",file_name[i]);
    }
    for(i=0; i<n; i++) {
        printf("%s\n",file_name[i]);
    }
    //直接比较两个文件！
    for(i=0; i<n; i++) {
        for(j=i+1; j<n; j++) {
		//判断是不是有相同文件名！
            int same_extensionij=1;
	    int k,l;

            int findi=-1;
            int sizei=strlen(file_name[i]);
            for(k=0; k<sizei; k++) {
                if(file_name[i][k]=='.') {
                    findi=k;
                }
            }
            int findj=-1;
            int sizej=strlen(file_name[j]);
            for(k=0; k<sizej; k++) {
                if(file_name[j][k]=='.') {
                    findj=k;
                }
            }
	    if(findi!=-1&&findj!=-1) {
		    k=findi+1;l=findj+1;
		    while(1) {
			    if(file_name[i][k]!=file_name[j][l]) {
				    same_extensionij=0;
				    break;
			    }
		    }
	    }
            if(same_extension(i,j)) {
                if(same_file(i,j)) {
                    //放入同一组里！
                }
            } else {
                //在不同的组里！
            }
        }
    }

    //获取扩展名
    char file_extension[M][N];
    int gi=0;
    int gj=0;
    int files[M];
    int fi=0;
    for(i=0; i<n; i++) {
        int find=0;
        int size=strlen(file_name[i]);
        for(j=0; j<size; j++) {
            if(file_name[i][j]=='.') {
                find=1;
                break;
            }
        }
        char extension[N];
        int k;
        if(find) {
            for(k=j+1; k<size; k++) {
                extension[k-j-1]=file_name[i][k];
            }
            extension[k-j-1]='\0';
        }
        int which=-1;
        for(k=0; k<fi; k++) {
            if(strcmp(extension,file_extension[k])==0) {
                which=k;
                break;
            }
        }
        if(which==-1) {
            strcpy(file_extension[fi],extension);
            files[fi]=1;
            fi++;
        } else {
            files[which]++;
        }
    }
    for(i=0; i<fi; i++) {
        printf("%s:%d\n",file_extension[i],files[i]);
    }
    //如果某个扩展名下的文件只有一个，我们也不需要比较！
    return 0;
}
