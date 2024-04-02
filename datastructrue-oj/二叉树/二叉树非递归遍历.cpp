#include <iostream>
#include <stack>

using namespace std;
//访问不一定要输出，看具体要求
// 二叉树结点的定义
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

// 非递归方式前序遍历二叉树
void preOrderTraversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    stack<TreeNode*> nodeStack;
    TreeNode* node = root;
    while (node != NULL || !nodeStack.empty()) {
        while (node != NULL) {
            cout << node->val << " ";  // 访问当前结点
            nodeStack.push(node);
            node = node->left;  // 先左
        }
        if (!nodeStack.empty()) {
            node = nodeStack.top();
            nodeStack.pop();
            node = node->right;  // 再右
        }
    }
}

// 非递归方式中序遍历二叉树
void inOrderTraversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    stack<TreeNode*> nodeStack;
    TreeNode* node = root;
    while (node != NULL || !nodeStack.empty()) {
        while (node != NULL) {
            nodeStack.push(node);
            node = node->left;  // 先左
        }
        if (!nodeStack.empty()) {
            node = nodeStack.top();
            nodeStack.pop();
            cout << node->val << " ";  // 访问当前结点
            node = node->right;  // 再右
        }
    }
}

// 非递归方式后序遍历二叉树
void postOrderTraversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    stack<TreeNode*> nodeStack;
    TreeNode* node = root;
    TreeNode* prevVisited =NULL;
    while (node != NULL || !nodeStack.empty()) {
        while (node != NULL) {
            nodeStack.push(node);
            node = node->left;  // 先左
        }
        node = nodeStack.top();
        if (node->right == NULL || node->right == prevVisited) {
            cout << node->val << " ";  // 访问当前结点
            nodeStack.pop();
            prevVisited = node;
            node =NULL;
        } else {
            node = node->right;  // 再右
        }
    }
}

int main() {
    // 构造二叉树
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // 前序遍历
    cout << "Preorder traversal: ";
    preOrderTraversal(root);
    cout << endl;

    // 中序遍历
    cout << "Inorder traversal: ";
    inOrderTraversal(root);
    cout << endl;

    // 后序遍历
    cout << "Postorder traversal: ";
    postOrderTraversal(root);
    cout << endl;

    return 0;
}
