#include <stdio.h>
#include <stdlib.h>


int main()
{
    int n, a, b;
    scanf("%d",&n);

    int presum[1000002];
    presum[0] = 0;

    for( int i = 1 ; i < 1000001 ; i++ ){
        int ans = 0, k = i;
        while( k > 0 ){
            if( k % 10 == 1 )
                ans++;
            k /= 10;
        }
        presum[i] = presum[i-1] + ans;
    }

    while( n-- ){
        scanf("%d %d",&a,&b);

        printf("%d\n",presum[b] - presum[a-1]);


    }
    return 0;
}





/*

3
1 11
10 100
1 2

5
3 500
456 60000
500000 500001
999998 999999
500000 500000
*/
