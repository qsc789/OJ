//牛客BM18
//https://www.nowcoder.com/practice/abc3fe2ce8e146608e868a70efebf62e?tpId=295&tqId=23256&ru=/exam/oj&qru=/ta/format-top101/question-ranking&sourceUrl=%2Fexam%2Foj
/*在一个二维数组array中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
[
[1,2,8,9],
[2,4,9,12],
[4,7,10,13],
[6,8,11,15]
]
给定 target = 7，返回 true。

给定 target = 3，返回 false。
 */
/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 *
 *
 * @param target int整型
 * @param array int整型二维数组
 * @param arrayRowLen int array数组行数
 * @param arrayColLen int* array数组列数
 * @return bool布尔型
 */
//C
bool Find(int target, int** arr, int arrayRowLen, int* arrayColLen ) {
    int num1=0,num2=*arrayColLen-1;//起始点为右上角
    while(arr[num1][num2]!=target)
    {
        while(target>arr[num1][num2])//太小则横坐标++
        {
            num1++;
            if(num1>=arrayRowLen)
            {
                return false;
            }
        }
        while(target<arr[num1][num2])//太小则纵坐标--
        {
            num2--;
            if(num2<0)
            {
                return false;
            }
        }
    }
    return true;
}

//C++
//1.暴力搜索
bool Find(int target, vector<vector<int> > array) {
    for(auto i:array)
    {
        for(auto j:i)
        {
            if(j==target)
            {
                return true;
            }
        }
    }
    return false;
}
//二分查找
class Solution {
        public:
        /**
         * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
         *
         *
         * @param target int整型
         * @param array int整型vector<vector<>>
         * @return bool布尔型
         */
        bool binary_search(vector<int> arr,int target)//二维数组每行二分查找
        {
            int left=0,right=arr.size()-1;
            while(left<=right)
            {
                int mid=(left+right)/2;
                if(arr[mid]==target)
                {
                    return true;
                }
                else if(arr[mid]<target)
                {
                    left=mid+1;
                }
                else {
                    {
                        right=mid-1;
                    }
                }


            }
            return false;
        }
        bool Find(int target, vector<vector<int> >& array) {
            for(auto i:array)
            {
                if(binary_search(i,target))
                    return true;
            }
            return false;
        }
};