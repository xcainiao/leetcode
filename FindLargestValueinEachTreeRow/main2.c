#include <stdio.h>
/*
        1
       / \
      2   3
     /   / \
    4   5   6
      /    
     7   

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
    ptreeNode p1,p2,p3;
    p1 = createNode(1);
    p2 = createNode(2);
    p3 = createNode(3);

    p1->left = p2;
    p1->right = p3;
    return p1;
}

int treedepth(ptreeNode tree)
{
    int rightdepth = 0;
    int leftdepth = 0;
    if(!tree)
        return 0;
    leftdepth = treedepth(tree->left);
    rightdepth = treedepth(tree->right);
    return leftdepth>rightdepth?leftdepth+1:rightdepth+1;
}

int treewidth(ptreeNode tree, int* maxnum)
{   
    static int i;
    if(tree)
    {
        if(maxnum[i]<tree->val)
            maxnum[i] = tree->val;
        if(i==0)
        {
            i++;
        }
        else
        {
            i++;
        }
        if(tree->left)
        {
            treewidth(tree->left, maxnum);
            i--;
        }
        if(tree->right)
        {
            treewidth(tree->right, maxnum);
            i--;
        }
    }
}
int* largestValues(struct TreeNode* root, int *returnSize) 
{
    int depth;
    int result;
    int *maxnum;
    int i;
    depth = treedepth(root);
    *returnSize = depth;
    maxnum = (int*)malloc(sizeof(int)*depth);
    for(i=0;i<depth;i++)
    {
        maxnum[i] = -2147483648;
    }
    treewidth(root,maxnum);
    return maxnum;
}
int main() 
{   
    int i;
    int *result;
    int size;
    ptreeNode tree;
    tree = createTree();
    result = largestValues(tree, &size);
    for(i=0;i<size;i++)
    {
        printf("%d\n", result[i]);
    }
} 
