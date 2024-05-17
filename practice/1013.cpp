#include <iostream>
using namespace std;

// 双向循环链表结点类
template <class T>
struct DNode
{
    T data;
    DNode<T> *prior, *next;
};

// 双向循环链表类
template <class T>
class DLinkList
{
public:
    DLinkList();      // 建立只有头结点的双向循环链表
    ~DLinkList();     // 析构函数
    int Length();     // 求链表的长度
    void Insert(T x); // 表尾插入x
    void DispListF(); // 正向遍历链表，按照逻辑序号输出各元素
    void DispListR(); // 反向遍历链表，按照反向逻辑序号输出各元素
private:
    DNode<T> *first; // 链表的头指针
};

// 构造函数
template <class T>
DLinkList<T>::DLinkList()
{
    first = new DNode<T>;
    first->next = first->prior = first;
}

// 析构函数
template <class T>
DLinkList<T>::~DLinkList()
{
    DNode<T> *s = first->next;
    while (s != first)
    {
        first->next = s->next;
        delete s;
        s = first->next;
    }
    delete s;
}

// 求链表的长度
template <class T>
int DLinkList<T>::Length()
{
    int len = 0;
    DNode<T> *p = first->next;
    while (p != first)
    {
        len++;
        p = p->next;
    }
    return len;
}

// 表尾插入x
template <class T>
void DLinkList<T>::Insert(T x)
{
    DNode<T> *p = first;
    while (p->next != first)
    {
        p = p->next;
    }
    DNode<T> *newNode = new DNode<T>;
    newNode->data = x;
    newNode->next = first;
    newNode->prior = p;
    p->next = newNode;
    first->prior = newNode;
}

// 正向遍历链表，按照逻辑序号输出各元素
template <class T>
void DLinkList<T>::DispListF()
{
    cout << "The length:" << Length() << endl;
    cout << "The elements:";
    DNode<T> *p = first->next;
    while (p != first)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

// 反向遍历链表，按照反向逻辑序号输出各元素
template <class T>
void DLinkList<T>::DispListR()
{
    cout << "The length:" << Length() << endl;
    cout << "The elements:";
    DNode<T> *p = first->prior;
    while (p != first)
    {
        cout << p->data << " ";
        p = p->prior;
    }
    cout << endl;
}

int main()
{
    DLinkList<string> DL;
    string name;
    int i, n;
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cin >> name;
        DL.Insert(name);
    }
    DL.DispListF();
    DL.DispListR();
    return 0;
}
