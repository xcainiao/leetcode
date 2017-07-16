#include <stdio.h>
double findMaxAverage(int* nums, int numsSize, int k) 
{
    int i;
    int j;
    int sum1 = -2147483648;
    int sum2 = 0;
    for(i=0;i<=numsSize-k;i++)
    {
        sum2 = 0;
        for(j=0;j<k;j++)
        {
            sum2 = sum2 + nums[i+j]; 
        }
        if(sum2>sum1)
        {
            sum1 = sum2;
        }
    }
    printf("%d\n", sum1);
    return (double)sum1/k;
}
int main()
{
    double result;
    int nums[1] = {5};
    result = findMaxAverage(nums, 1, 1);
    printf("%f\n", result);
}
