#include <iostream>
using namespace std;

//头结点
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
    LinkList();              //建立只有头结点的空链表
    ~LinkList();             //析构函数
    void InsertR(T x);       //在链表的表尾位置插入元素值为x的结点
    void InsertF(T x);       //在链表的头结点后插入元素值为x的结点
    void DispList();         //遍历链表，依次输出各元素
    void AddDx(int dx);      //将表中不是3的倍数的元素值增dx，其它值不变

private:
    Node<T> *first;  //单链表的头指针
};

//构造只有头结点的空表
template <class T>
LinkList<T>::LinkList()
{
    first = new Node<T>;
    first->next = NULL;
}

//析构
template <class T>
LinkList<T>::~LinkList()
{
    Node<T> *s;
    while (first)
    {
        s = first;
        first = first->next;
        delete s;
    }
}

template <class T>
void LinkList<T>::InsertR(T x)
{
    Node<T> *p = first;
    while (p->next != NULL)
        p = p->next;
    Node<T> *newNode = new Node<T>;
    newNode->data = x;
    newNode->next = NULL;
    p->next = newNode;
}

template <class T>
void LinkList<T>::InsertF(T x)
{
    Node<T> *newNode = new Node<T>;
    newNode->data = x;
    newNode->next = first->next;
    first->next = newNode;
}

template <class T>
void LinkList<T>::DispList()
{
    Node<T> *p = first->next;
    cout << "Data:";
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

template <class T>
void LinkList<T>::AddDx(int dx)
{
    Node<T> *p = first->next;
    while (p != NULL)
    {
        if (p->data % 3 != 0)
            p->data += dx;
        p = p->next;
    }
}

int main()
{
    LinkList<int> A;
    int x;
    while (1)
    {
        cin >> x; //输入整数
        if (!x)
            break; //为0退出
        A.InsertR(x); //表尾插入
    }
    A.DispList();
    int dx;
    cin >> dx; //输入dx
    A.AddDx(dx);
    A.DispList();

    LinkList<char> B;
    char ch;
    int n;
    cin >> n; //输入个数n
    for (int i = 1; i <= n; i++)
    {
        cin >> ch;      //输入n个字符
        B.InsertF(ch);  //表头后插入
    }
    B.DispList();
    return 0;
}
