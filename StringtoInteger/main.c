#include <stdio.h>
#define bool int

int myAtoi(char* str) 
{
    int i=0;
    int length = strlen(str);
    long result = 0;
    int flag = 0;
    while(str[i]==' ')
    {
        i++;
    }
    if(str[i]=='+' &&(str[i+1]>='0' && str[i+1]<='9'))
    {
        i = i+1;
    }
    if(str[i]=='-' &&(str[i+1]>='0' && str[i+1]<='9'))
    {
        flag = 1;
        i = i+1;
    }
    //printf("%d\n", flag);
    for(;i<length;i++)
    {
        if(str[i]<'0' || str[i]>'9')
            break;
        result = result*10 + str[i]-'0';
        if(flag)
        {
            if(result >= 2147483649)
                return -2147483648;
        }
        else
        { 
            if(result >= 2147483648)
                return 2147483647;
        }
    }
    if(flag)
    {
        //printf("xxxxxxxxxxxxxxxxxxx\n");
        //printf("%ld\n", result); 
        return -result;
    }
    
    //printf("xxxxxxxxxxxxxxxxxxx\n");
    return result;
}

int main() 
{   
    int result;
    char str[] = "123";
	result = myAtoi(str);
    printf("%d\n", result);
} 
