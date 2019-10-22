#include <stdio.h>

char * defangIPaddr(char * address){
    char *res = malloc(100);
    memset(res, '\0', 100);
    int i, j;
    j = 0;
    for(i=0; i<strlen(address); i++)
    {
        if(address[i] == '.'){
            res[j++] = '[';
            res[j++] = address[i];
            res[j++] = ']';
        }
        else{
            res[j] = address[i];
            j++;
        }
    }
    return res;
}


int main(int argc, char *argv[])
{
    char *S = "1.1.1.1";
    printf("%s\n",  defangIPaddr(S));
}
