#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ab, bc, ca;
    scanf("%d %d %d",&ab,&bc,&ca);

    int sum = ab + bc + ca;
    sum /= 2;

    printf("%d ",sum - bc);
    printf("%d ",sum - ca);
    printf("%d\n",sum - ab);

    return 0;
}
