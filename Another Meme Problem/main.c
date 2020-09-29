#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long int a,b,sum;
    int n;
    scanf("%d",&n);

    while(n--){
        scanf("%lld %lld",&a,&b);
        sum=0;

        if( b>=99999999 ){
            sum+=a;
            b/=10;
        }
        if( b>=9999999  ){
            sum+=a;
            b/=10;
        }
        if( b>=999999   ){
            sum+=a;
            b/=10;
        }
        if( b>=99999    ){
            sum+=a;
            b/=10;
        }
        if( b>=9999     ){
            sum+=a;
            b/=10;
        }
        if( b>=999      ){
            sum+=a;
            b/=10;
        }
        if( b>=99       ){
            sum+=a;
            b/=10;
        }
        if( b>=9        ){
            sum+=a;
        }
        printf("%lld\n",sum);
    }

    return 0;
}
