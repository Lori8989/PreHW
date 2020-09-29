#include <stdio.h>
#include <stdlib.h>

void moreday( int start,int sum, int k );
int main()
{
    int year,n;
    scanf("%d",&n);
    while( n-- ){
        scanf("%d",&year);

        if( year%400 == 0 ){
            moreday(year,0,0);
        }
        else if( year%100 == 0 ){
            moreday(year,0,1);
        }
        else if( year%4 == 0){
            moreday(year,0,0);
        }
        else{
            moreday(year,0,1);
        }//k=0 leap,k=1 normal

    }
    return 0;
}

void moreday( int start, int sum, int k )
{
    int kk,next;
    next=start+1;

    if(start%400 == 0){
        sum+=2;
    }else if( start%100 == 0 ){
        sum++;
    }else if( start%4 == 0){
        sum+=2;
    }else{
        sum++;
    }

    if(next%400 == 0){
        kk=0;
    }else if( next%100 == 0 ){
        kk=1;
    }else if( next%4 == 0){
        kk=0;
    }else{
        kk=1;//kk=0 leap
    }

    if( kk == k && sum %7 == 0 && sum>0)
        printf("%d\n",next);
    else
        moreday( next,sum ,k );
}
