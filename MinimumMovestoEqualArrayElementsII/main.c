#include <stdio.h>
void sort(int *arr, int sz)
{
    int i = 0;
    int j = 0;
	int tmp;
    for(i=0;i<sz-1;i++)
    {
        for(j=0;j<sz-i-1;j++)
        {
            if(arr[j]>arr[j+1])
			{
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            } 
        }
    }
}
int minMoves2(int* nums, int numsSize)  
{
   int i;
   int result;
   int average;
   sort(nums, numsSize);
   average = nums[numsSize/2];
   for(i=0;i<numsSize;i++)
   {
       result = result + abs(nums[i]-average);
   }
   return result;
}
int main() 
{     
   int result;
   int *nums;
   int numsSize = 3;
   nums = (int *)malloc(sizeof(int)*numsSize); 
   nums[0] = 1;
   nums[1] = 2;
   nums[2] = 3;
   result = minMoves2(nums, numsSize);
   printf("%d\n", result);
   
} 
