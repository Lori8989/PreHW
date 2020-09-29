#include <stdio.h>
#include <stdlib.h>

int q[11]={0};
int n;
int way=0;

int vaild(int row,int col);
int place(int row);

int main()
{
    scanf("%d",&n);
    place(0);
    printf("%d",way);
    return 0;
}
int vaild(int row,int col){
    for(int i=0;i<row;i++){
        if(q[i]==col || q[i]==col-row+i ||q[i]==col+row-i)
            return 0;//no
    }
    return 1;
}
 int place(int row){
    int i;
    if(row==n)
        way++;//finish test
    else {
        for(i=0;i<n;i++){
            if(vaild(row,i)){
                q[row]=i;//put flag
                place(row+1);//continue test
            }
        }
    }
    return 0;
}
