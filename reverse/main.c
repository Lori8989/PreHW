#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char sent[501];

int next( int n );
int flag=0;

int main()
{
    while( fgets( sent,505,stdin )!=NULL ){
        next( 0 );
        printf("\n");
    }
    return 0;
}

int next( int pos ){//record the position
    int i;
    char wrd[500]={'\0'};//initialize
    for( i=pos;i<=strlen(sent);i++ ){//from the head
        if( sent[i]==32 ){//next word
            flag=1;
            next( i+1 );
            if( i==strlen(sent) )
                printf("%s",wrd);
            else
                printf(" %s",wrd);
            break;
        }
        wrd[i-pos]=sent[i];
    }
        if( i==strlen(sent)+1 ){//only one word,print(basic step)
            for( int j=0;j<strlen(wrd)-1;j++ )
                printf( "%c",wrd[j] );
            return 0;
        }
}

