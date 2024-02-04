//牛客BM33
//https://www.nowcoder.com/practice/a9d0ecbacef9410ca97463e4a5c83be7?tpId=295&tqId=1374963&ru=/exam/oj&qru=/ta/format-top101/question-ranking&sourceUrl=%2Fexam%2Foj
//操作给定的二叉树，将其变换为源二叉树的镜像。
/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */
/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 *
 *
 * @param pRoot TreeNode类
 * @return TreeNode类
 */
struct TreeNode* Mirror(struct TreeNode* pRoot ) {
    struct TreeNode* tmp=NULL;
    if(pRoot==NULL)
    {
        return NULL;
    }
    //每次暴力交换节点下面一层
    //下层节点可能交换多次
    tmp=pRoot->left;
    pRoot->left=pRoot->right;
    pRoot->right=tmp;
    Mirror(pRoot->left);
    Mirror(pRoot->right);
    return pRoot;
}