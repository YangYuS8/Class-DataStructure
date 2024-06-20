// 请在LinkSortList类的基础上添加成员函数Merge，实现将两个有序表A，B的合并为表C，C中序列仍有序。要求利用A，B中的结点进行合并，合并后A，B置为空表。main代码已知，请勿改动。
#include <iostream>
using namespace std;

// 定义节点结构体
template <class T>
struct Node
{
    T data;        // 数据域
    Node<T> *next; // 指针域，指向下一个节点
};

// 有序表类
template <class T>
class LinkSortList
{
public:
    LinkSortList();                                     // 建立只有头结点的空链表
    ~LinkSortList();                                    // 析构函数
    void Insert(T x);                                   // 有序插入
    int Length();                                       // 获取链表长度
    void DispList();                                    // 遍历单链表，按序号依次输出各元素
    void Merge(LinkSortList<T> &A, LinkSortList<T> &B); // 合并A, B到当前类
    void Display();                                     // 显示链表长度和元素

private:
    Node<T> *first; // 单链表的头指针
};

// 构造函数，初始化只有头结点的空链表
template <class T>
LinkSortList<T>::LinkSortList()
{
    first = new Node<T>;
    first->next = nullptr;
}

// 析构函数，释放所有节点
template <class T>
LinkSortList<T>::~LinkSortList()
{
    Node<T> *p = first;
    while (p != nullptr)
    {
        Node<T> *temp = p;
        p = p->next;
        delete temp;
    }
}

// 有序插入节点
template <class T>
void LinkSortList<T>::Insert(T x)
{
    Node<T> *p = first;
    while (p->next != nullptr && p->next->data < x)
    {
        p = p->next;
    }
    Node<T> *newNode = new Node<T>;
    newNode->data = x;
    newNode->next = p->next;
    p->next = newNode;
}

// 获取链表长度
template <class T>
int LinkSortList<T>::Length()
{
    int len = 0;
    Node<T> *p = first->next;
    while (p != nullptr)
    {
        len++;
        p = p->next;
    }
    return len;
}

// 遍历单链表，按序号依次输出各元素
template <class T>
void LinkSortList<T>::DispList()
{
    Node<T> *p = first->next;
    while (p != nullptr)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

// 合并A, B到当前类
template <class T>
void LinkSortList<T>::Merge(LinkSortList<T> &A, LinkSortList<T> &B)
{
    Node<T> *pA = A.first->next;
    Node<T> *pB = B.first->next;
    Node<T> *pC = first;

    while (pA != nullptr && pB != nullptr)
    {
        if (pA->data <= pB->data)
        {
            pC->next = pA;
            pA = pA->next;
        }
        else
        {
            pC->next = pB;
            pB = pB->next;
        }
        pC = pC->next;
    }

    if (pA != nullptr)
    {
        pC->next = pA;
    }
    else
    {
        pC->next = pB;
    }

    A.first->next = nullptr;
    B.first->next = nullptr;
}

// 显示链表长度和元素
template <class T>
void LinkSortList<T>::Display()
{
    cout << "The length:" << Length() << endl;
    cout << "The elements:";
    DispList();
}

// 主函数
int main()
{
    LinkSortList<int> A, B, C;
    int x;
    // 输入有序表A
    while (1)
    {
        cin >> x;
        if (!x)
            break;
        A.Insert(x);
    }
    // 输入有序表B
    while (1)
    {
        cin >> x;
        if (!x)
            break;
        B.Insert(x);
    }
    // 显示A
    A.Display();
    // 显示B
    B.Display();
    // 合并A和B到C
    C.Merge(A, B);
    // 显示C
    C.Display();
    // 显示A（应该为空）
    A.Display();
    // 显示B（应该为空）
    B.Display();
    return 0;
}
