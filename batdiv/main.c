#include <stdio.h>
#include <stdlib.h>


long long pow(long long a,long long n);
int main()
{
    int a,n,d;
    while(scanf("%d %d %d",&a,&n,&d)!=-1){
        printf("%d\n",a*pow(n+1,d-1)%10177);
    }

    return 0;
}
long long pow(long long a,long long n){
    if( n == 0 )
        return 1;
    else{
        if( n%2==0 ){
            return pow(a,n/2)*pow(a,n/2)%10177;
        }
        else{
            return a*pow(a,n/2)*pow(a,n/2)%10177;
        }
    }
}
