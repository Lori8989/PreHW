#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n,l,r,k,num;
    char line[10001],line2[10001];

    scanf("%s",line);
    scanf("%d",&n);

    while(n--){
        int i;
        scanf("%d %d %d",&l,&r,&k);
        l--;r--;
        num=r-l+1;
        while( k > num )
            k=k-num;

        for( i=0;i<l;i++ )
            line2[i]=line[i];
        for( i=0;i<k;i++ )
            line2[l+i]=line[r-k+1+i];
        for( i=0;i<num-k;i++ )
            line2[l+k+i]=line[l+i];
        for( i=0;i<strlen(line)-r-1;i++ )
            line2[r+1+i]=line[r+1+i];

        for( i=0;i<strlen(line);i++ )
            line[i]=line2[i];
    }
    printf("%s\n",line2);

    return 0;
}
