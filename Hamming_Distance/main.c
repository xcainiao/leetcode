#include <stdio.h>
int hammingDistance(int x, int y);
int main(int argc, char *argv[])
{
    printf("%d\n", hammingDistance(1, 4));
}
int hammingDistance(int x, int y) 
{
    int num = 1;
    int z;
    int check = 0;
    z = x^y;
    for(;z!=0;)
    {
        if(num&z)
            check ++;
        z = z >> 1;
    }
    return check;
}
