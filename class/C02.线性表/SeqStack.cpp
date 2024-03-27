#include<iostream>
using namespace std;
template<class T>
class SeqStack
{
private:
    int maxSize; // Declare maxSize variable
    int top; // Declare top variable
    T* stack; // Declare stack array
public:
    SeqStack(int sz=10);
    ~SeqStack();
    void Push(T x);
    T Pop();
    T GetTop();
    void Print();
    bool Empty();
};

template<class T>
SeqStack<T>::SeqStack(int sz)
{
    maxSize = sz;
    top = -1;
    stack = new T[maxSize];
}

template<class T>
SeqStack<T>::~SeqStack()
{
    delete []stack;
}

template<class T>
void SeqStack<T>::Push(T x)
{
    if(top==maxSize-1)
    {
        cerr << "Stack is full." << endl;
        exit(1);
    }
    stack[++top] = x;
}

template<class T>
T SeqStack<T>::Pop()
{
    if(Empty())
    {
        cerr << "Stack is empty." << endl;
        exit(1);
    }
    return stack[top--];
}

template<class T>
T SeqStack<T>::GetTop()
{
    if(Empty())
    {
        cerr << "Stack is empty." << endl;
        exit(1);
    }
    return stack[top];
}

template<class T>
void SeqStack<T>::Print()
{
    for(int i=0;i<=top;i++)
    {
        cout << stack[i] << " ";
    }
    cout << endl;
}

template<class T>
bool SeqStack<T>::Empty()
{
    return top == -1;
}

int main()
{
    SeqStack<int> stack;
    stack.Push(1);
    stack.Push(2);
    stack.Push(3);
    stack.Print();
    cout << stack.Pop() << endl;
    cout << stack.GetTop() << endl;
    stack.Print();
    return 0;
}
