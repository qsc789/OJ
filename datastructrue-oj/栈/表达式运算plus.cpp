//MT3034
//https://www.matiji.net/exam/dohomework/6230/5
#include<bits/stdc++.h> 
#include<math.h>
using namespace std;
bool tag[40];
bool is_op(char op)
{
    return op=='+'||op=='-'||op=='*'||op=='/'||op=='^';
}
int priority(char op)
{
  if(op=='+'||op=='-')
  {
    return 1;
  }
  else if(op=='*'||op=='/')
  {
    return 2;
  }
  else if(op=='^')
  {
    return 3;
  }
  return -1;
}
void process_op(stack<int> &st,char op)
{
    int r=st.top();
    st.pop();
    int l=st.top();
    st.pop();
    switch(op)
    {
        case '+':
           st.push(l+r);
           break;
        case '-':
           st.push(l-r);
           break;
        case '*':
           st.push(l*r);
           break;
        case '/':
           st.push(l/r);
           break;
        case '^':
           st.push(pow(l,r));
           break;
    }
}
int evaluate(string &s)
{
    stack<int> st;
    stack<char> op;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='(')
        {
            if(!tag[i])
            {
                continue;
            }
            op.push(s[i]);
        }
        else if(s[i]==')')
        {
            if(!tag[i])
            {
                continue;
            }
            while(op.top()!='(')
            {
                process_op(st,op.top());
                op.pop();
            }
            op.pop();
        }
        else if(is_op(s[i]))
        {
            char cur=s[i];
            while(!op.empty()&&priority(op.top())>=priority(s[i]))
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
            i--;
            st.push(num);
        }
    }
    while(!op.empty())
    {
        process_op(st,op.top());
        op.pop();
    }
    return st.top();
}
void init(string &s)
{
    stack<pair<char,int>> st;
    for(int i=0;i<s.size();i++)
    {
        if(!st.empty()&&st.top().first=='('&&s[i]==')')
        {
            tag[i]=tag[st.top().second]=true;//有配对的
            st.pop();
        }
        else if(s[i]=='(')
        {
            st.push({'(',i});
        }
    }
}
int main( )
{
    string str;
    cin>>str;
init(str);
cout<<evaluate(str);
    return 0;
}