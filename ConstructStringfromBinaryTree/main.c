#include <stdio.h>
/*
        1
       / \
      2   3
     /   / \
    4   5   6
   / \  /   / \
  7  8  9  10  11

        3
       /  \
      1    5
     / \   / \
    0   2 4   6
          
           
*/
typedef struct TreeNode  {
 int val;
 struct TreeNode  *left;
 struct TreeNode  *right;
} treeNode, *ptreeNode;


treeNode* createNode(int val)
{
    ptreeNode node; 
    node = (ptreeNode)malloc(sizeof(treeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}
treeNode* createTree()
{
    ptreeNode p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11;
    p1 = createNode(1);
    p2 = createNode(2);
    p3 = createNode(3);
    p4 = createNode(4);
    /*
    p5 = createNode(2);
    p6 = createNode(4);
    p7 = createNode(6);
    */
    p1->left = p2;
    p1->right = p3;
    p2->left = p4;
    return p1;
}

int i = 0;
void preorder(struct TreeNode* root, char* result, int flag)
{
    if(!flag)
        i = 0;
    if(!root)
    {
        result[i] = '(';
        result[i+1] = ')';
        i = i+2;
        //printf("()");
    }
    if(root)
    {
        //printf("(");
        result[i] = '(';
        i = i+1;
        i = i + sprintf(result+i, "%d", root->val);
        //printf("%d", root->val);
        preorder(root->left, result, 1);
        preorder(root->right, result, 1);
        //printf(")");
        result[i] = ')';
        i = i+1;
    }
}

char* tree2str(struct TreeNode* root)  
{
    int j,k;
    char *result;
    char *result2;
    result = (char*)malloc(10000);
    result2 = (char*)malloc(10000);
    preorder(root, result, 0);
    result[i] = '\0';
    printf("%s\n", result);
    k = 0;
    for(j=1;j<strlen(result)-1; j++)
    {
        if(result[j]== '(' && result[j+1]== ')' && result[j+2]== '(' && result[j+3]== ')')
        {
            j = j+3;
        }
        else if(result[j]== '(' && result[j+1]== ')' && result[j+2]== ')')
        {
            j = j+1;
        }
        else
        {
            result2[k] = result[j];
            k++;
        }
    }
    //return result2;
    printf("%s\n", result2);
}


int main() 
{   
    int i;
    int size;
    int *result;
    ptreeNode tree;
    tree = createTree();
    tree2str(tree);
} 
