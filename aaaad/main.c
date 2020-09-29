#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,nxt,nnxt,num[10];
    for(i=0;i<9;i++){
        scanf("%d",&num[i]);
    }
    if (num[0]==1)
        printf("1\n");
    else{
    int sum=num[0]+1;
    nxt=num[num[0]-1];
    while(i>0){
            if(nxt==1){
                break;
            }
            else{
                sum+=nxt;
                nnxt=num[nxt-1];
                nxt=nnxt;
            }
            i--;
    }
    printf("%d\n",sum);}
}
