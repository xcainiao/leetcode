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
    p1 = createNode(3);
    p2 = createNode(1);
    p3 = createNode(5);
    p4 = createNode(0);
    p5 = createNode(2);
    p6 = createNode(4);
    p7 = createNode(6);

    p1->left = p2;
    p1->right = p3;
    p2->left = p4;
    p2->right = p5;
    p3->left = p6;
    p3->right = p7;
    return p1;
}



struct TreeNode* mergeTrees2(struct TreeNode* t1, struct TreeNode* t2, int flag) 
{
    if(!flag)
        t1->val = t1->val + t2->val;
    if(t1&&t2)
    {   
        if(!t1->left&&t2->left)
        {   
            t1->left = t2->left;
            t2->left = NULL;
        }   
        if(!t1->right&&t2->right)
        {   
            t1->right = t2->right;
            t2->right = NULL;
        }
        if(t1->left&&t2->left)
        {
            t1->left->val = t1->left->val + t2->left->val;
        }
        if(t1->right&&t2->right)
        {
            t1->right->val = t1->right->val + t2->right->val;
        }
        mergeTrees2(t1->left, t2->left, 1);
        mergeTrees2(t1->right, t2->right, 1);
    }
    return t1; 
}
struct TreeNode* mergeTrees(struct TreeNode* t1, struct TreeNode* t2) 
{
    if(!t1)
        return t2;
    if(!t2)
        return t1;
    mergeTrees2(t1, t2, 0);
    return t1; 
}



int main() 
{   
    int i;
    int result;
    ptreeNode tree;
    tree = createTree();
    mergeTrees(tree, tree);
    printf("%d\n", result);
} 
