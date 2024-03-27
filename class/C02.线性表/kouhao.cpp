#include<iostream>
#include "SeqStack.cpp"
using namespace std;

void Juge(char str[])
{
    SeqStack<char> s;
    for (int i=0;str[i]!='\0';i++)
    {
        if (str[i]=='(')
        {
            s.Push(str[i]);
        }
        else if (str[i]==')')
        {
            if (s.Empty())
            {
                cout << "右括号剩余" << endl;
                return;
            }
            s.Pop();
        }
    }
    if(s.Empty())
    {
        cout << "括号匹配" << endl;
    }
    else
    {
        throw "左括号剩余";
    }
}

int main()
{
    char str[] = "((())";
    try
    {
        Juge(str);
    }
    catch(const char *s)
    {
        cout << s << endl;
    }
    return 0;
}