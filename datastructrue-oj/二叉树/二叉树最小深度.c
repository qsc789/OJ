//力扣111
// https://leetcode.cn/problems/minimum-depth-of-binary-tree/
//给定一个二叉树，找出其最小深度。
//最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
//说明：叶子节点是指没有子节点的节点。
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int minDepth(struct TreeNode* root) {
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    int min_depth = INT_MAX;//放一个最大的数
    if (root->left != NULL)
    {
        min_depth = fmin(minDepth(root->left), min_depth);//取最小值
    }
    if (root->right != NULL)
    {
        min_depth = fmin(minDepth(root->right), min_depth);
    }
    return min_depth + 1;
}