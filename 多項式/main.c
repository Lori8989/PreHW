#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n,m,a,i;
    int sum=0;
    scanf("%d%d\n",&n,&m);
    i=n;
    while(i>=0){
        scanf("%d",&a);
        sum=sum+pow(m,i)*a;
        i--;
    }
    printf("%d\n",sum);
    return 0;
}
