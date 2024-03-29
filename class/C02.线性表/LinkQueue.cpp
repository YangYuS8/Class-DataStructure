#include<iostream>
using namespace std;

template<class T>
struct Node
{
	T data;
	Node<T> *next;
};

template<class T>
class LinkOueue
{
public:
    LinkOueue();        // 构造函数
    ~LinkOueue();       // 析构函数
    void EnQueue(T x);  // 入队
    T DeQueue();        // 出队
    T GetFront();       // 获取队头元素
    void Print();       // 打印队列
    bool Empty();       // 判断队列是否为空
private:
    Node<T> *front, *rear;
};

template<class T>
LinkOueue<T>::LinkOueue()   // 构造函数
{
    front = rear = new Node<T>;
    front->next = NULL;
}

template<class T>
LinkOueue<T>::~LinkOueue()  // 析构函数
{
    while(front)
    {
        Node<T> *temp = front;
        front = front->next;
        delete temp;
    }
}

template<class T>
void LinkOueue<T>::EnQueue(T x) // 入队
{
    Node<T> *s = new Node<T>;
    s->data = x;    // 新结点数据域赋值
    s->next = NULL; // 新结点指针域为空
    rear->next = s; // 原队尾结点指针域指向新结点
    rear = s;       // rear指向新结点
}

template<class T>
T LinkOueue<T>::DeQueue()   // 出队
{
    if (front == rear)  // 队列为空
    {
        throw "队列为空";
    }
    Node<T> *temp = front->next;    // 指向队头结点
    T x = temp->data;   // 保存队头元素
    front->next = temp->next;   // front指向队头结点的下一个结点
    if (rear == temp)   // 删除最后一个结点时，rear指向头结点
    {
        rear = front;
    }
    delete temp;    // 释放原队头结点
    return x;       // 返回队头元素
}

template<class T>
bool LinkOueue<T>::Empty()  // 判断队列是否为空
{
    return front == rear;   // 队列为空时，front和rear指向同一个结点
}

template<class T>
void LinkOueue<T>::Print()  // 打印队列
{
    Node<T> *temp = front->next;    // 指向队头结点
    while(temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    LinkOueue<int> q;
    int x;
    cout << "请选择操作：1.入队 2.出队 3.打印 4.判断空 0.退出" << endl; 
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
            default:
                break;
            }
            cout << "请选择操作：1.入队 2.出队 3.打印 4.判断空 0.退出" << endl; 
            cin >> x;
        }
    }
    catch(const std::exception& e)  // 捕获异常
    {
        std::cerr << e.what() << '\n';  // 输出异常信息
    }
    return 0;
}