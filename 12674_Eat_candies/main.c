#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);

    while( n-- ){
        int max, mid, min, tmp;
        scanf("%d %d %d",&max,&mid,&min);
//sort first, most : 3 times
        if( max < mid ){
            tmp = max;
            max = mid;
            mid = tmp;
        }

        if( mid < min ){
            tmp = mid;
            mid = min;
            min = tmp;
        }

        if( max < mid ){
            tmp = max;
            max = mid;
            mid = tmp;
        }
//if max > mid + min
        if( max >= mid + min ){
            printf("%d\n",mid+min);
        }
//else 8 2 8
        else{
            tmp = max+mid+min;
            tmp /= 2;
            printf("%d\n",tmp);
        }
    }
    return 0;
}

/*

6
1 1 1
1 2 1
4 1 1
7 4 10
8 1 4
8 2 8

*/
