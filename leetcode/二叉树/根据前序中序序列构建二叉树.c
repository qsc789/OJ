//力扣105
//题目链接：https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal
//题解链接：https://github.com/qsc789/LeetCode-Book/blob/main/selected_coding_interview/docs/105.%20%E4%BB%8E%E5%89%8D%E5%BA%8F%E4%B8%8E%E4%B8%AD%E5%BA%8F%E9%81%8D%E5%8E%86%E5%BA%8F%E5%88%97%E6%9E%84%E9%80%A0%E4%BA%8C%E5%8F%89%E6%A0%91.md
//给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历， inorder 是同一棵树的中序遍历，请构造二叉树并返回其根节点。
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

//重点是如何分割两个序列
int find(int target,int* num)//找相同元素下标
{
    int res=0;
    while(num[res]!=target)
    {
        res++;
    }
    return res;
}
struct TreeNode* create(int* preorder,int prestart,int preend,int* inorder,int instart,int inend)
{
    if(prestart>preend||instart>inend)
    {
        return NULL;
    }
    struct TreeNode* tmp=(struct TreeNode*)malloc(sizeof(struct TreeNode));
    tmp->val=preorder[prestart];
    int num=find(preorder[prestart],inorder);
    tmp->left=create(preorder,prestart+1,prestart+num-instart,inorder,instart,num-1);//构建左子树
    tmp->right=create(preorder,prestart+num-instart+1,preend,inorder,num+1,inend);//构建右子树
    return tmp;
}
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    int prestart=0,preend=preorderSize-1;
    int instart=0,inend=inorderSize-1;
    struct TreeNode*root=create(preorder,prestart,preend,inorder,instart,inend);
    return root;
}