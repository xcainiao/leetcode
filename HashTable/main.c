#include <stdio.h>
#include <string.h>

#define HASHSIZE 101

typedef struct hashnode_
{
    char* key;
    char* value;
    struct hashnode_ *next;
} hashnode;

hashnode * hashtable[HASHSIZE] = {NULL};

/*
*
*散列函数 copy form the c programming language 
*
*/

unsigned int hash(char *s)
{
    unsigned int hashval = 0;
    for (hashval = 0; *s != '\0'; s++)
        hashval = *s + 31 * hashval;
    return hashval % HASHSIZE;
}

/*
*
*
*lookup a key in hashtable
*
*/
hashnode* lookup(char *key)
{
	int index;
	hashnode * tmp;
	index = hash(key);
	tmp = hashtable[index];
	for(tmp;tmp!=NULL;tmp=tmp->next)
	{
		if(!strcmp(key, tmp->value))
			return tmp;
	}
	return NULL;
}
/*
*
*storage value in memery
*
*/
char* stradd(char *s)
{
	int len;
	int *result;
	len = strlen(s);
	result = (char *)malloc(sizeof(char)*(len+1));
	strcpy(result, s);
	return result;
}
/*
*
*insert key->value to hashtable
*
*/
hashnode* insert(char *key, char* value)
{
	int index;
	hashnode * tmp;
	tmp = lookup(key);
	if(!tmp)
	{
		//printf("---------------------------------------------debug");
		tmp = (hashnode*)malloc(sizeof(*tmp));
		tmp->key = stradd(key);
		tmp->value = stradd(value);
		index = hash(key);
		tmp->next = NULL;
		hashtable[index] = tmp;

	}
	else
	{
		printf("already exit\n");
		return NULL;
	}
	return tmp;
}
/*
*
*get key->value form hashtable
*
*/
char* getvalue(char *key)
{
	int index;
	hashnode *tmp;
	index = hash(key);
	tmp = hashtable[index];
	if(!tmp)
		return NULL;
	return tmp->value;
}
/*
*
* print all hashtable value
*
*/
void printall()
{
	int i;
	hashnode* tmp;
	for(i=0;i<HASHSIZE;i++)
	{
		if(hashtable[i]!=NULL)
		{
			tmp = hashtable[i];
			for(tmp;tmp!=NULL;tmp=tmp->next)
			{
				printf("%s, %s\n",tmp->key, tmp->value);
			}
		}
	}
}
/*
*
* free all
*
*/
void cleanup()
{
	int i;
	hashnode* tmp, *next;
	for(i=0;i<HASHSIZE;i++)
	{
		if(hashtable[i]!=NULL)
		{
			tmp = hashtable[i];
			while(tmp)
			{
				free(tmp->value);
				free(tmp->key);
				next = tmp->next;
				free(tmp);
				tmp = next;
			}
		}
	}
}

int main() 
{     
	int i;
	char* keys[]={"name", "test1", "test2"};
	char* values[]={"Sourav", "21", "12"};   
	for(i=0;i<3;i++)
		insert(keys[i],values[i]);
	printf("%s\n", getvalue(keys[2]));
	//printall();
} 
