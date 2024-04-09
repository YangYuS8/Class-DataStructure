#include <iostream>
using namespace std;

// 结点结构
template <class T>
struct Node {
    T data;
    Node<T> *next;
};

// 链表类
template <class T>
class SortList {
public:
    SortList(); // 建立只有头结点的空链表
    ~SortList(); // 析构函数
    void Insert(T x); // 递增有序表插入x，使序列仍有序
    void DeleteEven(); // 在单链表中删除所有偶数，不需返回被删除数据个数
    void DispList(); // 遍历单链表，依次输出各元素
private:
    Node<T> *first; // 单链表的头指针
};

// 构造函数
template <class T>
SortList<T>::SortList() {
    first = new Node<T>;
    first->next = NULL;
}

// 析构：释放内存
template <class T>
SortList<T>::~SortList() {
    Node<T> *s;
    while (first) {
        s = first;
        first = first->next;
        delete s;
    }
}

// 插入元素
template <class T>
void SortList<T>::Insert(T x) {
    Node<T> *p = first;
    while (p->next && p->next->data <= x)
        p = p->next;
    Node<T> *s = new Node<T>;
    s->data = x;
    s->next = p->next;
    p->next = s;
}

// 删除所有偶数结点
template <class T>
void SortList<T>::DeleteEven() {
    Node<T> *p = first->next; // 工作指针
    Node<T> *prev = first; // 前驱结点指针
    while (p != NULL) {
        if (p->data % 2 == 0) { // 如果当前结点为偶数
            Node<T> *temp = p;
            prev->next = p->next;
            p = p->next;
            delete temp; // 删除当前结点
        } else {
            prev = p;
            p = p->next;
        }
    }
}

// 遍历链表并输出元素
template <class T>
void SortList<T>::DispList() {
    cout << "Data:";
    Node<T> *p = first->next;
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main() {
    SortList<int> A;
    int x;
    // 利用有序表的插入创建一个有序链表，输入数据以0结束
    while (true) {
        cin >> x;
        if (x == 0) break;
        A.Insert(x);
    }

    A.DispList(); // 遍历并输出原始链表

    A.DeleteEven(); // 删除偶数结点

    A.DispList(); // 遍历并输出删除偶数后的链表

    return 0;
}
