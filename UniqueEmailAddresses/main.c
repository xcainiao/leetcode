#include <stdio.h>

int numUniqueEmails(char ** emails, int emailsSize){
	int res =0;
	int i = 0, j = 0, k=0, pk = 0;
	char **tmp;
	tmp = (char **)malloc(sizeof(char*)*emailsSize);
	for(i=0; i<emailsSize; i++){
		tmp[i] = (char *)malloc(101);
	}
    
	for(i=0; i<emailsSize; i++){
		k = 0;
		j = 0;
		pk = 0;
		while(emails[i][j]){

			if(emails[i][j]=='@'){
				pk = 1;
			}
			if(emails[i][j]=='+'){
				pk = 1;
				while(emails[i][j]!='@')
					j++;
			}
			if(emails[i][j]=='.' && !pk){
				j++;
				continue;
			}
			tmp[i][k] = emails[i][j];
			k++;
			j++;

		}
        tmp[i][k] = emails[i][j];
	}


	for(i=0; i<emailsSize; i++){
		for(j=i+1; j<emailsSize; j++){
			if(!strcmp(tmp[i], tmp[j])){
				tmp[i][0] = '\0';
			}

		}
	}

    for(i=0; i<emailsSize; i++){
		if(tmp[i][0])
                	res++;

	}
    
	return res;

}


int main(int argc, char *argv[])
{
	int res;
	char *tmp1 = "test.email+alex@leetcode.com";
	char *tmp2 = "test.email@leetcode.com";
	char **email;
	email = (char **)malloc(sizeof(char *)*2);
	email[0] = tmp1;
	email[1] = tmp2;
	res = numUniqueEmails(email, 2);
	printf("%d\n", res);

}
