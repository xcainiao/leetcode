#include <stdio.h>

int addDigits(int num) {
    if(num<10)
      return num;
    else if(num%9==0)
      return 9;
    else
      return num%9;
}

int main(int argc, char *argv[])
{
	int result;
	result = addDigits(10);
	printf("%d\n", result);
}
