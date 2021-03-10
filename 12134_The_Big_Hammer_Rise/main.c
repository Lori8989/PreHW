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

/*
//another method
#include<stdio.h>

int main(){
    int a_i, a_f, b_i, b_f, ans;
    scanf("%d.%d %d.%d",&a_i,&a_f,&b_i,&b_f);
    //let a_i be a*100, so that it is int, so as b
    a_i = a_i * 100 + a_f;
    b_i = b_i * 100 + b_f;
    ans = a_i * b_i;
    printf("%d.%04d\n", ans/10000, ans%10000);
    return 0;
}
*/
