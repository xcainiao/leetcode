#include <stdio.h>

char* getHint(char* secret, char* guess) {
    char *result;
    int index;
    int tmp; 
    int tmp1[10];
    int tmp2[10];

    int length;
    int i,j;
    int A = 0;
    int B = 0;
    
    for(i=0;i<10;i++)
    {
        tmp1[i] = -1;
    }

    for(i=0;i<10;i++)
    {
        tmp2[i] = -1;
    }

    length = strlen(secret);
    for(i=0;i<length;i++)
    {
        tmp1[secret[i]-'0']++;
        tmp2[guess[i]-'0']++;
        for(j=0;j<length;j++)
        {
            if(secret[i]==guess[j]) 
            {
                if(i==j)
                {
                    A++;
                }
            }
        }
    }
    for(i=0;i<10;i++)
    {
            tmp = tmp1[i]>tmp2[i]?tmp2[i]:tmp1[i];
            if(tmp>=0)
                B = B + tmp + 1;
            //printf("---------------\n");
            //printf("%d\n", B);
    }
    B--; 
    result = (char*)malloc(sizeof(char)*20);
    index = sprintf(result, "%d", A);
    index += sprintf(result+index, "%s", "A");
    index += sprintf(result+index, "%d", B);
    index += sprintf(result+index, "%s", "B");
    return result;
}

int main() 
{   
    int* result;
    result = getHint("1123", "0111");
    printf("%s\n", result);
} 
