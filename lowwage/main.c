#include <stdio.h>
#include <stdlib.h>

int main()
{
    int h,m,s,H1,M1,S1,H2,M2,S2,x;//x=hour wage
    scanf(" %d ",&x);
    scanf("%d:%d:%d ~ %d:%d:%d",&H1,&M1,&S1,&H2,&M2,&S2);
    h=H2-H1;
    m=M2-M1;
    s=S2-S1;
    if(s<0){
        m=m-1;s=s+60;
    }
    if(m<0){
        h=h-1;m=m+60;
    }
    int wage=h*x;
    printf("Working Time: %d Hour(s) %d Minute(s) %d Second(s)\n",h,m,s);
    printf("Daily Wage: %d TWD\n",wage);
    return 0;
}
