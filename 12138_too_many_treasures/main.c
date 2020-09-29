#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, q;
    scanf("%d %d",&n,&q);

    long long int presum[n+2];
    presum[0] = 0;

    for( int i = 1 ; i <= n ; i++ ){//printf("###");
        int cur;
        scanf("%d",&cur);//printf("cur=%d\n",cur);
        if( cur < 0 ) cur = 0;
        presum[i] = presum[i-1] + cur;
        //printf("number[%d] = %d\n",i,presum[i]);
    }

    int l, r, m;
    while( q-- ){
        scanf("%d %d %d",&l,&r,&m);

        printf("%lld\n",presum[l+m-1] - presum[l-1]);
    }
    return 0;
}

/*

10 5
103 21 9 6 6 4 2 2 2 1
1 5 3
2 9 4
3 3 1
1 10 2
4 7 3

*/
