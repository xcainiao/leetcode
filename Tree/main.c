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
 struct TreeNode *left;
 struct TreeNode *right;
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
    p8 = createNode(8);
    p9 = createNode(9);
    p10 = createNode(10);
    p11 = createNode(11);

    p1->left = p2;
    p1->right = p3;
    p2->left = p4;
    p3->left = p5;
    p3->right = p6;
    p4->left = p7;
    p4->right = p8;
    p5->left = p9;
    p6->left = p10;
    p6->right = p11;
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
void inorder(ptreeNode tree)
{
    if(tree)
    {
        inorder(tree->left);
        printf("%d\n", tree->val);
        inorder(tree->right);
    }
}
void lastorder(ptreeNode tree)
{
    if(tree)
    {
        inorder(tree->left);
        inorder(tree->right);
        printf("%d\n", tree->val);
    }
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
int a[10] = {0};
int i = 0;
int treewidth(ptreeNode tree)
{   
    if(tree)
    {
        if(i==0)
        {
            a[i] = 1;
            i++;
            if(tree->left)
                a[i]++;
            if(tree->right)
                a[i]++;
        }
        else
        {
            i++;
            if(tree->left)
                a[i]++;
            if(tree->right)
                a[i]++;
        }
        if(tree->left)
        {
            treewidth(tree->left);
            i--;
        }
        if(tree->right)
        {
            treewidth(tree->right);
            i--;
        }
    }
}
int main() 
{   
    int depth;
    int i;

    ptreeNode tree;
    tree = createTree();
    //preorder(tree);
    //inorder(tree);
    //lastorder(tree);
    //depth = treedepth(tree);
    //printf("%d\n", depth);
    treewidth(tree);
    for(i=0;i<10;i++)
    {
        printf("%d\n", a[i]);
    }
} 
