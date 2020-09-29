#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 500

char text[MAX];
char input[MAX];
int now=0,r=-1,l=-1;

void backspace();
void shiftright();

int main()
{
    fgets( input,MAX,stdin );

    for( int i=0;i<strlen(input);i++ ){
        if( input[i]=='/' ){
            if( input[i+1]=='b'){//backspace
                backspace();
                i+=9;
            }
            else if( input[i+1]=='n'){//newline
                if( now!=r+1 )
                    shiftright();
                text[now]='\n';
                now++;
                r++;
                i+=7;
            }
            else if( input[i+1]=='l'){//left
                if( now!=l+1 )
                    now--;
                i+=4;
            }
            else if( input[i+1]=='r'){//right
                if( now!=r+1 )
                    now++;
                i+=5;
            }
        }
        else{
            if( now!=r+1 )
                shiftright();
            text[now]=input[i];
            r++;
            now++;
        }
    }
    printf("%s",text);
    return 0;
}
void backspace(){
    if( now==l+1 )
        return;
    else if( now==r+1 ){//on the end
        now--;
        r--;
    }
    else{
        for( int i=now;i<=r;i++ ){//something need to move
            text[i-1]=text[i];
        }
        now--;
        r--;
    }
    return;
}

void shiftright(){
    for( int i=r;i>=now;i-- ){
        text[i+1]=text[i];
    }
    return;
}
