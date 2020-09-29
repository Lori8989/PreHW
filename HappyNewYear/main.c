#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t,home,k,min=100000000,max=0;
    scanf("%d",&t);
    scanf("%d",&home);

    while( t-- ){
        scanf("%d",&k);
        if( k<min )
            min=k;
        if( k>max )
            max=k;;
    }

    if( home <= min )
        k=2*max-2*home;
    else if( min < home && max > home )
        k=2*max-2*min;
    else
        k=2*home-2*min;

    printf("%d\n",k);

    return 0;
}
