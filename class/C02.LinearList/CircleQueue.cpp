#include<iostream>
using namespace std;
const int MaxSize = 5;

template<class T>
class CircleQueue
{
public:
    CircleQueue();
    ~CircleQueue(){}
    void EnQueue(T x);
    T DeQueue();
    T GetFront();
    void Print();
    bool Empty();
    bool Full();
private:
    T data[MaxSize];
    int front, rear;    
    // front指向队头元素,处理出队   
    // rear指向队尾元素的下标,处理入队
};

template<class T>
CircleQueue<T>::CircleQueue()
{
    front = rear = 0;   //构造空队列，初始化私有成员
}

template<class T>
void CircleQueue<T>::EnQueue(T x)
{
    if (Full()) //队列已满
        throw "队列已满";
    data[rear] = x; //新元素入队
    rear = (rear + 1) % MaxSize; //rear指向下一个位置
}

template<class T>
T CircleQueue<T>::DeQueue()
{
    if (Empty()) //队列为空
    {
        throw "队列为空";
    }
    T x = data[front]; //保存队头元素
    front = (front + 1) % MaxSize; //front指向下一个位置
    return x; //返回队头元素
}

template<class T>
T CircleQueue<T>::GetFront()
{
    if (Empty()) //队列为空
    {
        throw "队列为空";
    }
    return data[front]; //返回队头元素
}

template<class T>
void CircleQueue<T>::Print()
{
    /*  //以下注释部分为另一种思路
    int i = front; //从队头开始遍历
    while (i != rear) //遍历到队尾
    {
        cout << data[i] << " "; //输出元素
        i = (i + 1) % MaxSize; //i指向下一个位置
    }
    cout << endl;
    */

    if (rear > front)
    {
        for (int i = front; i < rear; i++)
        {
            cout << data[i] << " ";
        }
    }
    else if (rear < front)
    {
        for (int i = front; i < MaxSize; i++)
        {
            cout << data[i] << " ";
        }
        for (int i = 0; i < rear; i++)
        {
            cout << data[i] << " ";
        }
    }
    else
        cout << "队列为空";
    cout << endl;
}

template<class T>
bool CircleQueue<T>::Empty()
{
    return front == rear; //队列为空时，front和rear相等
}

template<class T>
bool CircleQueue<T>::Full()
{
    return (rear + 1) % MaxSize == front; //队列满时，rear的下一个位置为front
}

int main()
{
    CircleQueue<int> q;
    int x;
    cout << "请选择操作：1.入队 2.出队 3.打印 4.判断空 5.判断满 0.退出" << endl; 
    cin >> x;
    try
    {
        while (x!=0)
        {
            switch (x)
            {
            case 1:
                cout << "请输入入队元素：";
                cin >> x;
                q.EnQueue(x);
                break;
            case 2:
                cout << "出队元素：" << q.DeQueue() << endl;
                break;
            case 3:
                q.Print();
                break;
            case 4:
                cout << "队列是否为空：" << q.Empty() << endl;  // 1为空，0不为空
                break;
            case 5:
                cout << "队列是否已满：" << q.Full() << endl;  // 1为满，0不满
                break;
            default:
                break;
            }
            cout << "请选择操作：1.入队 2.出队 3.打印 4.判断空 5.判断满 0.退出" << endl; 
            cin >> x;
        }
    }
    catch(const std::exception& e)  // 捕获异常
    {
        std::cerr << e.what() << '\n';  // 输出异常信息
    }
    return 0;
}