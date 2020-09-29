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
    }//t=幾位數，
    }


    int temp2=t;//temp2=幾位數
    while(t>0){
        b[t-1]=a%2;
        a=a/2;
        t--;
    }

    t=temp2;
    int i=t-1;
    b[i]=b[i]+1;//t-1可以得到末位
    int k=0;//k進位幾次
    while(b[i]==2&&i>0){
        b[i]=b[i]%2;//2是0進1 3是1進1
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
