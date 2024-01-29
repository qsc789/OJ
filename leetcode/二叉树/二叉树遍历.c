//链接：https://www.nowcoder.com/questionTerminal/4b91205483694f449f94c179883c1fef
//来源：牛客网
//
//编一个程序，读入用户输入的一串先序遍历字符串，根据此字符串建立一个二叉树（以指针方式存储）。 例如如下的先序遍历字符串： ABC##DE#G##F### 其中“#”表示的是空格，空格字符代表空树。建立起此二叉树以后，再对二叉树进行中序遍历，输出遍历结果。

#include <stdio.h>
typedef struct TreeNode
{
    char val;
    struct TreeNode* left;
    struct TreeNode* right;
}TNode;
TNode* CreateTree(char* a, int* pi)
{
    if (a[*pi] == '#')
    {
        (*pi)++;
        return NULL;
    }
    TNode* root = (TNode*)malloc(sizeof(TNode));
    if (root == NULL)
    {
        printf("malloc fail\n");
        exit(-1);
    }
    root->val = a[*pi];
    (*pi)++;
    root->left = CreateTree(a, pi);//递归构建左子树
    root->right = CreateTree(a, pi);//递归构建右子树
    return root;

}
void InOrder(TNode* root)
{
    if (root == NULL)
        return;
    InOrder(root->left);
    printf("%c ", root->val);
    InOrder(root->right);
}
int main() {
    char str[100];
    scanf("%s", str);
    int i = 0;
    TNode* root = CreateTree(str, &i);
    InOrder(root);
    return 0;
}