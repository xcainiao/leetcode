#include <stdio.h>

int getSum(int a, int b) 
{
    int i=1;
    int x;
    int y;
    int res;
    while(i)
    {
        x = (a&b)<<1;
        y = a^b;
        a = x;
        b = y;
        i = a&b;
        res = x|y;
    }
    return res;
}

int main(int argc, char *argv[])
{
	int result;
	result = getSum(10, 11);
	printf("%d\n", result);
}
