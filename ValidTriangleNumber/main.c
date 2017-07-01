#include <stdio.h>

int triangleNumber(int* nums, int numsSize) 
{
   int result = 0;
   int i,j,k;
   for(i=0;i<numsSize;i++)
   {
       for(j=i+1;j<numsSize;j++)
       {
            for(k=j+1;k<numsSize;k++)
            {
                if(nums[k]<(nums[i]+nums[j]) && nums[k]>abs(nums[i]-nums[j]))  
                    result++;
            }
       }
    
   }
   return result;
}

int main() 
{   
    int result;
    int nums[4] = {2, 2, 3, 4};
    result = triangleNumber(nums, 4);
    printf("%d\n", result);
} 
