#include <stdio.h>

char** findWords(char** words, int wordsSize, int* returnSize) 
{
    char alphabet[58];
    char** result;
    int i;
    int j;
    int flag;
    char tmpchar[2];
    int indexres[wordsSize];
    int wordlen;
    *returnSize = 0;
    alphabet['A'-'A'] = 1;  alphabet['a'-'A'] = 1;
    alphabet['S'-'A'] = 1;  alphabet['s'-'A'] = 1;
    alphabet['D'-'A'] = 1;  alphabet['d'-'A'] = 1;
    alphabet['F'-'A'] = 1;  alphabet['f'-'A'] = 1;
    alphabet['G'-'A'] = 1;  alphabet['g'-'A'] = 1;
    alphabet['H'-'A'] = 1;  alphabet['h'-'A'] = 1;
    alphabet['J'-'A'] = 1;  alphabet['j'-'A'] = 1;
    alphabet['K'-'A'] = 1;  alphabet['k'-'A'] = 1;
    alphabet['L'-'A'] = 1;  alphabet['l'-'A'] = 1;
    alphabet['Q'-'A'] = 2;  alphabet['q'-'A'] = 2;
    alphabet['W'-'A'] = 2;  alphabet['w'-'A'] = 2;
    alphabet['E'-'A'] = 2;  alphabet['e'-'A'] = 2;
    alphabet['R'-'A'] = 2;  alphabet['r'-'A'] = 2;
    alphabet['T'-'A'] = 2;  alphabet['t'-'A'] = 2;
    alphabet['Y'-'A'] = 2;  alphabet['y'-'A'] = 2;
    alphabet['U'-'A'] = 2;  alphabet['u'-'A'] = 2;
    alphabet['I'-'A'] = 2;  alphabet['i'-'A'] = 2;
    alphabet['O'-'A'] = 2;  alphabet['o'-'A'] = 2;
    alphabet['P'-'A'] = 2;  alphabet['p'-'A'] = 2;
    alphabet['Z'-'A'] = 3;  alphabet['z'-'A'] = 3;
    alphabet['X'-'A'] = 3;  alphabet['x'-'A'] = 3;
    alphabet['C'-'A'] = 3;  alphabet['c'-'A'] = 3;
    alphabet['V'-'A'] = 3;  alphabet['v'-'A'] = 3;
    alphabet['B'-'A'] = 3;  alphabet['b'-'A'] = 3;
    alphabet['N'-'A'] = 3;  alphabet['n'-'A'] = 3;
    alphabet['M'-'A'] = 3;  alphabet['m'-'A'] = 3;
    for(i=0;i<wordsSize;i++)
    {
       indexres[i] = 0;
       wordlen = strlen(words[i]);
       flag = 1;
       for(j=0;j<wordlen;j++)
       {
            tmpchar[j%2] = alphabet[words[i][j]-'A'];
            if(j!=0 && (tmpchar[j%2+1]-tmpchar[j%2])!=0)
            {
                flag = 0;
                break;
            }
       }
       if(flag)
       {
             indexres[*returnSize] = i ;
            *returnSize = *returnSize + 1;
       }
    }
    result = (char**)malloc(sizeof(char*)*(*returnSize));
    for(i=0;i<*returnSize;i++)
    {
        result[i] = (char*)malloc(sizeof(char)*(strlen(words[indexres[i]])+1));
        memcpy(result[i], words[indexres[i]], strlen(words[indexres[i]]));
    }
    return result;
}

int main(int argc, char *argv[])
{
    char **words;
    int returnSize;
    int **result;
    int i;
    words = (char**)malloc(sizeof(char*)*4);
    words[0] = (char*)malloc(sizeof(char)*6);
    words[1] = (char*)malloc(sizeof(char)*7);
    words[2] = (char*)malloc(sizeof(char)*4);
    words[3] = (char*)malloc(sizeof(char)*6);
    memcpy(words[0], "hello", strlen("hello"));    
    memcpy(words[1], "Alaska", strlen("Alaska"));    
    memcpy(words[2], "Dad", strlen("Dad"));    
    memcpy(words[3], "Peace", strlen("Peace"));    
    result = findWords(words, 4, &returnSize); 
    for(i=0;i<returnSize;i++)
    {
        printf("%s\n", result[i]);
    }
}
