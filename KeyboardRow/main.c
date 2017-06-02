#include <stdio.h>

char** findWords(char** words, int wordsSize, int* returnSize) 
{
    char alphabet[52];
    int i;
    int j;
    int flag;
    char tmpchar[2];
    alphabet['A'-'A'] = '1';  alphabet['a'-'A'] = '1';
    alphabet['S'-'A'] = '1';  alphabet['s'-'A'] = '1';
    alphabet['D'-'A'] = '1';  alphabet['d'-'A'] = '1';
    alphabet['F'-'A'] = '1';  alphabet['f'-'A'] = '1';
    alphabet['G'-'A'] = '1';  alphabet['g'-'A'] = '1';
    alphabet['H'-'A'] = '1';  alphabet['h'-'A'] = '1';
    alphabet['J'-'A'] = '1';  alphabet['j'-'A'] = '1';
    alphabet['K'-'A'] = '1';  alphabet['k'-'A'] = '1';
    alphabet['L'-'A'] = '1';  alphabet['l'-'A'] = '1';
    alphabet['Q'-'A'] = '2';  alphabet['q'-'A'] = '2';
    alphabet['W'-'A'] = '2';  alphabet['w'-'A'] = '2';
    alphabet['E'-'A'] = '2';  alphabet['e'-'A'] = '2';
    alphabet['R'-'A'] = '2';  alphabet['r'-'A'] = '2';
    alphabet['T'-'A'] = '2';  alphabet['t'-'A'] = '2';
    alphabet['Y'-'A'] = '2';  alphabet['y'-'A'] = '2';
    alphabet['U'-'A'] = '2';  alphabet['u'-'A'] = '2';
    alphabet['I'-'A'] = '2';  alphabet['i'-'A'] = '2';
    alphabet['O'-'A'] = '2';  alphabet['o'-'A'] = '2';
    alphabet['P'-'A'] = '2';  alphabet['p'-'A'] = '2';
    alphabet['Z'-'A'] = '3';  alphabet['z'-'A'] = '3';
    alphabet['X'-'A'] = '3';  alphabet['x'-'A'] = '3';
    alphabet['C'-'A'] = '3';  alphabet['c'-'A'] = '3';
    alphabet['V'-'A'] = '3';  alphabet['v'-'A'] = '3';
    alphabet['B'-'A'] = '3';  alphabet['b'-'A'] = '3';
    alphabet['N'-'A'] = '3';  alphabet['n'-'A'] = '3';
    alphabet['M'-'A'] = '3';  alphabet['m'-'A'] = '3';
    for(i=0;i<wordsSize;i++)
    {
       wordlen = strlen(words[i]);
       for(j=0;j<wordlen;j++)
       {
            tmpchar[i%2] = alphabet[words[i][j]-'A'];
            if(i!=0 && (tmpchar[i%2]-tmpchar[i%2-1])!=0)
            {
                flag = 0;
                break;
            }
       }
       if(flag)
       {
             
       }
    }
    printf("%c\n", alphabet[0]);
}

int main(int argc, char *argv[])
{
    char **words;
    int returnSize;
    words = (char**)malloc(sizeof(char*)*4);
    words[0] = (char*)malloc(sizeof(char)*6);
    words[1] = (char*)malloc(sizeof(char)*7);
    words[2] = (char*)malloc(sizeof(char)*4);
    words[3] = (char*)malloc(sizeof(char)*6);
    findWords(words, 4, &returnSize); 
}
