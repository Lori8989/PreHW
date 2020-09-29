#include <stdio.h>
#include <stdlib.h>

int main()
{
    int b[12];
    int a,i=0,k;
    scanf("%d",&a);
    if (a==0){
        printf("1 0");
    }
    else{
            while(a>0){
                b[i]=a%2;
                a/=2;
                i++;
            }//binary
            i--;
            k=i;
        b[0]++;//+1
        int cnt=0;
        i=0;
        while(b[i]==2){
            b[i]=b[i]%2;
            b[i+1]++;
            cnt++;
            i++;
        }//carry
        if(i>k)
        {
            k++;
            b[k]=1;
        }//+1 carry
        while(k>=0){
            printf("%d",b[k]);
            k--;
        }
        printf(" %d",cnt);
        }

    }


