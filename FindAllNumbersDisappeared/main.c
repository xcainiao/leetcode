#include <stdio.h>

int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
      int *res;
      int i;
      int x[numsSize];
      int size = 0;
      int y = 0;
      for(i=0;i<numsSize;i++)
      {   
          x[i] = 0;
      }   
      for(i=0;i<numsSize;i++)
      {   
          if(x[nums[i]-1]==0)
              x[nums[i]-1] = nums[i];    
          else
          {
              size++;
          }
      }   
      res = (int *)malloc(sizeof(int)*numsSize);
      for(i=0;i<numsSize;i++)
      {   
          if (x[i] == 0)
          {
              res[y] = i+1;
              y++;
          }
      }   
      *returnSize = size;
      return res;
}

int main(int argc, char *argv[])
{
	int i;
    int returnSize;
	int numsSize;
	int *result;
	int *nums;
    nums = (int *)malloc(8*sizeof(int));
    nums[0] = 4;
    nums[1] = 3;
    nums[2] = 2;
    nums[3] = 7;
    nums[4] = 8;
    nums[5] = 2;
    nums[6] = 3;
    nums[7] = 1;
    numsSize = 8;
    result = findDisappearedNumbers(nums, numsSize, &returnSize);
    for(i=0;i<returnSize;i++)
    {
        printf("%d\n",result[i]);
    }
}
