#include <stdio.h>
int findComplement(int num) 
{
    int out = 0;
    int xx = num;
    int check = 0;
    while(xx != 0)
    {   
        xx = xx >>1;
        check = check << 1;
        check = check | 1;
    }   
    out = num^check;
    return out;

}

void main()
{
	int result;
	result = findComplement(5);
	printf("%d\n", result);
}
