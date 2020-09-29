#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,n,i,t;
    int num[1001],ans[1001];
    scanf("%d",&n);//total n numbers
    for(t=0;t<n;t++){
        scanf("%d",&num[t]);
        }//numbers in num[]
    for(t=0;t<n;t++){
        int mul=0,div=0;//clean
        for(i=0;i<n;i++){
            if(num[i]%num[t]==0){
                mul++;
            }
            if(num[t]%num[i]==0){
                div++;
            }
        }
        ans[t]=mul-div;

    }

    a=ans[0];
    b =0 ;
    for(t=0;t<n;t++){
        if(a>ans[t]){
            a=ans[t];
            b=t;
        }
        else if(a==ans[t]&&num[t]<num[b]){
            b=t;
        }
    }

    printf("%d\n",num[b]);


    return 0;
}
