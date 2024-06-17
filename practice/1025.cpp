#include <bits/stdc++.h>
using namespace std;
// 顺序存储的二叉树，依次实现二叉树的三种递归遍历：先序、中序、后序；
// 二叉树的先序非递归、层次遍历；计算二叉树的叶子个数、高度。
// 部分代码已知，请勿改动，将其它代码补充完整，达到相应的输出结果。
// 循环队列类
const int QueueSize = 100; // 循环队列的最大长度
template <class T>         // 定义模板类CirQueue
class CirQueue
{
public:
    CirQueue();        // 构造函数，置空队
    ~CirQueue();       // 析构函数
    void EnQueue(T x); // 将元素x入队
    T DeQueue();       // 将队头元素出队
    T GetQueue();      // 取队头元素（并不删除）
    bool Empty();      // 判断队列是否为空
    bool Full();

private:
    T data[QueueSize]; // 存放队列元素的数组
    int front, rear;   // 队头和队尾指针，分别指向队头元素的前一个位置和队尾元素的位置
};
// 功    能：初始化空队列
template <class T>
CirQueue<T>::CirQueue()
{
    front = rear = 0;
}
// 功    能：销毁队列
template <class T>
CirQueue<T>::~CirQueue()
{
}
// 功    能：元素x入队
template <class T>
void CirQueue<T>::EnQueue(T x)
{
    if (Full())
        throw "Overflow";
    rear = (rear + 1) % QueueSize; // 队尾指针在循环意义下加1
    data[rear] = x;                // 在队尾处插入元素
}
// 功    能：队头元素出队，返回值为出队元素
template <class T>
T CirQueue<T>::DeQueue()
{
    if (Empty())
        throw "Downflow";
    front = (front + 1) % QueueSize; // 队头指针在循环意义下加1
    return data[front];              // 读取并返回出队前的队头元素，注意队头指针
}
// 指向队头元素的前一个位置
//  功    能：获取队头元素
template <class T>
T CirQueue<T>::GetQueue()
{
    int i;
    if (Empty())
        throw "Downflow";
    i = (front + 1) % QueueSize; // 注意不要给队头指针赋值
    return data[i];
}
// 功    能：判断队列是否为空,若空返回true，否则返回false
template <class T>
bool CirQueue<T>::Empty()
{
    return front == rear;
}
// 功   能：判断队列是否满，若满返回true，否则false
template <class T>
bool CirQueue<T>::Full()
{
    return (rear + 1) % QueueSize == front;
}

// 栈类
const int StackSize = 100; // 100只是示例性的数据，可以根据实际问题具体定义
template <class T>         // 定义模板类SeqStack
class SeqStack
{
public:
    SeqStack();     // 构造函数，栈的初始化
    ~SeqStack();    // 析构函数
    void Push(T x); // 将元素x入栈
    T Pop();        // 将栈顶元素弹出
    T GetTop();     // 取栈顶元素（并不删除）
    bool Empty();   // 判断栈是否为空
    bool Full();    // 判断栈是否为满
private:
    T data[StackSize]; // 存放栈元素的数组
    int top;           // 栈顶指针，指示栈顶元素在数组中的下标
};

// 初始化空栈
template <class T>
SeqStack<T>::SeqStack()
{
    top = -1;
}

// 功    能：销毁栈
template <class T>
SeqStack<T>::~SeqStack()
{
}

// 功    能：元素x压栈
template <class T>
void SeqStack<T>::Push(T x)
{
    if (Full())
        throw "Overflow";
    top++;
    data[top] = x;
}
// 功    能：栈顶元素弹栈
template <class T>
T SeqStack<T>::Pop()
{
    T x;
    if (Empty())
        throw "Downflow";
    x = data[top--];
    return x;
}

// 功    能：读取当前的栈顶元素
template <class T>
T SeqStack<T>::GetTop()
{
    if (Empty())
        throw "Downflow";
    return data[top];
}

// 功    能：判断栈是否为空
template <class T>
bool SeqStack<T>::Empty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}

// 功    能：判断栈是否为满
template <class T>
bool SeqStack<T>::Full()
{
    return top == StackSize - 1;
}

// 顺序二叉树类
const int TreeSize = 100; // 最大长度
template <class T>
class BiTree
{
public:
    BiTree(T *);             // 构造函数，初始化一棵二叉树，其前序序列由键盘输入
    void PreOrder(int pos);  // 前序遍历二叉树
    void InOrder(int pos);   // 中序遍历二叉树
    void PostOrder(int pos); // 后序遍历二叉树
    int CountLeaf(int pos);  // 计算叶子结点总数
    int Depth(int pos);      // 计算高度
    void PreOrder();         // 非递归先序遍历
    void LevelOrder();       // 层次遍历
private:
    T data[TreeSize];
    // 存储结点的元素值，根结点存储在1下标，双亲下标为i，则左右孩子依次为2i，2i+1
};

// 构造函数
template <class T>
BiTree<T>::BiTree(T *str)
{
    strcpy(data + 1, str); // 把字符数组str存储到data数组里，从下标1开始存
}

// 前序遍历
template <class T>
void BiTree<T>::PreOrder(int pos)
{
    if (pos >= TreeSize || data[pos] == 0)
        return;
    cout << data[pos] << " ";
    PreOrder(2 * pos);
    PreOrder(2 * pos + 1);
}

// 中序遍历
template <class T>
void BiTree<T>::InOrder(int pos)
{
    if (pos >= TreeSize || data[pos] == 0)
        return;
    InOrder(2 * pos);
    cout << data[pos] << " ";
    InOrder(2 * pos + 1);
}

// 后序遍历
template <class T>
void BiTree<T>::PostOrder(int pos)
{
    if (pos >= TreeSize || data[pos] == 0)
        return;
    PostOrder(2 * pos);
    PostOrder(2 * pos + 1);
    cout << data[pos] << " ";
}

// 计算叶子结点总数
template <class T>
int BiTree<T>::CountLeaf(int pos)
{
    if (pos >= TreeSize || data[pos] == 0)
        return 0;
    if (data[2 * pos] == 0 && data[2 * pos + 1] == 0)
        return 1;
    return CountLeaf(2 * pos) + CountLeaf(2 * pos + 1);
}

// 计算高度
template <class T>
int BiTree<T>::Depth(int pos)
{
    if (pos >= TreeSize || data[pos] == 0)
        return 0;
    int left = Depth(2 * pos);
    int right = Depth(2 * pos + 1);
    return max(left, right) + 1;
}

// 非递归先序遍历
template <class T>
void BiTree<T>::PreOrder()
{
    SeqStack<int> s;
    int pos = 1;
    while (pos < TreeSize && (pos != 0 || !s.Empty()))
    {
        while (pos < TreeSize && data[pos] != 0)
        {
            cout << data[pos] << " ";
            s.Push(pos);
            pos = 2 * pos;
        }
        if (!s.Empty())
        {
            pos = s.Pop();
            pos = 2 * pos + 1;
        }
    }
}

// 层次遍历
template <class T>
void BiTree<T>::LevelOrder()
{
    CirQueue<int> q;
    int pos = 1;
    q.EnQueue(pos);
    while (!q.Empty())
    {
        pos = q.DeQueue();
        if (pos >= TreeSize || data[pos] == 0)
            continue;
        cout << data[pos] << " ";
        if (data[2 * pos] != 0)
            q.EnQueue(2 * pos);
        if (data[2 * pos + 1] != 0)
            q.EnQueue(2 * pos + 1);
    }
}

int main()
{
    char str[80];
    cin >> str;
    BiTree<char> bt(str);
    bt.PreOrder(1);
    cout << endl;
    bt.InOrder(1);
    cout << endl;
    bt.PostOrder(1);
    cout << endl;
    bt.PreOrder();
    cout << endl;
    bt.LevelOrder();
    cout << endl;
    cout << bt.CountLeaf(1) << " " << bt.Depth(1) << endl;
    return 0;
}