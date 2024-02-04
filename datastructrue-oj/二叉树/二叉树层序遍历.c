//牛客BM26
//https://www.nowcoder.com/practice/04a5560e43e24e9db4595865dc9c63a3?tpId=295&tqId=644&ru=/exam/oj&qru=/ta/format-top101/question-ranking&sourceUrl=%2Fexam%2Foj
//给定一个二叉树，返回该二叉树层序遍历的结果，（从左到右，一层一层地遍历）
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
 * @param root TreeNode类
 * @return int整型二维数组
 * @return int* returnSize 返回数组行数
 * @return int** returnColumnSizes 返回数组列数
 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes ) {
    // write code here*returnSize=0;
    if(root==NULL)
    {
        return NULL;
    }
    struct TreeNode* queue[100001];//建队列
    int** res=(int**)malloc(sizeof(int*)*100001);
    *returnColumnSizes=(int*)malloc(sizeof(int)*100001);//行

    int head=0,tail=0;
    queue[tail]=root;
    tail++;

    while(head!=tail)
    {
        int tmp=tail;
        int num=0;//当前层节点数量
        res[*returnSize]=(int*)malloc(sizeof(int)*(tmp-head));
        while(head<tmp)
        {
            struct TreeNode* p=queue[head];//队头元素出队
            res[*returnSize][num]=p->val;
            num++;
            if(p->left!=NULL)//将当前出队元素的左孩子结点入队
            {
                queue[tail]=p->left;
                tail++;
            }
            if(p->right!=NULL)//将当前出队元素的右孩子结点入队
            {
                queue[tail]=p->right;
                tail++;
            }
            head++;
        }
        (*returnColumnSizes)[*returnSize]=num;//更新返回数组本层结点个数
        (*returnSize)++;  //指针指向下一层返回数组
    }
    return res;
}