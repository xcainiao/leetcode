#include <stdio.h>

int missingNumber(int* nums, int numsSize) 
{
    int i;
    int n = 0;
    for(i=0;i<numsSize;i++)
    {   
        n = n^i^nums[i];
    }   
    n = n^numsSize;
    return n;

}

int main(int argc, char *argv[])
{
	int result;
	int nums[3] = {0, 1, 3};
	int len;
    len = sizeof(nums)/sizeof(int);
	result = missingNumber(nums, len);  
	printf("%d\n", result);
}
