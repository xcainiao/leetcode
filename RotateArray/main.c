#include <stdio.h>

void rotate(int* nums, int numsSize, int k) {
    int tmp[numsSize];
    int i;
    while(k>numsSize)
    {
        k = k-numsSize;
    }
    for(i=0;i<numsSize;i++)
    {   
        //tmp[i] = nums[i];
        if(numsSize-k+i < numsSize)
        {
            tmp[i] = nums[numsSize-k+i];
        }
        else
        {
            tmp[i] = nums[i-k];
        }   
    }   
    for(i=0;i<numsSize;i++)
    {   
        nums[i] = tmp[i];
    }
}

int main() 
{   
    int nums[7] = {1, 2, 3, 4, 5, 6, 7};
    int i;
    rotate(nums, 7, 3);
    for(i=0;i<7;i++)
    {
        printf("%d\n", nums[i]);
    }
} 
