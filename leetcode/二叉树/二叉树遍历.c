//���ӣ�https://www.nowcoder.com/questionTerminal/4b91205483694f449f94c179883c1fef
//��Դ��ţ����
//
//��һ�����򣬶����û������һ����������ַ��������ݴ��ַ�������һ������������ָ�뷽ʽ�洢���� �������µ���������ַ����� ABC##DE#G##F### ���С�#����ʾ���ǿո񣬿ո��ַ����������������˶������Ժ��ٶԶ������������������������������

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
    root->left = CreateTree(a, pi);//�ݹ鹹��������
    root->right = CreateTree(a, pi);//�ݹ鹹��������
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