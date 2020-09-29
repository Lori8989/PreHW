#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char wrd[100000];
    int len,i;
    while(scanf("%s",wrd)!=EOF){
        len=strlen(wrd);
        int mid=len/2;
        for(i=0;i<mid;i++){
            if(wrd[i]!=wrd[len-1-i])
                break;
        }
        if(i==mid)
            printf("Yes\n");
        else
            printf("No\n");
    }
    }

