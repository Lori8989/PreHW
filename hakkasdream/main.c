#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int t,i;
    double a,b,tol;
    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%lf %lf",&a,&b);

        tol = round( 10000*(b-a)/a )/100.00;

        if(tol>=5.00){
            printf("%7.2lf%% (#`Д´)ﾉ\n",tol);
            }
        else if (-5.00<=tol&&tol<5.00){
                if(tol==0.00)
                printf("   0.00%% \\^o^/\n");
                else
                    printf("%7.2lf%% \\^o^/\n",tol);
        }
        else{
            printf("%7.2lf%% (ゝ∀･)b\n",tol);


            }
        }
}

