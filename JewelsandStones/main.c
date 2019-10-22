#include <stdio.h>

int numJewelsInStones(char * J, char * S){
    int res = 0;
    int i, j;
    for(j=0; j<strlen(J); j++){
        for(i=0; i<strlen(S); i++){
            if(J[j]==S[i])
                res++;
        }
    }
    return res;
}


int main(int argc, char *argv[])
{
	char *J = "aA";
    char *S = "aAAbbbb";
    printf("%d\n", numJewelsInStones(J, S));
}
