#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a, b;
    scanf("%f %f",&a,&b);
 //   printf("read a = %f, b = %f\n",a,b);

    a += b;

    //printf("a+b = %.3f\n",a);
    printf("%.3f",a);

    //int ab = a * 1000;
/*
    if( ab % 1000 == 0 )
        printf("000");
    else if( ab % 100 == 0 )
        printf("00");
    else if( ab % 10 == 0 )
        printf("0");
*/
    printf("\n");

    return 0;
}
