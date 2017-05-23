#include <stdio.h>

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) 
{
    int i;
    int j;
    int tmp;
    int k=0;
    int *res = NULL;
    if(nums1Size==0 || nums2Size==0)
        return NULL;
    int tmp1[nums2Size];
    for (i= 0; i<nums2Size; i++)  
    {   
        for (j=i + 1; j < nums2Size; j++)  
        {
            if (nums2[i] > nums2[j])  
            {
                tmp = nums2[i];
                nums2[i] = nums2[j];
                nums2[j] = tmp;
            }
        }
    }   
    for(i=0;i<nums2Size;i++)
    {   
        if(i==0 || nums2[i]!=nums2[i-1])
        {
            for(j=0;j<nums1Size;j++)
            {
                if(nums2[i]==nums1[j])
                {
                    tmp1[k]=nums2[i];
                    k++;
                    break;
                }
            }
        }
    }   
    res = (int *)malloc(sizeof(int)*(k+1));
    for(i=0;i<k;i++)
    {   
        res[i]=tmp1[i];
        printf("%d\n", res[i]);
    }   
    *returnSize = k;
    return res;
}

int main(int argc, char *argv[])
{
	int returnSize;
    int *result;
    
    int i;
    
    int num1[] = {1, 2, 2, 1};
	int num2[] = {2, 2};
    int len1;
    int len2;
    len1 = sizeof(num1)/sizeof(int);
    len2 = sizeof(num2)/sizeof(int);
	result = intersection(num1, len1, num2, len2, &returnSize);
    for(i=0;i<returnSize;i++)
    {
        printf("%d\n", result[i]);
    }
}
