#include <stdio.h>
#include <stdlib.h>

int main()
{
    int r,c,hei,wid,time,dir=0;
    scanf( "%d %d",&hei,&wid );
    scanf( "%d %d",&r,&c );
    scanf( "%d",&time );
    while( --time ){
        if( c==1&&r==1||c==wid&&r==hei||c==wid&&r==1||c==1&&r==hei ) break;
        if( dir==0 ){
            while( c!=wid&&r!=1 ){
                c++;
                r--;
            }
            if( c==wid )
                dir=3;
            else  dir=1;
        }
        else if( dir==1 ){
            while( c!=wid&&r!=hei ){
                c++;
                r++;
            }
            if( c==wid )
                dir=2;
            else dir=0;
        }
        else if( dir==2 ){
            while( c!=1&&r!=hei ){
                c--;
                r++;
            }
            if( c==1 )
                dir=1;
            else dir=3;
        }
        else if( dir==3 ){
            while( c!=1&&r!=1 ){
                c--;
                r--;
            }
            if( c==1 )
                dir=0;
            else dir=2;
        }
    }
    printf( "(%d,%d)",r,c );
    return 0;
}
