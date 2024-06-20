// 已知链式栈类的定义、构造函数及主函数的代码如下，请完成类的其它成员函数，完成相应的输出。
#include <iostream>
using namespace std;

// 链表节点定义
template <typename T>
struct Node
{
    T data;                               // 节点数据
    Node<T> *next;                        // 指向下一个节点的指针
    Node(T x) : data(x), next(nullptr) {} // 构造函数
};

// 链式栈类定义
template <typename T>
class LinkStack
{
public:
    LinkStack();    // 构造函数，置空链栈
    ~LinkStack();   // 析构函数，释放链栈中各结点的存储空间
    void Push(T x); // 将元素x入栈
    T Pop();        // 将栈顶元素出栈
    T GetTop();     // 取栈顶元素（并不删除）
    bool Empty();   // 判断链栈是否为空栈

private:
    Node<T> *top; // 栈顶指针即链栈的头指针
};

// 构造函数，置空链栈
template <typename T>
LinkStack<T>::LinkStack()
{
    top = nullptr; // 初始化栈顶指针为空
}

// 析构函数，释放链栈中各结点的存储空间
template <typename T>
LinkStack<T>::~LinkStack()
{
    // 释放链栈中所有节点的存储空间
    while (top != nullptr)
    {
        Node<T> *temp = top;
        top = top->next;
        delete temp;
    }
}

// 将元素x入栈
template <typename T>
void LinkStack<T>::Push(T x)
{
    Node<T> *newNode = new Node<T>(x); // 创建新节点
    newNode->next = top;               // 新节点指向当前栈顶
    top = newNode;                     // 更新栈顶指针为新节点
}

// 将栈顶元素出栈
template <typename T>
T LinkStack<T>::Pop()
{
    if (Empty())
    {
        throw "Downflow"; // 栈空，抛出异常
    }
    Node<T> *temp = top; // 暂存栈顶节点
    T data = temp->data; // 获取栈顶元素值
    top = top->next;     // 更新栈顶指针为下一个节点
    delete temp;         // 释放原栈顶节点的空间
    return data;         // 返回栈顶元素值
}

// 取栈顶元素（并不删除）
template <typename T>
T LinkStack<T>::GetTop()
{
    if (Empty())
    {
        throw "Downflow"; // 栈空，抛出异常
    }
    return top->data; // 返回栈顶元素值
}

// 判断链栈是否为空栈
template <typename T>
bool LinkStack<T>::Empty()
{
    return (top == nullptr); // 栈空时返回 true，否则返回 false
}

// 主函数
int main()
{
    LinkStack<char> s;
    char ch;

    // 输入元素并依次进行入栈操作，直到输入 '#'
    while (1)
    {
        cin >> ch;
        if (ch == '#')
            break;
        s.Push(ch);
    }

    // 输出当前栈顶元素
    try
    {
        cout << "Gettop:" << s.GetTop() << endl;
    }
    catch (const char *ms)
    {
        cout << "Gettop:" << ms << endl; // 捕获并输出获取栈顶元素异常信息
    }

    // 依次将栈中元素出栈并输出
    while (!s.Empty())
    {
        cout << s.Pop() << " ";
    }
    cout << endl;

    // 再次尝试获取栈顶元素，捕获并输出异常信息
    try
    {
        cout << s.GetTop() << endl;
    }
    catch (const char *ms)
    {
        cout << "Gettop:" << ms << endl;
    }

    return 0;
}
