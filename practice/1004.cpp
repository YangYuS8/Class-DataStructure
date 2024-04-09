#include <iostream>
using namespace std;

// 节点结构体
template <class T>
struct Node {
    T data; // 数据域
    Node<T> *next; // 指针域
};

// 链表类
template <class T>
class LinkList {
public:
    LinkList(); // 建立只有头结点的空链表
    ~LinkList(); // 析构函数
    int Length(); // 求单链表的长度
    int Locate(T x); // 求单链表中值为x的元素序号
    void Insert(int i, T x); // 在单链表中第i个位置插入元素值为x的结点
    void Reverse(); // reverse list
    void DispList(); // 遍历单链表，按序号依次输出各元素
private:
    Node<T> *first; // 单链表的头指针
};

template <class T>
LinkList<T>::LinkList() { // 建立只有头结点的空链表
    first = new Node<T>;
    first->next = nullptr;
}

template <class T>
LinkList<T>::~LinkList() { // 析构函数，释放内存
    Node<T> *p = first;
    while (first != nullptr) {
        first = first->next;
        delete p;
        p = first;
    }
}

template <class T>
int LinkList<T>::Length() { // 求单链表的长度
    int len = 0;
    Node<T> *p = first->next;
    while (p != nullptr) {
        len++;
        p = p->next;
    }
    return len;
}

template <class T>
int LinkList<T>::Locate(T x) { // 求单链表中值为x的元素序号，不存在返回0
    int pos = 0;
    Node<T> *p = first->next;
    while (p != nullptr) {
        pos++;
        if (p->data == x) {
            return pos;
        }
        p = p->next;
    }
    return 0;
}

template <class T>
void LinkList<T>::Insert(int i, T x) { // 在单链表中第i个位置插入元素值为x的结点
    if (i < 1) {
        cout << "Invalid position." << endl;
        return;
    }
    int j = 0;
    Node<T> *p = first;
    while (p != nullptr && j < i - 1) { // 找到第i-1个结点
        p = p->next;
        j++;
    }
    if (p == nullptr) {
        cout << "Invalid position." << endl;
        return;
    }
    Node<T> *newNode = new Node<T>;
    newNode->data = x;
    newNode->next = p->next;
    p->next = newNode;
}

template <class T>
void LinkList<T>::Reverse() { // reverse list
    Node<T> *prev = nullptr;
    Node<T> *current = first->next;
    Node<T> *next = nullptr;
    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    first->next = prev;
}

template <class T>
void LinkList<T>::DispList() { // 遍历单链表，按序号依次输出各元素
    cout << "The length:" << Length() << endl;
    cout << "The elements:" << endl;
    Node<T> *p = first->next;
    while (p != nullptr) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main() {
    LinkList<int> list;
    int num;
    cin >> num;
    while (num != 0) {
        list.Insert(1, num); // 插入到表的1号位置
        cin >> num;
    }
    list.DispList();

    int target;
    cin >> target;
    int position = list.Locate(target);
    if (position != 0) {
        cout << "Found position:" << position << endl;
    } else {
        cout << "No found" << endl;
    }

    list.Reverse();
    list.DispList();

    return 0;
}
