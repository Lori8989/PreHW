#include <stdio.h>
#include <stdlib.h>

int main()
{
    char card[5][3];

    int n,t,k;
    scanf("%d",&n);

    while(n>0){
        int num[5]={0};

        scanf(" %s %s %s %s %s", &card[0], &card[1], &card[2], &card[3], &card[4]);

        for(t=0;t<5;t++){
            for(k=0;k<5;k++){
                if(card[t][0]==card[k][0])
                    num[t]++;
            }
        }
        int flag =0;
        for(t=0;t<5;t++){
            if(num[t]==3&&num[0]+num[1]+num[2]+num[3]+num[4]==13){
                printf("YES\n");
                flag =1;
                break;
            }
        }
        if(flag==0)
            printf("NO\n");

        n--;
    }

}
