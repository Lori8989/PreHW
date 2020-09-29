#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,j;
    int num[2001];
    scanf("%d\n",&n);
    for(i=0;i<n;i++){
        scanf("%d",&num[i]);
    }
    for(i=0;i<n;i++){
            int a=0;
        for(j=0;j<n;j++){
                if(num[i]>num[j]){
                    a++;
                }
        }
    a++;
        printf("%d",a);
        if (i<n-1)
            printf(" ");
    }
    printf("\n");



}
