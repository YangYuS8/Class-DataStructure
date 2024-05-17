#include <iostream>
using namespace std;

template <class T>
struct Node
{
    T data;
    Node<T> *next;
};

template <class T>
class LinkSortList
{
public:
    LinkSortList();   // 建立只有头结点的空链表
    ~LinkSortList();  // 析构函数
    void Insert(T x); // sort insert
    int Length();
    void DispList();                                    // 遍历单链表，按序号依次输出各元素
    void Merge(LinkSortList<T> &A, LinkSortList<T> &B); // 合并A,B到当前类

private:
    Node<T> *first; // 单链表的头指针
};

template <class T>
LinkSortList<T>::LinkSortList()
{
    first = new Node<T>;
    first->next = nullptr;
}

template <class T>
LinkSortList<T>::~LinkSortList()
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
void LinkSortList<T>::Insert(T x)
{
    Node<T> *p = first;
    while (p->next && p->next->data < x)
    {
        p = p->next;
    }
    Node<T> *s = new Node<T>;
    s->data = x;
    s->next = p->next;
    p->next = s;
}

template <class T>
int LinkSortList<T>::Length()
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
void LinkSortList<T>::DispList()
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

template <class T>
void LinkSortList<T>::Merge(LinkSortList<T> &A, LinkSortList<T> &B)
{
    Node<T> *p = A.first->next;
    Node<T> *q = B.first->next;

    while (p && q)
    {
        if (p->data <= q->data)
        {
            Node<T> *temp = p->next;
            p->next = first->next;
            first->next = p;
            p = temp;
        }
        else
        {
            Node<T> *temp = q->next;
            q->next = first->next;
            first->next = q;
            q = temp;
        }
    }

    while (p)
    {
        Node<T> *temp = p->next;
        p->next = first->next;
        first->next = p;
        p = temp;
    }

    while (q)
    {
        Node<T> *temp = q->next;
        q->next = first->next;
        first->next = q;
        q = temp;
    }

    A.first->next = nullptr;
    B.first->next = nullptr;
}

int main()
{
    LinkSortList<int> A, B, C;
    int x;
    while (true)
    {
        cin >> x;
        if (!x)
            break;
        A.Insert(x);
    }

    while (true)
    {
        cin >> x;
        if (!x)
            break;
        B.Insert(x);
    }

    A.DispList();
    B.DispList();

    C.Merge(A, B);
    C.DispList();

    A.DispList();
    B.DispList();

    return 0;
}
