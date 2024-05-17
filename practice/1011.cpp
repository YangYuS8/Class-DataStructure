#include <iostream>
using namespace std;

template <class T>
struct Node
{
    T data;
    Node<T> *next;
};

template <class T>
class LinkList
{
public:
    LinkList();                                  // 建立只有头结点的空链表
    ~LinkList();                                 // 析构函数
    int Length();                                // 求单链表的长度
    void Insert(int i, T x);                     // 在单链表中第i个位置插入元素值为x的结点
    void Divide(LinkList<T> &A, LinkList<T> &B); // 将当前链表分解为A，B表
    void DispList();                             // 遍历单链表，按序号依次输出各元素

private:
    Node<T> *first; // 单链表的头指针
};

template <class T>
LinkList<T>::LinkList()
{
    first = new Node<T>;
    first->next = nullptr;
}

template <class T>
LinkList<T>::~LinkList()
{
    Node<T> *p = first;
    while (first != nullptr)
    {
        p = first;
        first = first->next;
        delete p;
    }
}

template <class T>
int LinkList<T>::Length()
{
    int len = 0;
    Node<T> *p = first->next;
    while (p)
    {
        len++;
        p = p->next;
    }
    return len;
}

template <class T>
void LinkList<T>::Insert(int i, T x)
{
    Node<T> *p = first;
    int j = 0;
    while (p && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (!p || j > i - 1)
        throw "Insert failed.";
    Node<T> *s = new Node<T>;
    s->data = x;
    s->next = p->next;
    p->next = s;
}

template <class T>
void LinkList<T>::Divide(LinkList<T> &A, LinkList<T> &B)
{
    Node<T> *p = first->next;  // 当前链表的第一个结点
    Node<T> *a_head = A.first; // 表A的头结点
    Node<T> *b_head = B.first; // 表B的头结点

    // 分别初始化A和B表为空表
    A.first->next = nullptr;
    B.first->next = nullptr;

    while (p)
    {
        if (p->data % 2 == 0)
        {
            // 将偶数结点插入到表B的头结点之后
            Node<T> *temp = p->next;
            p->next = b_head->next;
            b_head->next = p;
            p = temp;
            B.first->data++;
        }
        else
        {
            // 将奇数结点插入到表A的头结点之后
            Node<T> *temp = p->next;
            p->next = a_head->next;
            a_head->next = p;
            p = temp;
            A.first->data++;
        }
    }

    // 将当前链表置为空表
    first->next = nullptr;
}

template <class T>
void LinkList<T>::DispList()
{
    Node<T> *p = first->next;
    cout << "The length:" << Length() << endl;
    cout << "The elements:";
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main()
{
    LinkList<int> A, B, C;
    int x, i = 1;
    while (true)
    {
        cin >> x;
        if (!x)
            break;
        try
        {
            C.Insert(i++, x);
        }
        catch (const char *ms)
        {
            cout << ms << endl;
        }
    }
    C.DispList();
    C.Divide(A, B);
    C.DispList();
    A.DispList();
    B.DispList();
    return 0;
}
