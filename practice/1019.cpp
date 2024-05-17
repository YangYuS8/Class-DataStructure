#include <iostream>
using namespace std;

template <class T>
struct Node
{
    T data;
    Node<T> *next;
};

template <class T>
class Stack
{
public:
    Stack();        // 构造函数，置空链栈(有头结点)
    ~Stack();       // 析构函数，释放链栈中各结点的存储空间
    void Push(T x); // 将元素x入栈
    T Pop();        // 将栈顶元素出栈
    bool Empty();   // 判断链栈是否为空栈
private:
    Node<T> *top; // 栈顶指针即链栈的头指针
};

/*
 * 前置条件：栈不存在
 * 输    入：无
 * 功    能：栈的初始化
 * 输    出：无
 * 后置条件：构造一个空栈
 */
template <class T>
Stack<T>::Stack()
{
    top = new Node<T>;
    top->next = NULL;
}
/*
 * 前置条件：栈已存在
 * 输    入：无
 * 功    能：销毁栈
 * 输    出：无
 * 后置条件：释放栈所占用的存储空间
 */
template <class T>
Stack<T>::~Stack()
{
    while (top)
    {
        Node<T> *p;
        p = top->next;
        delete top;
        top = p;
    }
}
/*
 * 前置条件：栈已存在
 * 输    入：无
 * 功    能：判断栈是否为空
 * 输    出：如果为空，返回true；否则，返回false
 * 后置条件：无
 */
template <class T>
bool Stack<T>::Empty()
{
    return (top->next == NULL);
}

/*
 * 前置条件：栈已存在
 * 输    入：元素值x
 * 功    能：向栈顶插入元素
 * 输    出：无
 * 后置条件：栈顶插入了一个元素
 */
template <class T>
void Stack<T>::Push(T x)
{
    Node<T> *p = new Node<T>;
    p->data = x;
    p->next = top->next;
    top->next = p;
}

/*
 * 前置条件：栈已存在
 * 输    入：无
 * 功    能：删除栈顶元素
 * 输    出：如果删除成功，返回被删元素值，否则，抛出异常
 * 后置条件：如果删除成功，栈顶减少了一个元素
 */
template <class T>
T Stack<T>::Pop()
{
    Node<T> *p;
    T x;
    if (top->next == NULL)
        throw "Downflow";
    x = top->next->data; // 暂存栈顶元素
    p = top->next;
    top->next = p->next; // 将栈顶结点摘链
    delete p;
    return x;
}

int main()
{
    Stack<char> s;
    char ch;
    while (1)
    {
        cin >> ch;
        if (ch == '#')
            break;
        s.Push(ch);
    }
    cout << "Pop:";
    while (!s.Empty())
    {
        cout << s.Pop() << " ";
    }
    cout << endl;
    return 0;
}
