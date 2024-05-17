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
    void EnQueue(T x); // 将元素x入队，队满时抛出异常信息Overflow
    T DeQueue();       // 将队头元素出队，队空抛出异常信息Downflow
    T GetQueue();      // 取队头元素（并不删除），队空抛出异常信息Downflow
    bool Empty();      // 判断队列是否为空，空返回true，否则返回false
    bool Full();       // 判断队列是否为满，满返回true，否则返回false
private:
    T data[QueueSize]; // 存放队列元素的数组
    int front, rear;   // 队头和队尾指针，分别指向队头元素所在数组的前一下标和队尾元素的数组下标
};

template <class T>
CirQueue<T>::CirQueue()
{
    front = rear = QueueSize - 1;
}

template <class T>
CirQueue<T>::~CirQueue()
{
}

template <class T>
void CirQueue<T>::EnQueue(T x)
{
    if (Full())
        throw "Overflow";
    rear = (rear + 1) % QueueSize;
    data[rear] = x;
}

template <class T>
T CirQueue<T>::DeQueue()
{
    if (Empty())
        throw "Downflow";
    front = (front + 1) % QueueSize;
    return data[front];
}

template <class T>
T CirQueue<T>::GetQueue()
{
    if (Empty())
        throw "Downflow";
    int next_front = (front + 1) % QueueSize;
    return data[next_front];
}

template <class T>
bool CirQueue<T>::Empty()
{
    return front == rear;
}

template <class T>
bool CirQueue<T>::Full()
{
    return (rear + 1) % QueueSize == front;
}

int main()
{
    CirQueue<string> Q;
    string x;
    while (1)
    {
        cin >> x;
        if (x == "#")
            break;
        try
        {
            cout << "EnQueue:";
            Q.EnQueue(x);
            cout << x << "\n";
        }
        catch (const char *ms)
        {
            cout << x << " " << ms << endl;
        }
    }
    while (!Q.Empty())
    {
        x = Q.DeQueue();
        cout << "DeQueue:" << x << endl;
    }
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
