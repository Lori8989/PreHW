#include <stdio.h>
#include <string.h>
#include "function.h"

int solver(int **ptr, int *sum, char *s)
{
  int len=strlen(*s);
  int flag[len]={0};
  for(int i=0;i<len;i++){
    if(s[i]=='-'&&isdigit(s[i+1])){
        *ptr[i]=s[i];
        *ptr[i+1]=s[i+1];
        flag[i]=2;
        flag[i+1]=1;
        printf("-%d",s[i+1]);
        continue;
    }
    if(isdigit(s[i]))
        *ptr[i]=s[i];
        flag[i]=1;
        printf("%d",s[i]);
  }
  printf(" ");
  for(int i=0;i<len;i++){
        int num=0;
    if(flag[i]==2){//-
            int j=i+1;
        while(flag[j]==1){//after num
            num=num*10+s[j];
            flag[j]=0;
            j++;
        }
        sum-=num;
        flag[i]=0;
    }
    else{
        num=0;
        while(flag[i]==1){//num
            num=num*10+s[i];
        }
        sum+=num;
    }
  }
    printf("\n");
    printf("%d",sum);
}
