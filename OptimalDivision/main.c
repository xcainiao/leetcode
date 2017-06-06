#include <stdio.h>
// num1 / (num2/num3/num4/num5)
int leftcount = 0;
int rightcount = 0;

char* optimalDivision(int* nums, int numsSize) 
{
    char *result;
    char tmp[5];
    int i;
    result = (char*)malloc(sizeof(char)*100);
    memset(result, NULL, 100);
    for(i=0;i<numsSize;i++)
    {
        sprintf(tmp, "%d", nums[i]);
        strcat(result, tmp);
        if(i!=numsSize-1)
            strcat(result, "/");
        if(i==0&&numsSize>2)
        {
            strcat(result, "(");
        }
    }
    if(numsSize>2)
        strcat(result, ")");
    return result;
}

int main(int argc, char *argv[])
{
    char* result;
    int nums[2] = {2, 2};
    int numsSize = 2;
    result = optimalDivision(nums, numsSize); 
    printf("%s\n", result);
}
