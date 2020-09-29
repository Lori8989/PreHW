#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, af, b, bf;//af, bf are two-number numbers
    scanf("%d.%d %d.%d",&a,&af,&b,&bf);
    //printf("read %d.%d %d.%d\n",a,af,b,bf);

    a *= 100;
    b *= 100;
    a = a*b + a*bf + b*af + af*bf;

//printf("a*b = %d\n",a);


    int tmp = a / 10000;
    printf("%d.",tmp);

    a = a - tmp * 10000;


    if( a / 1000 == 0 )
        printf("0");
    if( a / 100 == 0 )
        printf("0");
    if( a / 10 == 0 )
        printf("0");

    printf("%d",a);

    printf("\n");

//printf("**tmp: %d, a: %d",tmp,a);

    return 0;
}

/*
3.0 4.0
39.78 61.80
*/

