#include <stdio.h>

unsigned long long i,j,m,n,k=0,sum=0,h[10000003],a[100000];

int main(){
    scanf( "%llu %llu",&n,&m );
    h[0]=1000000001;
    for( i=1;i<=n;i++ )
        scanf( "%llu",&h[i] );
    for( i=n;i>m;i-- ){
        sum=0;
        for( j=i-1;j>0;j-- ){
            if( h[i]>h[i-m-1] )//too much
                break;
            if( h[i]>h[j] )
                sum++;//comfort++
            else
                break;
            if( sum>m )
                break;
        }
        if( sum==m ){
            k++;
            a[k]=i;
            i=i-m;
        }
    }
    if(k==0)
        printf("ouo");
    else{
        printf("%llu",a[k]);
        for(i=k-1;i>0;i--){
            printf(" %llu",a[i]);
        }
    }
    printf("\n");
    return 0;
}
