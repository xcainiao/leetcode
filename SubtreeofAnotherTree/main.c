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
    return p1;
}

int isTrue(struct TreeNode* s, struct TreeNode* t)
{
    if(s == NULL && t == NULL)
        return 1;
    if(s != NULL && t == NULL)
        return 0;
    if(s == NULL && t != NULL)
        return 0;
    if(s->val != t->val)
        return 0;
    if(isTrue(s->left, t->left) && isTrue(s->right, t->right))
        return 1;
    else
        return 0;

}

int preorder(struct TreeNode* root, struct TreeNode* t)
{
    if(!root)
        return 0;
    if(isTrue(root, t))
        return 1;
    if(preorder(root->left, t) || preorder(root->right, t))
        return 1;
}

bool isSubtree(struct TreeNode* s, struct TreeNode* t) 
{
    return preorder(s, t);    
}

int main() 
{   
    int i;
    int size;
    int result;
    ptreeNode tree;
    tree = createTree();
    result = isSubtree(tree, tree);
    printf("%d\n", result);
} 
