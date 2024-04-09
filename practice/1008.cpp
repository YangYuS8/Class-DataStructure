#include <iostream>
using namespace std;

// 头结点
template <class T>
struct Node {
    T data;
    Node<T> *next; 
};

template <class T>
class LinkList {
public:
    LinkList();          // 建立只有头结点的空链表
    ~LinkList();         // 析构函数
    void InsertR(T x);   // 在链表的表尾位置插入元素值为x的结点
    void InsertF(T x);   // 在链表的头结点后插入元素值为x的结点
    void DispList();     // 遍历链表，依次输出各元素
    void SubDx(int dx);  // 将表中是小写字母的元素值减dx，其它值不变

private:
    Node<T> *first;  // 单链表的头指针
};

// 构造只有头结点的空表
template <class T>
LinkList<T>::LinkList() {
    first = new Node<T>;
    first->next = NULL;
}

// 析构
template <class T>
LinkList<T>::~LinkList() {
    Node<T> *s;
    while (first) {
        s = first;
        first = first->next;
        delete s;
    }
}

// 在链表的表尾位置插入元素值为x的结点
template <class T>
void LinkList<T>::InsertR(T x) {
    Node<T> *p = first;
    while (p->next != NULL) {
        p = p->next;
    }
    Node<T> *s = new Node<T>;
    s->data = x;
    s->next = NULL;
    p->next = s;
}

// 在链表的头结点后插入元素值为x的结点
template <class T>
void LinkList<T>::InsertF(T x) {
    Node<T> *s = new Node<T>;
    s->data = x;
    s->next = first->next;
    first->next = s;
}

// 遍历链表并输出元素
template <class T>
void LinkList<T>::DispList() {
    Node<T> *p = first->next;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

// 将表中是小写字母的元素值减dx，其它值不变
template <class T>
void LinkList<T>::SubDx(int dx) {
    Node<T> *p = first->next;
    while (p != NULL) {
        if (p->data >= 'a' && p->data <= 'z') {
            p->data -= dx;
        }
        p = p->next;
    }
}

int main() {
    LinkList<char> A;
    char ch;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> ch;
        A.InsertF(ch);
    }

    cout << "Data:";
    A.DispList();

    int dx;
    cin >> dx;
    A.SubDx(dx);

    cout << "Data:";
    A.DispList();

    LinkList<int> B;
    int x;
    while (true) {
        cin >> x;
        if (x == 0) break;
        B.InsertR(x);
    }

    cout << "Data:";
    B.DispList();

    return 0;
}
