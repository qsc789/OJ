//力扣257
//https://leetcode.cn/problems/binary-tree-paths
//给你一个二叉树的根节点 root ，按 任意顺序 ，返回所有从根节点到叶子节点的路径。
//
//叶子节点 是指没有子节点的节点。
//
//
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void ConstructPaths(struct TreeNode* root,char** paths,int* returnSize,int* arr,int top)
{
    if(root!=NULL)
    {
        if(root->left==NULL&&root->right==NULL)//root为叶子节点
        {
            char* tmp=(char*)malloc(1001);
            int len=0;
            for(int i=0;i<top;i++)
            {
                len+=sprintf(tmp+len,"%d->",arr[i]);
            }
            sprintf(tmp+len,"%d",root->val);
            paths[*returnSize]=tmp;
            (*returnSize)++;
        }
        else//root不是叶子节点
        {
            arr[top]=root->val;
            top++;
            ConstructPaths(root->left,paths,returnSize,arr,top);
            ConstructPaths(root->right,paths,returnSize,arr,top);
        }
    }
}
char** binaryTreePaths(struct TreeNode* root, int* returnSize) {
    char** paths=(char**)malloc(sizeof(char*)*1001);
    *returnSize=0;
    int arr[1001];
    ConstructPaths(root,paths,returnSize,arr,0);
    return paths;
}