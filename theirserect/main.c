#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 5000

int n,cnt=0;
char p[max];
char str[max][max+1];
char ans[max][max+1];
int freq[max]={};

void patt( char* a,char* b );
void swap( int i,int j );
int cmp( int i,int j );

int main()
{
    scanf( "%d %s",&n,p );
    patt(p,p);
    for( int i=0;i<n;i++){
        char s[max+1],pat[max+1];
        scanf( "%s",s );
        if( strcmp( pat,p )!=0)
            continue;
        int prev=cnt-1;
        if( strcmp( s,str[prev] )!=0 ){
            strcpy( str[cnt],s )
            freq[cnt]=1;
            cnt++;
        }
        else
            freq[prev]++;
    }
    for(int i=0; i<cnt; i++){
        for(int j=0; j<cnt-1; j++){
            if( mycmp(j, j+1) > 0){
                myswap(j, j+1);
            }
        }
    }

    printf("%d\n", cnt);
    for(int i=0; i<cnt; i++){
        printf("%s %d\n", str[i], freq[i]);
    }

    return 0;
}
void patt( char* a,char* b ){
    char map[26]={};
    strcpy( a,b );
    int len=strlen(a);
    char cur='a';
    for(int i=0;i<len;i++){
        int idx=a[i]-'a';
        if( map[idx]==0 )
            map[idx]=cur++;
        a[i]=map[idx];
    }
}

void swap( int i,int j ){
    char temp;
    strcpy(temp,str[i]);
    strcpy(str[i],str[j]);
    strcpy(str[j],temp);

    int x=freq[i];
    freq[i]=freq[j];
    freq[j]=x;
}

int cmp( int i,int j ){
    if( freq[i]<freq[j] ) return 1;
    if( freq[i]<freq[j] ) return -1;
    return 0;
}
