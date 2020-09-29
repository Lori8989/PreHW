#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m,n,t,T,i;
    int spr[110];
    scanf("%d\n",&T);
    while(T>0){
        scanf("%d %d %d\n",&n,&m,&t);
        if(t>=n+m){
                for(i=1;i<=n;i++){
                    printf("-");//all sit
                }
                }
        else {
            for(i=0;i<n-1;i++){
                spr[i]='-';
            }
            for(i=n-1;i<n+m-1;i++){
            spr[i]='^';
            }
            for(i=n+m-1;i<m+n+n-1;i++){
            spr[i]='-';
            }
        for(i=n+n+m-2;i>n+m-1-t;i--){
            printf("%c",spr[i]);
        }
        }


    printf("\n");
    T--;



    }

}
