#include <iostream>
using namespace std;

// 节点结构体
template <class T>
struct Node {
    T data; // 数据域
    Node<T> *next; // 指针域
};

// 有序链表类
template <class T>
class LinkSortList {
public:
    LinkSortList(); // 建立只有头结点的空链表
    ~LinkSortList(); // 析构函数
    void Insert(T x); // 在有序单链表中插入元素x使序列仍有序
    int Length(); // 求表长
    int DeleteOdd(); // 在单链表中删除所有奇数，返回值为奇数个数
    void DispList(); // 遍历有序单链表，按序号依次输出各元素
private:
    Node<T> *first; // 单链表的头指针
};

template <class T>
LinkSortList<T>::LinkSortList() { // 建立只有头结点的空链表
    first = new Node<T>;
    first->next = nullptr;
}

template <class T>
LinkSortList<T>::~LinkSortList() { // 析构函数，释放内存
    Node<T> *p = first;
    while (first != nullptr) {
        first = first->next;
        delete p;
        p = first;
    }
}

template <class T>
void LinkSortList<T>::Insert(T x) { // 在有序单链表中插入元素x使序列仍有序
    Node<T> *p = first;
    while (p->next != nullptr && p->next->data < x) { // 找到插入位置
        p = p->next;
    }
    Node<T> *newNode = new Node<T>;
    newNode->data = x;
    newNode->next = p->next;
    p->next = newNode;
}

template <class T>
int LinkSortList<T>::Length() { // 求表长
    int len = 0;
    Node<T> *p = first->next;
    while (p != nullptr) {
        len++;
        p = p->next;
    }
    return len;
}

template <class T>
int LinkSortList<T>::DeleteOdd() { // 在单链表中删除所有奇数，返回值为奇数个数
    int count = 0;
    Node<T> *p = first->next;
    Node<T> *prev = first;
    while (p != nullptr) {
        if (p->data % 2 != 0) { // 如果为奇数
            Node<T> *temp = p;
            prev->next = p->next;
            p = p->next;
            delete temp;
            count++;
        } else {
            prev = p;
            p = p->next;
        }
    }
    return count;
}

template <class T>
void LinkSortList<T>::DispList() { // 遍历有序单链表，按序号依次输出各元素
    cout << "The length:" << Length() << endl;
    cout << "The elements:";
    Node<T> *p = first->next;
    while (p != nullptr) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main() {
    LinkSortList<int> sa;
    int x;
    while (true) {
        cin >> x;
        if (x == 0) break;
        sa.Insert(x);
    }
    sa.DispList();
    int count = sa.DeleteOdd();
    cout << "Count of deleted odds:" << count << endl;
    sa.DispList();
    return 0;
}
