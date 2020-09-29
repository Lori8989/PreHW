#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m,T,t,i,j,k;//T次數t第幾次
    scanf("%d",&T);
    while(T>0){
            scanf("%d %d %d",&n,&m,&t);
        if(t>=n+m||t==0){
                for(i=1;i<=n;i++){
                    printf("-");//all sit
                }
        }
        else{
            if(m+n>t&&t>m){
                for(i=0;i<t-m;i++){
                    printf("-");//sit front
                }
            }
            if(m<=t && t <= n){
                for(j=0;j<m;j++){
                    printf("^");//m stand
                }
            }
            if(0<t&&t<m){
                for(j=0;j<t;j++){
                    printf("^");//front (stand<m)
                }
            }
            if(n+m>t&&t>n){
                for(j=n+m-t;j>0;j--){
                    printf("^");//back (stand<m)
                }
            }
            if(0<t&&t<n){
            for(k=0;k<n-t;k++){
                printf("-");//sit back
            }
        }
        }
        T--;
        printf("\n");
    }
    }
