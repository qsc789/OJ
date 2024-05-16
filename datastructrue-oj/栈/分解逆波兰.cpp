//MT3035
//https://www.matiji.net/exam/dohomework/6317/2
#include<bits/stdc++.h> 
using namespace std;
bool is_op(char ch)
{
    return ch=='+'||ch=='-'||ch=='*'||ch=='/';
}
int priority(char ch)
{
   if(ch=='+'||ch=='-')
   {
    return 1;
   }
   else if(ch=='*'||ch=='/')
   {
    return 2;
   }
//    else if(ch=='^')
//    {
//     return 3;
//    }
   return -1;
}
void process_op(string str)
{
    stack<int> st;
    bool change=false;
    for(int i=0;i<str.size();i++)
    {
        if(is_op(str[i]))
    {
        int right=st.top();
        st.pop();
        int left=st.top();
        st.pop();
        switch(str[i])
           {
            case '+':
            st.push(left+right);
            break;
            case '-':
            st.push(left-right);
            break;
            case '*':
            st.push(left*right);
            break;
            case '/':
            st.push(left/right);
            break;
           }
           change=true;
    }
    else{
        st.push(str[i]-'0');
        change=false;
    }
    if(change)//发生变化就打印
    {
        stack<int> temp1,temp2;
        temp1=st;
        while(!temp1.empty())
        {
            temp2.push(temp1.top());
            temp1.pop();
        }
        while(!temp2.empty())
        {
            cout<<temp2.top()<<" ";
            temp2.pop();
        }
        for(int j=i+1;j<str.size();j++)
        {
            if(j<str.size()-1)
            cout<<str[j]<<" ";
            else
            cout<<str[j];
        }
        cout<<endl;
    }
   
    }
    
}
string toRPN(string str)//中序转后续
{
    stack<char> st;
    stack<char> op;
    for(int i=0;i<str.size();i++)
    {
        if(str[i]=='(')
        {
            op.push('(');
        }
        else if(str[i]==')')
        {
            while(op.top()!='(')
            {
                st.push(op.top());
                op.pop();
            }
            op.pop();
        }
        else if(is_op(str[i]))
        {
            while(!op.empty()&&priority(op.top())>=priority(str[i]))
            {
                st.push(op.top());
                op.pop();
            }
            op.push(str[i]);
        }
        else{
            st.push(str[i]);
        }
    }
    while(!op.empty())
    {
        st.push(op.top());
        op.pop();
    }
    string ans;
    int len=st.size();
    while(len--)
    {
        ans=st.top()+ans;
        st.pop();
    }
    return ans;
}
int main( )
{
    string str;
    cin>>str;
    string s=toRPN(str);//转换为后序形式
    for(int i=0;i<s.size();i++)
    {
        cout<<s[i]<<" ";
    }
    cout<<endl;
    process_op(s);
    return 0;
}