#include <iostream>
using namespace std;

// 节点类
template <class T>
struct Node
{
    T data;        // 数据域
    Node<T> *next; // 指针域
};

// 单向循环链表类
template <class T>
class LinkList
{
public:
    LinkList();       // 建立只有头结点的空链表
    ~LinkList();      // 析构函数
    int Length();     // 求单链表的长度
    void Insert(T x); // 在单链表中的表尾位置插入元素值为x的结点
    void Reverse();   // 逆置链表
    void DispList();  // 遍历单链表，按序号依次输出各元素
private:
    Node<T> *first; // 单链表的头指针
};

// 构造函数
template <class T>
LinkList<T>::LinkList()
{
    first = new Node<T>;
    first->next = first;
}

// 析构函数：释放链表各个结点所占内存单元
template <class T>
LinkList<T>::~LinkList()
{
    Node<T> *s = first->next;
    while (s != first)
    {
        first->next = s->next;
        delete s;
        s = first->next;
    }
    delete s;
}

// 求单链表的长度
template <class T>
int LinkList<T>::Length()
{
    int len = 0;
    Node<T> *p = first->next;
    while (p != first)
    {
        len++;
        p = p->next;
    }
    return len;
}

// 在单链表中的表尾位置插入元素值为x的结点
template <class T>
void LinkList<T>::Insert(T x)
{
    Node<T> *p = first;
    while (p->next != first)
    {
        p = p->next;
    }
    Node<T> *newNode = new Node<T>;
    newNode->data = x;
    newNode->next = first;
    p->next = newNode;
}

// 逆置链表
template <class T>
void LinkList<T>::Reverse()
{
    if (first->next == first || first->next->next == first) // 链表为空或者只有一个节点时不用逆置
        return;

    Node<T> *p = first->next;
    Node<T> *q = nullptr;
    while (p != first)
    {
        Node<T> *temp = p->next;
        p->next = q;
        q = p;
        p = temp;
    }
    first->next = q;
}

// 遍历单链表，按序号依次输出各元素
template <class T>
void LinkList<T>::DispList()
{
    cout << "The length:" << Length() << endl;
    cout << "The elements:";
    Node<T> *p = first->next;
    while (p != first)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main()
{
    LinkList<int> sa;
    int x;
    while (1)
    {
        cin >> x;
        if (!x)
            break;
        sa.Insert(x);
    }
    sa.DispList();
    sa.Reverse();
    sa.DispList();
    return 0;
}
