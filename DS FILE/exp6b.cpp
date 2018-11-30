#include<iostream>
#include<stack>
#include<string.h>
using namespace std;

int post_eval(string exp)
{
    stack<int>s;
    int result;
    for(int i=0;i<exp.length();i++)
    {
        if(exp[i]>=48 && exp[i]<=57)
        {
            s.push(exp[i]-'0');
        }
        else if(exp[i]>=42 && exp[i]<=47)
        {
            int a,b;
            a=s.top();
            s.pop();
            b=s.top();
            s.pop();
            if(exp[i]=='+')
                result=b+a;
            else if(exp[i]=='-')
                result=b-a;
            else if(exp[i]=='/')
                result=b/a;
            else if(exp[i]=='*')
                result=b*a;
            s.push(result);
        }
        else if(exp[i]==' '||exp[i]==',')
            continue;
    }
    return s.top();
}

int main()
{
    string exp;
    getline(cin,exp);
    cout<<post_eval(exp);
}
