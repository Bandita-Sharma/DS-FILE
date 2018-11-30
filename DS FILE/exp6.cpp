#include<iostream>
#include<string.h>
#include<ctype.h>
#define max 20
using namespace std;

class infix
{
private:
    char target[max],stk[max];
    char *s,*t;
    int top;
public:
    infix()
    {
        top=-1;
        t=target;
        s=stk;
    }
    void setexpr(char *expr)
    {
        s=expr;
    }
    void push(char c)
    {
        if(top==max-1)
        {
            cout<<"stack is full";
        }
        else
        {
            top++;
            stk[top]=c;
        }
    }
    char pop()
    {
        if(top==-1)
        {
            cout<<"stack underflow";
            return -1;
        }
        else
        {
            char item=stk[top];
            top--;
            return item;
        }
    }
    int priority(char c)
    {
        if(c=='$')
            return 3;
        if(c=='*'||c=='/')
            return 2;
        if(c=='+'||c=='-')
            return 1;
        else
            return 0;
    }
    void convert()
    {
        while(*s)
        {
            if(isdigit(*s)||isalpha(*s))
            {
                while(isdigit(*s)||isalpha(*s))
                {
                    *t=*s;
                    t++;
                    s++;
                }
            }
            if(*s=='(')
            {
                push(*s);
                s++;
            }
            char opr;
            if(*s == '*' || *s == '+' || *s == '/' || *s == '%' || *s == '-' || *s == '$' )
            {
                if(top!=-1)
                {
                    opr=pop();
                    if(priority(opr)>=priority(*s))
                    {
                        *t=opr;
                        t++;
                        push(*s);
                    }
                    else
                    {
                        push(opr);
                        push(*s);
                    }
                }
                else
                {
                    push(*s);
                }
                s++;
            }
            if(*s==')')
            {
                opr=pop();
                while((opr)!='(')
                {
                    *t=opr;
                    t++;
                    opr=pop();
                }
                s++;
            }
        }
        while(top!=-1)
        {
            char opr=pop();
            *t=opr;
            t++;
        }
        *t='\0';
    }
    void show()
    {
        cout<<target;
    }
};


    int main()
    {
            infix q;
    char expr[max];
    cout<<"enter an infix expression:";
    cin.getline(expr,max);
    q.setexpr(expr);
    q.convert();
    cout<<"Postfix expression is:";
    q.show(); 
        }

