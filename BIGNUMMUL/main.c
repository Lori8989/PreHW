#include <stdio.h>
#define BIGINT_WIDTH 4
#define BIGINT_BASE 10000
#define DIGIT_NUM 16
#define NUM_SIZE (DIGIT_NUM/BIGINT_WIDTH)//4
#define ANS_SIZE (NUM_SIZE*2)//8​
int main()
{
    int num[NUM_SIZE] = {0}; // store input number (under base 10000)
    int ans[ANS_SIZE] = {0}; // store answer (under base 10000)
    char input[DIGIT_NUM];   // store input number (under base 10)
    // input : input 16-digit number to a char array (under base 10)
    for(int i = 0; i < DIGIT_NUM; i++)
        scanf("%c",&input[i]);
    // convert from base 10 to base 10000
    for(int d = 0; d < DIGIT_NUM; d++)
    {
        int num_idx = (DIGIT_NUM-d-1)/BIGINT_WIDTH;//16-d-1/4
        num[num_idx] *= 10;
        num[num_idx] += input[d]-'0';
    }
    // TODO: multiplication
    for(int up = 0; up < NUM_SIZE; up++)//4
        for(int down = 0; down < NUM_SIZE; down++)//4
            ans[up+down] += num[down]*num[up];
    for(int d = 0; d < ANS_SIZE-1; d++)//8=1ANS_SIZE
    {
        ans[d+1]+=ans[d]/10000;
        ans[d]%=10000;
    }
    printf("%4d", ans[ANS_SIZE-1]);
    for(int d = ANS_SIZE-2; d >= 0; d--) printf("%04d", ans[d]);
    printf("\n");
    return 0;
}
