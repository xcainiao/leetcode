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

int i = 0;
void inorder(struct TreeNode* root, int* result, int* returnSize, int flag)
{
    if(!flag)
        i = 0;
    if(root)
    {
        *returnSize = *returnSize + 1;
        inorder(root->left, result, returnSize, 1);
        result[i] = root->val;
        i++;
        //printf("%d\n", root->val);
        inorder(root->right, result, returnSize, 1);
    }
}

void postorder(struct TreeNode* root, int* result, int* returnSize, int flag)
{
    if(!flag)
        i = 0;
    if(root)
    {
        //printf("%d\n", root->val);
        *returnSize = *returnSize + 1;
        postorder(root->left, result, returnSize, 1);
        postorder(root->right, result, returnSize, 1);
        result[i] = root->val;
        i++;
    }
}

void preorder(struct TreeNode* root, int* result, int* returnSize, int flag)
{
    if(!flag)
        i = 0;
    if(root)
    {
        result[i] = root->val;
        i++;
        //printf("%d\n", root->val);
        *returnSize = *returnSize + 1;
        preorder(root->left, result, returnSize, 1);
        preorder(root->right, result, returnSize, 1);
    }
}


void preordernorec(struct TreeNode* root)  
{  
    ptreeNode p = root;  
    ptreeNode stack[30];  
    int num=0;  
    while(NULL!=p||num>0)  
    {  
        while(NULL!=p)  
        {  
            printf("%d\n",p->val);  
            stack[num++]=p;  
            p=p->left;  
        }  
        num--;  
        p=stack[num];  
        p=p->right;  
    }  
}  

void inordernorec(struct TreeNode* root)  
{  
    ptreeNode p = root;  
    ptreeNode stack[30];  
    int num=0;  
    while(NULL!=p||num>0)  
    {  
        while(NULL!=p)  
        {  
            stack[num++]=p;  
            p=p->left;  
        }  
        num--;  
        p=stack[num];  
        printf("%d\n",p->val);  
        p=p->right;  
    }  
}  

void postordernorec(struct TreeNode* root)  
{  
    ptreeNode p = root;  
    ptreeNode stack[30];  
    int num=0;  
    
	ptreeNode have_visited=NULL;  
  
    while(NULL!=p||num>0)  
    {  
        while(NULL!=p)  
        {  
            stack[num++]=p;  
            p=p->left;        
        }  
        p=stack[num-1];  
        if(NULL==p->right||have_visited==p->right)  
        {  
            printf("%d\n",p->val);  
            num--;  
            have_visited=p;  
            p=NULL;  
        }  
        else  
        {  
            p=p->right;  
        }  
    }  
}  

void levelordernorec(struct TreeNode* root)  
{  
        ptreeNode stack[100];  
        int first,end;  
        first = 0, end = 0;  
        stack[end++] = root;  
        while(end > first)  
        {  
                ptreeNode temp = stack[first++];  
                printf("%d\n",temp->val);  
                if(temp->left)  
                        stack[end++] = temp->left;  
                if(temp->right)  
                        stack[end++] = temp->right;  
        }  
}  

//
int* traversal(struct TreeNode* root,  int* returnSize) 
{
    int *result;
    result = (int*)malloc(10000);
    
    printf("--------------------------递归------------------------------------\n");
    printf("--------------------------中-------------------------------\n");
    *returnSize = 0;
    inorder(root, result, returnSize, 0);
    for(i=0;i<*returnSize;i++)
    {
        printf("%d\n", result[i]); 
    }
    
    printf("--------------------------前------------------------------\n");
    *returnSize = 0;
	preorder(root, result, returnSize, 0);
    for(i=0;i<*returnSize;i++)
    {
        printf("%d\n", result[i]); 
    }

    printf("--------------------------后-------------------------------\n");
    *returnSize = 0;
    postorder(root, result, returnSize, 0);
    for(i=0;i<*returnSize;i++)
    {
        printf("%d\n", result[i]); 
    }
	
    printf("--------------------------非递归------------------------------------\n");
    printf("--------------------------前-----------------------------\n");
    preordernorec(root);	
    printf("--------------------------中-----------------------------\n");
	inordernorec(root);
    printf("--------------------------后-----------------------------\n");
	postordernorec(root);
    printf("--------------------------层-----------------------------\n");
	levelordernorec(root);
    return result;
}


int main() 
{   
    int i;
    int size;
    int *result;
    ptreeNode tree;
    tree = createTree();
    traversal(tree, &size);
} 
