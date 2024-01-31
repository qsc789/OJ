//leetcode129
//https://leetcode.cn/problems/sum-root-to-leaf-numbers
/*给你一个二叉树的根节点 root ，树中每个节点都存放有一个 0 到 9 之间的数字。
每条从根节点到叶节点的路径都代表一个数字：

例如，从根节点到叶节点的路径 1 -> 2 -> 3 表示数字 123 。
计算从根节点到叶节点生成的 所有数字之和 。

叶节点 是指没有子节点的节点。*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int dfs(struct TreeNode* root,int prevSum)
{
    if(root==NULL)
    {
        return 0;
    }
    int sum=prevSum*10+root->val;
    if(root->left==NULL&&root->right==NULL)
    {
        return sum;
    }
    else
        return dfs(root->left,sum)+dfs(root->right,sum);
}
int sumNumbers(struct TreeNode* root) {
    return dfs(root,0);
}