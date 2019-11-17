#include <stdio.h>

int calPoints(char ** ops, int opsSize){
	int res = 0;
	int tmpx = 0;
	int tmp[1000] = {0};
	int last = 0;
	int i = 0;
	int j = 0;
	for(i=0; i<opsSize; i++){
		if(!strcmp(ops[i], "C")){
			res = res - last;	
			j--;
			last = tmp[j-1];
		}
		else if(!strcmp(ops[i], "D")){
			tmpx = tmp[j-1] *2;
			res = res + tmpx;
			tmp[j] = tmpx;
			j++;
			last = tmpx;
		}
		else if(!strcmp(ops[i], "+")){
			tmpx = tmp[j-1] + tmp[j-2];
			res = res + tmpx;
			tmp[j] = tmpx;
			j++;
			last = tmpx;
			
		}
		else{
			last = 	atoi(ops[i]);
			res = res + last;
			tmp[j] = last;
			j++;
		}
	}
	return res;
}

int main(int argc, char *argv[])
{
	//char tmp[] = {'5','2','4','C','D','9','+','+'};
	char tmp[] = {'4','D','D','C','D','0','0','0'};
	//char tmp[] = {'5','2','4','C','D','0','+','+'};
	char **ops;
	ops = malloc(sizeof(int *)*8);
	int i;
	int res;
	for(i=0; i<8; i++){
		if(i==11){
			ops[i] = malloc(3);
			ops[i][0] = '-'; 
			ops[i][1] = tmp[i]; 
			ops[i][2] = '\0'; 
		}
		else{
			ops[i] = (char*)malloc(2);
			ops[i][0] = tmp[i]; 
			ops[i][2] = '\0'; 
		}
	}
	res = calPoints(ops, 8);
	printf("%d\n", res);

}
