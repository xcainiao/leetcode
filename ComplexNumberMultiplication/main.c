#include <stdio.h>
char* complexNumberMultiply(char* a, char* b) {
    	
	int tmp1;
	int tmp2;
	int tmpi1;
	int tmpi2;
	int sum;
	int sumi;
	
	int rtmp1;	
	int rtmp2;	
	char *result;	
	
	char *p1;
    	char *p2;
	char *i1;
	char *i2;
	int num1;	
	int num2;
	int numi1;
	int numi2;
	p1 = strchr(a, '+');
	p2 = strchr(b, '+');
	*p1 = NULL;
	*p2 = NULL;
	tmp1 = atoi(a);
	tmp2 = atoi(b);
	num1 = tmp1*tmp2;
	*p1 = '+';
	*p2 = '+';
	i1 = strchr(a, 'i');
	i2 = strchr(b, 'i');
	*i1 = NULL;
	*i2 = NULL;
	tmpi1 = atoi(p1+1);
	tmpi2 = atoi(p2+1);
	num2 = 	tmpi1 * tmpi2;
	sum = num1 - num2;
	numi1 = tmp1*tmpi2;
	numi2 = tmp2*tmpi1; 	
	sumi = numi1 + numi2;
	result = (char*)malloc(sizeof(int)*100);
	memset(result, 0, 100);
	rtmp1 = sprintf(result, "%d", sum);
	sprintf(result+rtmp1, "%s", "+");
	rtmp2 = sprintf(result+rtmp1+1, "%d", sumi);
	sprintf(result+rtmp1+1+rtmp2, "%s", "i");
	return result;
}

int main(int argc, char *argv[])
{
	int result;
	char *p;
	char a[] = "1+-1i";
	char b[] = "1+-1i";
	p = complexNumberMultiply(a, b);
	printf("%s\n", p);
}
