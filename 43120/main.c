#include <stdio.h>
#include <stdlib.h>
int main()
{
    int A[5]={0,1,2,3,4};
    int a,k,i,j;//a暫時，k次數，ij輸入兩數
	0<k<25;
    scanf("%d",&k);
    while(k>0){
        scanf("%d %d",&i,&j);
        a=A[j];
        A[j]=A[i];
        A[i]=a;
        k--;
    }
    printf("%d %d %d %d %d",A[0],A[1],A[2],A[3],A[4]);
    return 0;
}
