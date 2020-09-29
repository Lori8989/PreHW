#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,n,m,sum,first,cur;
    int game[1001],bill[1001];
    scanf("%d %d",&n,&m);
    for( i=0;i<n;i++ )
        scanf("%d",&game[i]);
    for( i=0;i<m;i++ )
        scanf("%d",&bill[i]);
    first=cur=sum=0;

    while( first<m && cur<n ){
            int c=cur;
            for( i=c;i<n;i++){
                if( game[i] <= bill[first] ){
                    sum++;
                    cur=i+1;
                    first++;
                    break;
                }
            }
            if( i == n )
                break;
    }
    printf("%d\n",sum);
    return 0;
}
