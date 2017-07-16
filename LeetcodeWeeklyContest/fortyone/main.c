#include <stdio.h>
double findMaxAverage(int* nums, int numsSize, int k) 
{
    int i;
    int j;
    int sum1 = -2147483648;
    int sum2 = 0;
    double result1;
    double result2 = -2147483648;
    for(;k<=numsSize;k++)
    {
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
        result1 = (double)sum1/k;
        if(result1 > result2)
        {
            result2 = result1;
        }
    }
    //printf("%f\n", result2);
    return result2;
}
int main()
{
    double result;
    int nums[6] = {1,12,-5,-6,50,3};
    result = findMaxAverage(nums, 6, 4);
    printf("%f\n", result);
}
