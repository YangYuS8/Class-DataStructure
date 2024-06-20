// 在循环队列中增加一个count变量，用来记录当前队列中数据个数，利用该值为0或QueueSize来判断队空或队满条件判断。循环队列类的定义、部分实现及主函数代码如下：
#include <iostream>
#include <string>
using namespace std;

const int QueueSize = 5;

template <class T>
class CirQueue
{
public:
    CirQueue();        // 构造函数，置空队
    ~CirQueue();       // 析构函数
    void EnQueue(T x); // 将元素x入队
    T DeQueue();       // 将队头元素出队
    T GetQueue();      // 取队头元素（并不删除）
    bool Empty();      // 判断队列是否为空，空返回true，否则返回false
    bool Full();       // 判断队列是否为满，满返回true，否则返回false

private:
    T data[QueueSize]; // 存放队列元素的数组
    int front, rear;   // 队头和队尾指针，分别指向队头元素所在数组的前一下标和队尾元素的数组下标
    int count;         // 记录队列中数据个数
};

// 构造函数：初始化队列为空
template <class T>
CirQueue<T>::CirQueue()
{
    front = rear = QueueSize - 1;
    count = 0;
}

// 析构函数：销毁队列
template <class T>
CirQueue<T>::~CirQueue()
{
}

// 判断队列是否为空
template <class T>
bool CirQueue<T>::Empty()
{
    return count == 0;
}

// 判断队列是否为满
template <class T>
bool CirQueue<T>::Full()
{
    return count == QueueSize;
}

// 将元素x入队
template <class T>
void CirQueue<T>::EnQueue(T x)
{
    if (Full())
        throw "Overflow";
    rear = (rear + 1) % QueueSize; // 队尾指针在循环意义下加1
    data[rear] = x;                // 将x插入到新的队尾位置
    count++;
}

// 删除队头元素
template <class T>
T CirQueue<T>::DeQueue()
{
    if (Empty())
        throw "Downflow";
    front = (front + 1) % QueueSize; // 队头指针在循环意义下加1
    T value = data[front];           // 读取并返回出队前的队头元素
    count--;
    return value;
}

// 读取队头元素（并不删除）
template <class T>
T CirQueue<T>::GetQueue()
{
    if (Empty())
        throw "Downflow";
    int i = (front + 1) % QueueSize; // 注意不要给队头指针赋值
    return data[i];
}

// 主函数
int main()
{
    CirQueue<string> Q;
    string x;
    // 输入并尝试入队
    while (1)
    {
        cin >> x;
        if (x == "#")
            break;
        try
        {
            Q.EnQueue(x);
            cout << "EnQueue:" << x << endl;
        }
        catch (const char *ms)
        {
            cout << "EnQueue:" << x << " " << ms << endl;
        }
    }
    // 尝试出队
    while (!Q.Empty())
    {
        x = Q.DeQueue();
        cout << "DeQueue:" << x << endl;
    }
    // 尝试读取队头元素
    try
    {
        x = Q.GetQueue();
    }
    catch (const char *ms)
    {
        cout << "GetQueue:The queue is empty," << ms << endl;
    }
    return 0;
}
