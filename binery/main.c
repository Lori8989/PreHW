#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b[12];

    scanf("%d",&a);
    int temp1=a,t=0;
    if (a=0){
        t=1;
    }
    else{
        while(temp1>0){
        temp1=temp1/2;
        t++;
    }//t=�X��ơA
    }


    int temp2=t;//temp2=�X���
    while(t>0){
        b[t-1]=a%2;
        a=a/2;
        t--;
    }

    t=temp2;
    int i=t-1;
    b[i]=b[i]+1;//t-1�i�H�o�쥽��
    int k=0;//k�i��X��
    while(b[i]==2&&i>0){
        b[i]=b[i]%2;//2�O0�i1 3�O1�i1
        b[i-1]++;
        i--;
        k++;
    }
    i=0;
    if(b[0]==2){
        while(i<=t-1){
            b[i]=b[i-1];
            i++;
            b[0]=1;
        }
    }
    i=0;
    while(i<=t-1){
        printf("%d",b[i]);
        i++;
    }
    printf(" %d",k);
    return 0;

}
