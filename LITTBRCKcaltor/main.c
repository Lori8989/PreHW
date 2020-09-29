#include <stdio.h>
#include <string.h>

#define maxn 1000

char input[1000010];
int solver(int **ptr, int *sum, char *s)
{
  int len=strlen(s);
  int j=0;
  for(int i=0;i<len;i++){
    if(isdigit(s[i])){
        while(isdigit(s[i])){
                *ptr[j]=*ptr[j]*10+s[i]-'0';
                i++;
            }
        j++;
    }
    else{
        if(s[i]=='-'&&isdigit(s[i+1])){
            while(isdigit(s[i+1])){
                *ptr[j]=*ptr[j]*10+s[i+1]-'0';
                i++;
            }
            *ptr[j]=0-*ptr[j];
            j++;
        }
    }
  }
  for(int i=0;i<j;i++){
    if(flag[i]==1){
        *sum-=*ptr[i];
    }
    else{
        *sum+=*ptr[i];
    }
  }
    return j;
}
int main() {
    int sum = 0;
    int a[maxn];
    int *ptr[maxn];

    for (int i = 0; i < maxn; i++) {
        a[i] = 0;
        ptr[i] = &a[i];
    }//ptr[i]=0;

    scanf("%s", input);
    int n = solver(ptr, &sum, input);
    printf("%d", a[0]);
    for (int i = 1; i < n; i++)
        printf(" %d", a[i]);
    printf("\n%d\n", sum);
    return 0;
}
