#include <stdio.h>
#include <stdlib.h>
#include <math.h>


long long l,r,num[52];

char map( int k, long long now );

int main()
{
    for( int i=1; i<52; i++ )
        num[i]= 3 *( pow(2, i+1 ) - 1 );


    int k;
    while( scanf("%d %d %d",&k,&l,&r) != EOF){
       char str[105]={0};
       int j=0;

       for( long long int i=l; i<=r; i++)
            str[j++]=map( k, i );

        printf("%s\n",str);
    }
    return 0;
}

char map( int k, long long int now )
{
    if( now == num[k]-1 )
        return 'Q';
    else if( now == (num[k]-1)/2 )
        return 'u';
    else if( now == 0 )
        return 'O';
    else if( now < (num[k]-1)/2 )
        return map( k-1, now-1 );
    else
        return map( k-1, (now-2) % num[k-1] );

}
/*
3 0 10
*/
