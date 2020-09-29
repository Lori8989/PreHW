#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, tmp, top_idx = 0;
    scanf("%d",&n);
    int num[n+1];//line up melons

    for( int i = 0 ; i < n ; i++ ){
        scanf("%d ",&num[i]);
    }

    tmp = n;
    while( tmp-- ){
        int target;
        int last = 0;
        scanf("%d",&target);//printf("now target is %d--\n",target);

        for( int i = top_idx ; i < n ; i++ ){
            if( num[i] == target ){//printf("**number[%d] is %d, top is [%d], so eat ",i,num[i],top_idx);
                printf("%d",i - top_idx + 1);
                top_idx = i + 1;
                if( top_idx == n ){
                    last = 1;
                }
                break;
            }
            if( i + 1 == n && num[i] != target )
                printf("0");
        }
        //printf("##%d , %d\n",top_idx,n);
        if( top_idx == n ){
            if( last )
                last = 0;
            else
                printf("0");
        }
        if( tmp )
            printf(" ");
        //printf("\n");
    }
    return 0;
}
/*

5
5 3 2 1 4
2 3 4 5 1

*/
