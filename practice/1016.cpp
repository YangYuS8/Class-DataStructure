// 已知顺序栈类的定义、构造函数及主函数的代码如下，请完成类的其它成员函数，完成相应的输出。
#include <iostream>
using namespace std;

const int StackSize = 5; // 顺序栈的最大长度

template <typename DataType>
class SeqStack
{
public:
    SeqStack();            // 构造函数，栈的初始化
    ~SeqStack();           // 析构函数
    void Push(DataType x); // 将元素x入栈
    DataType Pop();        // 将栈顶元素弹出
    DataType GetTop();     // 取栈顶元素（并不删除）
    bool Empty();          // 判断栈是否为空

private:
    DataType data[StackSize]; // 存放栈元素的数组
    int top;                  // 栈顶指针，指示栈顶元素在数组中的下标
};

/*
 * 构造函数，栈的初始化
 */
template <typename DataType>
SeqStack<DataType>::SeqStack()
{
    top = -1; // 初始化栈顶指针为-1，表示栈为空
}

/*
 * 析构函数
 */
template <typename DataType>
SeqStack<DataType>::~SeqStack()
{
    // 在析构函数中不需要特别的处理，因为数组 data 是静态分配的
}

/*
 * 将元素x入栈
 */
template <typename DataType>
void SeqStack<DataType>::Push(DataType x)
{
    if (top == StackSize - 1)
    {
        cout << "Push:Overflow" << endl; // 栈满，输出 Overflow
        return;
    }
    data[++top] = x; // 栈顶指针先加1，然后将元素入栈
}

/*
 * 将栈顶元素弹出
 */
template <typename DataType>
DataType SeqStack<DataType>::Pop()
{
    if (top == -1)
    {
        throw "Downflow"; // 栈空，抛出异常
    }
    return data[top--]; // 返回栈顶元素，并将栈顶指针减1
}

/*
 * 取栈顶元素（并不删除）
 */
template <typename DataType>
DataType SeqStack<DataType>::GetTop()
{
    if (top == -1)
    {
        throw "Downflow"; // 栈空，抛出异常
    }
    return data[top]; // 返回栈顶元素，但不改变栈的状态
}

/*
 * 判断栈是否为空
 */
template <typename DataType>
bool SeqStack<DataType>::Empty()
{
    return (top == -1); // 栈空时返回 true，否则返回 false
}

int main()
{
    SeqStack<int> s;
    int x;

    // 输入元素并依次进行入栈操作
    while (1)
    {
        cin >> x;
        if (!x)
            break;
        try
        {
            s.Push(x);
        }
        catch (const char *ms)
        {
            cout << ms << endl; // 捕获并输出入栈异常信息
        }
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
