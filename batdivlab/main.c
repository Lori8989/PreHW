#include <stdio.h>
#include <stdlib.h>

int pow(int a, int n){
    if( n == 0 ){
        return 1;
    }
    else{
        if(n%2==0)
            return pow(a,n/2)*pow(a,n/2)%10177;
        else
            return a*pow(a,n/2)*pow(a,n/2)%10177;

    }
}
int main()
{
    int x,a,n;
    while(scanf("%d %d %d",&x,&a,&n)!=-1){
        printf("%d\n",x*pow(a+1,n-1)%10177);
    }
    return 0;
}
