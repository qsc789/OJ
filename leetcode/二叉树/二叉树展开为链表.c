//力扣114
//https://leetcode.cn/problems/flatten-binary-tree-to-linked-list
//给你二叉树的根结点 root ，请你将它展开为一个单链表：

//展开后的单链表应该同样使用 TreeNode ，其中 right 子指针指向链表中下一个结点，而左子指针始终为 null 。
//展开后的单链表应该与二叉树 先序遍历 顺序相同。
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct TreeNode Node;

void Part (Node* root, Node** ListTail) {
    if (root==NULL)   // 如果没果子了，就结束
        return ;

    Node* tempLeft = root->left;
    Node* tempRight = root->right;

    (*ListTail)->right = root;   // 摘下一个果子
    root->left = NULL;   // 剔除掉根须
    root->right = NULL;

    *ListTail = (*ListTail)->right;
    Part(tempLeft, ListTail);   // 接着摘左边的果子
    Part(tempRight, ListTail);   // 接着摘右边的果子
}

void flatten(struct TreeNode* root) {
    Node* ListTail = (Node*)malloc(sizeof(Node));
    Part(root, &ListTail);

}