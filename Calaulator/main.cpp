#include <iostream>
#include<stack>
#include<queue>
#include<cstring>
#include<string>
using namespace std;
stack<char> temp;//存放运算符的临时栈
stack<float> sum;//存放运算结果的栈
queue<string> q;//存放后缀表达式的队列
int priority(char c)//运算符号优先级
{
    switch(c)
    {
    case '*':
    case '/':
        return 1;
    case '+':
    case '-':
        return 0;
    case '(':
    case ')':
        return -1;
    }
}
bool isnumber(char c)
{
    return c>=48&&c<=57;
}
void trans(string s)//中缀表达式转后缀表达式
{
    int n=s.size();
    string tem;
    for(int i=0;i<n;)
    {
        if(isnumber(s[i]))//是数字就直接push进后缀队列
        {
            tem+=s[i];
            while(isnumber(s[++i]))
                tem+=s[i];
            q.push(tem);
            tem.clear();
        }
        else//符号处理
        {
            switch(s[i])
            {
            case '('://左括弧直接进临时栈
                temp.push(s[i]);
                break;
            case ')'://右括弧则将临时栈中符号依次pop到后缀队列
                while(temp.top()!='(')
                {
                    tem+=temp.top();
                    q.push(tem);
                    tem.clear();
                    temp.pop();
                }
                temp.pop();
                break;
            default://+-*/
                if(temp.empty()) temp.push(s[i]);//临时栈空则直接放入符号
                else if(priority(s[i])>priority(temp.top()))//优先级大于栈顶符号则直接进栈
                    temp.push(s[i]);
                else//否则就将栈顶符号pop到后缀队列中
                {
                    while(!temp.empty()&&priority(s[i])<=priority(temp.top()))
                    {
                        tem+=temp.top();
                        q.push(tem);
                        tem.clear();
                        temp.pop();
                    }
                    temp.push(s[i]);
                }
            }
            i++;
        }
    }
    while(!temp.empty())//最后将所有剩余符号送入后缀队列
    {
        tem+=temp.top();
        q.push(tem);
        tem.clear();
        temp.pop();
    }
}
void calculate()//计算后缀队列的值
{
    float cal;
    while(!q.empty())
    {
        if(q.front()=="+")
        {
            cal=sum.top();
            sum.pop();
            cal+=sum.top();
            sum.pop();
            sum.push(cal);
        }
        else if(q.front()=="-")
        {
            cal=0-sum.top();
            sum.pop();
            cal+=sum.top();
            sum.pop();
            sum.push(cal);
        }
        else if(q.front()=="*")
        {
            cal=sum.top();
            sum.pop();
            cal*=sum.top();
            sum.pop();
            sum.push(cal);
        }
        else if(q.front()=="/")
        {
            cal=1/sum.top();
            sum.pop();
            cal*=sum.top();
            sum.pop();
            sum.push(cal);
        }
        else//将后缀队列中的数字从string转为int存入运算栈
        {
            int value=0;
            string t=q.front();
            int n=t.size();
            for(int i=0;i<n;i++)
            {
                value=value*10+t.at(i)-48;
            }
            sum.push(value);
        }
        q.pop();
    }
    cout<<"\nthe answer is: "<<sum.top()<<endl;
}
int main()
{
    cout<<"请输入计算表达式（输入的括弧必须为英文，q to quit）：\n";
    string s;
    cin>>s;
    while(s!="q")
    {
        trans(s);
        /*cout<<"\n后缀表达式为\n";
        while(!q.empty()){
            cout<<q.front();
            q.pop();
        }*/
        calculate();
        cin>>s;
    }
    return 0;
}
