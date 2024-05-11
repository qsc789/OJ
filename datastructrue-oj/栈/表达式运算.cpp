//MT3033
//https://www.matiji.net/exam/dohomework/6230/4
#include<bits/stdc++.h> 
using namespace std;
bool is_op(char op)
{
    return op=='&'||op=='|';
}
int priority(char op)
{
    if(op=='&'||op=='|')
    {
        return 1;
    }
    return -1;
}
void process_op(stack<int> &st,char op)
{
    int r=st.top();
    st.pop();
    int l=st.top();
    st.pop();
    switch(op){
        case '&':
            st.push(min(l,r));
            break;
        case '|':
            st.push(max(l,r));
            break;
    }
}
int evaluate(string &s)//4种情况，数字，'('，')'，两种运算符
{
    stack<int> st;
    stack<char> op;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='(')//(入栈
        {
            op.push('(');
        }
        else if(s[i]==')')
        {
            while(op.top()!='(')//)找对应的左括号
            {
                process_op(st,op.top());//算
                op.pop();//pop掉用过的运算符
            }
            op.pop();//pop掉左括号
        }
        else if(is_op(s[i]))//运算符
        {
            char cur=s[i];
            while(!op.empty()&&priority(op.top())>=priority(cur))//栈顶优先级高就先处理栈顶的，这道题只可能等于，相当于先处理先进栈的
            {
                process_op(st,op.top());
                op.pop();
            }
            op.push(cur);
        }
        else{
            int num=0;
            while(i<(int)s.size()&&isdigit(s[i]))
            {
                num=num*10+s[i]-'0';
                i++;
            }
            i--;//for循环还得加回来
            st.push(num);
        }
    }
    while(!op.empty())//复杂的字符串可能到这步还没算完
    {
        process_op(st,op.top());
        op.pop();
    }
    return st.top();
}
int main( )
{
    string str;
    cin>>str;
   cout<<evaluate(str);
    return 0;
}