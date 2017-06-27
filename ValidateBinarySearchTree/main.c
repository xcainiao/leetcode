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
#define bool int
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
    ptreeNode p1,p2,p3,p4,p5;
    p1 = createNode(3);
    p2 = createNode(30);
    p3 = createNode(10);
    p4 = createNode(15);
    p5 = createNode(16);

    p1->right = p2;
    p2->left = p3;
    p3->right = p4;
    p4->right = p5;
    
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
void inorder(struct TreeNode * root, int * stack, int * top)
{
    if(!root) return;
    inorder(root->left, stack, top);
    stack[(*top)++] = root->val;
    inorder(root->right, stack, top);
}
bool isValidBST(struct TreeNode *root)
{
    int stack[10000];
    int top = 0;
    int i;
    inorder(root, stack, &top);
    for(i = 1; i < top; ++i)
    {
        if(stack[i] <= stack[i - 1]) 
            return 0;
    }
    return 1;
}
int main() 
{   
    int i;
    int result;
    int size;
    ptreeNode tree;
    tree = createTree();
    result = isValidBST(tree);
    printf("%d\n", result);
} 
