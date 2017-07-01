#include <stdio.h>
#include <math.h>
char* convertToBase7(int num) 
{
    char *result;
    int tmp;
    int sum = 0;
    int i = 1;
    tmp = num / 7;
    sum = sum + num%7;
    while(tmp)
    {
        sum = sum + tmp%7 * pow(10, i);
        tmp = tmp / 7;
        i++;
    }
    result = (char*)malloc(sizeof(char)*9);
    sprintf(result, "%d", sum);
    return result;
    //printf("%d\n", sum);
}

int main() 
{   
    char* result;
    result = convertToBase7(-7);
    printf("%s\n", result);
} 
