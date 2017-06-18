#include <stdio.h>
/*
        1
       / \
      2   3
     /   / \
    4   5   6
   / \  /   / \
  7  8  9  10  11

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
    p5 = createNode(5);
    p6 = createNode(6);
    p7 = createNode(7);

    p1->left = p2;
    p1->right = p3;
    p2->left = p4;
    p3->left = p5;
    p3->right = p6;
    p5->left = p7;
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

int treewidth(ptreeNode tree, int depth)
{   
    static int i;
    static int result;
    if(tree)
    {
        if(i==depth)
        {
            if(tree->left&&result==0)
            {
               // printf("%d\n", tree->left->val);
                result = tree->left->val;
            }
        }
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
            treewidth(tree->left, depth);
            i--;
        }
        if(tree->right)
        {
            treewidth(tree->right, depth);
            i--;
        }
    }
    return result;
}
int findBottomLeftValue(struct TreeNode* root) 
{
    int depth;
    int result;
    depth = treedepth(root) - 2;
    result = treewidth(root, depth);
    return result;
}
int main() 
{   
    int i;
    int result;
    ptreeNode tree;
    tree = createTree();
    result = findBottomLeftValue(tree);
    printf("%d\n", result);
} 
