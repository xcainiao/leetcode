#include <stdio.h>

int fib(int N){
    if(N<=1)
        return N;
    return fib(N-1)+fib(N-2);
}


int main(int argc, char *argv[])
{
    int res;
    int N = 4;
    printf("%d\n",  fib(N));
}
