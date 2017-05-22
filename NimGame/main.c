#include <stdio.h>

#define bool int

bool canWinNim(int n) 
{
    return n%4;    
}

int main(int argc, char *argv[])
{
	int n = 15;
    int result;
    result = canWinNim(n);
    printf("%d\n", result);
}
