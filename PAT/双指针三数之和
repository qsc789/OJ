给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请

你返回所有和为 0 且不重复的三元组。

注意：答案中不可以包含重复的三元组。

 

 

示例 1：

输入：nums = [-1,0,1,2,-1,-4]
输出：[[-1,-1,2],[-1,0,1]]
解释：
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 。
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 。
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 。
不同的三元组是 [-1,0,1] 和 [-1,-1,2] 。
注意，输出的顺序和三元组的顺序并不重要。


int cmp(const void* e1,const void* e2)
 {
     return *(int*)e1-*(int*)e2;
 }
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int base=100;//数组的初始长度，可更改
    //初始化处理返回值，二维数组的大小和保存每一个一维数组大小的数组的空间保持一致
    int** res=(int**)malloc(sizeof(int*)*base);
    *returnColumnSizes=(int*)malloc(sizeof(int)*base);
    *returnSize=0;
    int i,j,k;
    //排序
    qsort(nums,numsSize,sizeof(int),cmp);
    for(i=0;i<numsSize;i++){
        //先确定第三个数的值，再对剩下的两个数进行两数之和的操作
        //若本次的第三个数与上一次的情况相同，则跳过这个数
        if(i>0&&nums[i]==nums[i-1])
            continue;
        //给定nums[i]，以j，k作为双指针进行两数之和操作
        j=i+1;
        k=numsSize-1;
        while(j<k){
            int sum=nums[i]+nums[j]+nums[k];
            if(sum==0){//刚好遇见符合要求的三元组
                //申请返回值二维数组的空间
                res[*returnSize]=(int*)malloc(sizeof(int)*3);
                //每一个数组大小都为3
                (*returnColumnSizes)[*returnSize]=3;
                //给申请的空间赋值
                res[*returnSize][0]=nums[i];
                res[*returnSize][1]=nums[j];
                res[*returnSize][2]=nums[k];
                //二维数组的行数加1
                (*returnSize)++;
                //如果二维数组的大小达到初始设定的行数，则进行空间扩容
                if(*returnSize==base){
                    base*=2;
                    res=(int**)realloc(res,sizeof(int*)*base);
                    *returnColumnSizes=(int*)realloc(*returnColumnSizes,sizeof(int)*base);
                }
                //记录符合要求的两个数，进行去重
                int num1=nums[j],num2=nums[k];
                while(nums[j]==num1&&j<k)
                    j++;
                while(nums[k]==num2&&j<k)
                    k--;
            }
            //若三个数之和小于0，则左边的指针右移
            else if(sum<0)
                j++;
            //若三个数的之和大于0，则右边的指针往左移
            else k--;
        }
    }
    return res;
}

