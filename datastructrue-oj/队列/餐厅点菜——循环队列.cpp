//MT3037
//https://www.matiji.net/exam/dohomework/6317/3
#include<bits/stdc++.h> 
using namespace std;
deque<int> q;
const int N=1e6+7;
int ans=INT_MAX;
int n,m;
int num[N];
int flag[N];//统计出现多少次
int type;
int main( )
{
    cin>>n>>m;
    int left,right;
    for(int i=1;i<=n;i++)
    {
        cin>>num[i];
        if(flag[num[i]]==0)
        {
            type++;
          
        }
          flag[num[i]]++;
        q.push_back(i);//队列里放需要的元素下标
        while(!q.empty()&&flag[num[q.front()]]>=2)//队头元素出现两次，可以把队头pop掉，有一次就够了，序列越短越好
        {
            flag[num[q.front()]]--;
            q.pop_front();
        }
        if(type==m)//记录种数=m
        {
            if(q.size()<ans)
            {
                ans=q.size();
                left=q.front();
                right=q.back();
            }
        }
    }
    cout<<left<<" "<<right;
    return 0;
}