#include <stdio.h>
#include <stdlib.h>
#define size 1000001
long long sum[size];

int main()
{
    int n,i,a,b,m;
    scanf("%d",&m);
    int num[m];
    for(i=1;i<=m;i++){
        sum[0]=0;
        scanf("%d",&num[i]);
        sum[i]=sum[i-1]+num[i];
    }
    scanf("%d",&n);
    while(n>0){
        scanf("%d %d",&a,&b);

    printf("%lld\n",sum[b]-sum[a-1]);
    n--;
    }
    return 0;
}
