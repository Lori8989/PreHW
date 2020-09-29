#include <stdio.h>
#include <stdlib.h>

char map[27]="abcdefghijklmnopqrstuvwxyz";

void swap( char x, char y );

int main()
{
    int len,t;
    char x,y;
    scanf("%d",&len);
    scanf("%d",&t);
    char brd[200001];
    scanf("%s",brd);

    while( t-- ){
        scanf(" %c %c",&x,&y);
        swap( x , y );
    }

    for( int i=0; i<len; i++ ){
        int idx;
        idx=brd[i]-'a';
        printf("%c",map[idx]);
    }
    printf("\n");

    return 0;
}

void swap( char x , char y )
{
    for( int i=0; i<26; i++ ){
        if( map[i] == x )
            map[i]=y;
        else if( map[i] == y )
            map[i]=x;
    }
}
