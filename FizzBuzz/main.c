#include <stdio.h>

char** fizzBuzz(int n, int* returnSize) {

    int i;
    char** result = (char **)malloc(sizeof(char*)*n);
    char str[20];
    for(i=0;i<n;i++)
    {   
        result[i] = malloc(sizeof(str));
    }   
    for(i=0;i<n;i++)
    {   
        if(((i+1)%3==0)&&((i+1)%5==0))
          result[i] = "FizzBuzz";
        else if ((i+1)%5==0)
           result[i] = "Buzz";
        else if  ((i+1)%3==0)
             result[i] = "Fizz";
        else
            sprintf(result[i],"%d",i+1);

    }   
    *returnSize = n;
    return result;
}

int main(int argc, char *argv[])
{
	int i;
	int n = 15;
	int returnSize;
	char **result;
	result = fizzBuzz(n, &returnSize);
	for(i=0;i<n;i++)
	{
		printf("%s\n", result[i]);
	} 
}
