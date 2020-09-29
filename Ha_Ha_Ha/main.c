#include <stdio.h>
#include <stdlib.h>

int gcd(int,int);

int main()
{
    int n,i,j,num,ans=1;
    int a[1001];
    scanf("%d",&n);
    for( i=0 ; i<n ; i++ ){
        scanf("%d",&a[i]);
    }

    for( i=0 ; i<n ; i++ ){
        for( j=0 ; j<n ; j++ ){
            if( j != i && a[i]>ans && a[j]>ans ){
                //printf("##");
                num=gcd(a[i],a[j]);//printf("num = %d, %d %d\n",num,a[i],a[j]);
                ans = ans > num ? ans : num;
            }

        }
    }
    printf("%d\n",ans);
    return 0;
}

int gcd(int a, int b)
{
    int t=1;
    while( t != 0){
        t=b%a;
        b=a;
        a=t;
    }
    return b;
}
