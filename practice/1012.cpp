// 单向循环表类的定义及部分函数和main函数代码（请勿改动）如下，请完成Length、Insert、Reverse和DispList算法。
#include <iostream>
using namespace std;

// 定义节点结构体
template <class T>
struct Node
{
    T data;        // 数据域
    Node<T> *next; // 指针域，指向下一个节点
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

// 构造函数，初始化只有头结点的空链表
template <class T>
LinkList<T>::LinkList()
{
    first = new Node<T>;
    first->next = first;
}

// 析构函数，释放链表各个结点所占内存单元
template <class T>
LinkList<T>::~LinkList()
{
    Node<T> *s;
    s = first->next;
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
    // 找到最后一个节点
    while (p->next != first)
    {
        p = p->next;
    }
    // 创建新节点
    Node<T> *newNode = new Node<T>;
    newNode->data = x;
    newNode->next = first; // 新节点的next指向头结点
    p->next = newNode;     // 将最后一个节点的next指向新节点
}

// 逆置链表
template <class T>
void LinkList<T>::Reverse()
{
    if (first->next == first || first->next->next == first)
    {
        return; // 如果链表为空或只有一个元素，无需逆置
    }
    Node<T> *prev = first;
    Node<T> *curr = first->next;
    Node<T> *next;
    while (curr != first)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    first->next->next = first;
    first->next = prev;
}

// 遍历单链表，按序号依次输出各元素
template <class T>
void LinkList<T>::DispList()
{
    Node<T> *p = first->next;
    cout << "The length:" << Length() << endl;
    cout << "The elements:" << endl;
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
    // 输入有序表
    while (1)
    {
        cin >> x;
        if (!x)
            break;
        sa.Insert(x);
    }
    // 显示链表
    sa.DispList();
    // 逆置链表
    sa.Reverse();
    // 显示逆置后的链表
    sa.DispList();
    return 0;
}
