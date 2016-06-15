#include <iostream>
#include<stack>
#include<queue>
#include<cstring>
#include<string>
using namespace std;
stack<char> temp;//������������ʱջ
stack<float> sum;//�����������ջ
queue<string> q;//��ź�׺���ʽ�Ķ���
int priority(char c)//����������ȼ�
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
void trans(string s)//��׺���ʽת��׺���ʽ
{
    int n=s.size();
    string tem;
    for(int i=0;i<n;)
    {
        if(isnumber(s[i]))//�����־�ֱ��push����׺����
        {
            tem+=s[i];
            while(isnumber(s[++i]))
                tem+=s[i];
            q.push(tem);
            tem.clear();
        }
        else//���Ŵ���
        {
            switch(s[i])
            {
            case '('://������ֱ�ӽ���ʱջ
                temp.push(s[i]);
                break;
            case ')'://����������ʱջ�з�������pop����׺����
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
                if(temp.empty()) temp.push(s[i]);//��ʱջ����ֱ�ӷ������
                else if(priority(s[i])>priority(temp.top()))//���ȼ�����ջ��������ֱ�ӽ�ջ
                    temp.push(s[i]);
                else//����ͽ�ջ������pop����׺������
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
    while(!temp.empty())//�������ʣ����������׺����
    {
        tem+=temp.top();
        q.push(tem);
        tem.clear();
        temp.pop();
    }
}
void calculate()//�����׺���е�ֵ
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
        else//����׺�����е����ִ�stringתΪint��������ջ
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
    cout<<"�����������ʽ���������������ΪӢ�ģ�q to quit����\n";
    string s;
    cin>>s;
    while(s!="q")
    {
        trans(s);
        /*cout<<"\n��׺���ʽΪ\n";
        while(!q.empty()){
            cout<<q.front();
            q.pop();
        }*/
        calculate();
        cin>>s;
    }
    return 0;
}
