// 本文件由chatGPT生成，仅供参考
#include <iostream>
using namespace std;
template <class T>
class SeqQueue
{
private:
    T *data;
    int front, rear;
    int maxSize;

public:
    SeqQueue(int size = 100);
    ~SeqQueue();
    bool Empty() const;
    bool Full() const;
    void EnQueue(const T &x);
    T DeQueue();
    T GetFront() const;
};

template <class T>
SeqQueue<T>::SeqQueue(int size)
{
    data = new T[size];
    front = rear = 0;
    maxSize = size;
}

template <class T>
SeqQueue<T>::~SeqQueue()
{
    delete[] data;
}

template <class T>
bool SeqQueue<T>::Empty() const
{
    return front == rear;
}

template <class T>
bool SeqQueue<T>::Full() const
{
    return (rear + 1) % maxSize == front;
}

template <class T>
void SeqQueue<T>::EnQueue(const T &x)
{
    if (Full())
    {
        cerr << "Queue is full" << endl;
        exit(1);
    }
    data[rear] = x;
    rear = (rear + 1) % maxSize;
}

template <class T>
T SeqQueue<T>::DeQueue()
{
    if (Empty())
    {
        cerr << "Queue is empty" << endl;
        exit(1);
    }
    T temp = data[front];
    front = (front + 1) % maxSize;
    return temp;
}

template <class T>
T SeqQueue<T>::GetFront() const
{
    if (Empty())
    {
        cerr << "Queue is empty" << endl;
        exit(1);
    }
    return data[front];
}