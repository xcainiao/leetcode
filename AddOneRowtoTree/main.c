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
void preorder(ptreeNode tree)
{
    if(tree)
    {   
        printf("%d\n", tree->val);  
        preorder(tree->left);
        preorder(tree->right);
    }   
}
void addnode(struct TreeNode* tree, int val)
{
    struct TreeNode* new1;
    struct TreeNode* new2;
    new1 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    new2 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    new1->left = tree->left;
    new1->right = NULL;
    new1->val = val;
    new2->right = tree->right;
    new2->left = NULL;
    new2->val = val;
    tree->left = new1;
    tree->right = new2;
}
struct TreeNode* addrootnode(struct TreeNode* tree, int val)
{
    struct TreeNode* new1;
    new1 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    new1->left = tree;
    new1->right = NULL;
    new1->val = val;
    return new1;
}
int i = 0;
struct TreeNode* treewidth(struct TreeNode* tree, int v, int d, int flag)
{
    if(!flag)
    {
        flag=1;
        i = 0;
    }
    if(d==1)
    {
        return addrootnode(tree, v);
    }
    if(tree)
    {
        if(i==(d-2))
        {
            addnode(tree, v);
        }
        i++;
        if(tree->left)
        {
            treewidth(tree->left, v, d, 1);
            i--;
        }
        if(tree->right)
        {
            treewidth(tree->right, v, d, 1);
            i--;
        }
    }
    return tree;
}
struct TreeNode* addOneRow(struct TreeNode* root, int v, int d)
{
    struct TreeNode* result;
    result = treewidth(root, v, d, 0);
    return result;
}
int main() 
{   
    int i;
    int v = 1;
    int d = 2;
    struct TreeNode* result;
    ptreeNode tree;
    tree = createTree();
    result = addOneRow(tree, v, d);
} 
