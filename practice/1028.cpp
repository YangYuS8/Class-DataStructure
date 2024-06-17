/*分别利用栈和队列实现二叉树的先序非递归算法和层次遍历算法。

已知部分代码如下：（勿改动），请在此基础上补充实现两个遍历算法
*/
#include <iostream>
#include <string>
using namespace std;

// 循环队列类
const int QueueSize = 50; // 定义存储队列元素的数组的最大长度

template <class DataType> // 定义模板类CirQueue
class Queue
{
public:
    Queue();                  // 构造函数，置空队
    ~Queue();                 // 析构函数
    void EnQueue(DataType x); // 将元素x入队
    DataType DeQueue();       // 将队头元素出队
    DataType GetQueue();      // 取队头元素（并不删除）
    bool Full();              // judge full
    bool Empty();             // 判断队列是否为空
private:
    DataType data[QueueSize]; // 存放队列元素的数组
    int front;                // 队头指针,指向队头元素的前一个位置
    int rear;                 // 队尾指针,指向队尾元素的位置
};
/*
 * 前置条件：队列不存在
 * 输    入：无
 * 功    能：初始化队列
 * 输    出：无
 * 后置条件：创建一个空队列
 */

template <typename DataType>
Queue<DataType>::Queue()
{
    front = rear = QueueSize - 1;
}

/*
 * 前置条件：队列已存在
 * 输    入：无
 * 功    能：销毁队列
 * 输    出：无
 * 后置条件：释放队列所占用的存储空间
 */

template <typename DataType>
Queue<DataType>::~Queue()
{
}

/*
 * 前置条件：队列已存在
 * 输    入：元素值x
 * 功    能：在队尾插入一个元素
 * 输    出：如果插入不成功，抛出异常
 * 后置条件：如果插入成功，队尾增加了一个元素
 */

template <typename DataType>
void Queue<DataType>::EnQueue(DataType x)
{
    if (Full())
        throw "上溢";
    rear = (rear + 1) % QueueSize; // 队尾指针在循环意义下加1
    data[rear] = x;                // 在队尾处插入元素
}

/*
 * 前置条件：队列已存在
 * 输    入：无
 * 功    能：删除队头元素
 * 输    出：如果删除成功，返回被删元素值，否则，抛出删除异常
 * 后置条件：如果删除成功，队头减少了一个元素
 */

template <typename DataType>
DataType Queue<DataType>::DeQueue()
{
    if (Empty())
        throw "下溢";
    front = (front + 1) % QueueSize; // 队头指针在循环意义下加1
    return data[front];              // 读取并返回出队前的队头元素，注意队头指针
}
// 指向队头元素的前一个位置
/*
 * 前置条件：队列已存在
 * 输    入：无
 * 功    能：读取队头元素
 * 输    出：若队列不空，返回队头元素
 * 后置条件：队列不变
 */

template <typename DataType>
DataType Queue<DataType>::GetQueue()
{
    int i;
    if (Empty())
        throw "下溢";
    i = (front + 1) % QueueSize; // 注意不要给队头指针赋值
    return data[i];
}

/*
 * 前置条件：队列已存在
 * 输    入：无
 * 功    能：判断队列是否为空
 * 输    出：如果队列为空，返回true，否则，返回false
 * 后置条件：队列不变
 */

template <typename DataType>
bool Queue<DataType>::Empty()
{
    return front == rear;
}

template <typename DataType>
bool Queue<DataType>::Full()
{
    return (rear + 1) % QueueSize == front;
}

// 栈类
const int StackSize = 50;
template <typename DataType>
class Stack
{
public:
    Stack(); // initialize an empty stack
    void Push(DataType x);
    DataType Pop();
    bool Full();  // return true if full
    bool Empty(); // return true if empty
private:
    DataType data[StackSize];
    int top; // subscript of array
};

// initialize an  empty stack
template <typename DataType>
Stack<DataType>::Stack()
{
    top = -1;
}

// push x
template <typename DataType>
void Stack<DataType>::Push(DataType x)
{
    if (Full())
        throw "Overflow";
    data[++top] = x;
}

// pop the top element of stack
template <typename DataType>
DataType Stack<DataType>::Pop()
{
    if (Empty())
        throw "Empty";
    DataType x;
    x = data[top--];
    return x;
}

// judge empty
template <typename DataType>
bool Stack<DataType>::Full()
{
    return top == StackSize - 1;
}

// judge empty
template <typename DataType>
bool Stack<DataType>::Empty()
{
    return top == -1;
    /*  if(top==-1)return true;
      else return false;*/
}

// 二叉树类，实现二叉树的非递归算法：先序遍历、层次遍历
template <typename DataType>
struct BiNode // 二叉树的结点结构
{
    DataType data;
    BiNode<DataType> *lchild, *rchild;
};

template <typename DataType>
class BiTree
{
public:
    BiTree();  // 构造函数，初始化一棵二叉树，其前序序列由键盘输入
    ~BiTree(); // 析构函数，释放二叉链表中各结点的存储空间

    void PreOrder(void); // 先序非递归

    void LevelOrder(void); // 层次遍历

private:
    BiNode<DataType> *root;              // 指向根结点的头指针
    void Creat(BiNode<DataType> *&bt);   // 被构造函数调用，递归方式生成二叉树
    void Release(BiNode<DataType> *&bt); // 被析构函数调用
};

// 定义类中的成员函数

// 构造函数:Creat利用创建二叉树
template <typename DataType>
BiTree<DataType>::BiTree()
{
    Creat(root);
}

// 功    能：递归方法创建一棵二叉树,由构造函数调用
template <typename DataType>
void BiTree<DataType>::Creat(BiNode<DataType> *&bt)
{
    DataType ch;
    cin >> ch;
    if (ch == "#")
        bt = nullptr; // 创建结点值为字符串的二叉树
    else
    {
        bt = new BiNode<DataType>; // 生成一个结点
        bt->data = ch;
        Creat(bt->lchild); // 递归建立左子树
        Creat(bt->rchild); // 递归建立右子树
    }
}
// 功    能：析构函数，释放二叉链表中各结点的存储空间
template <typename DataType>
BiTree<DataType>::~BiTree() // 析构函数不能带参数
{
    Release(root);
}

// 功    能：释放二叉树的存储空间，析构函数调用
template <typename DataType>
void BiTree<DataType>::Release(BiNode<DataType> *&bt)
{
    if (bt != nullptr)
    {
        Release(bt->lchild); // 释放左子树
        Release(bt->rchild); // 释放右子树
        delete bt;
    }
}

// 请在下面补充实现先序、层次遍历算法
// 前序遍历非递归算法
template <class DataType>
void BiTree<DataType>::PreOrder(void)
{
    if (root == nullptr)
        return;
    Stack<BiNode<DataType> *> s;
    s.Push(root);
    while (!s.Empty())
    {
        BiNode<DataType> *node = s.Pop();
        cout << node->data << " ";
        if (node->rchild != nullptr)
            s.Push(node->rchild);
        if (node->lchild != nullptr)
            s.Push(node->lchild);
    }
}

// 层序遍历非递归算法
// 层次遍历算法
template <class DataType>
void BiTree<DataType>::LevelOrder(void)
{
    if (root == nullptr)
        return;
    Queue<BiNode<DataType> *> q;
    q.EnQueue(root);
    while (!q.Empty())
    {
        BiNode<DataType> *node = q.DeQueue();
        cout << node->data << " ";
        if (node->lchild != nullptr)
            q.EnQueue(node->lchild);
        if (node->rchild != nullptr)
            q.EnQueue(node->rchild);
    }
}

int main()
{
    BiTree<string> bt;
    bt.PreOrder();
    cout << endl;
    bt.LevelOrder();
    cout << endl;
    return 0;
}