#include <iostream>
using namespace std;

const int MaxSize = 100; // 假设顺序表的最大长度为100

// 有序表类
template <class T>
class SortList {
public:
    SortList() {
        length = 0;
    } // 置空表
    ~SortList() {}
    void Insert(T x); // 非递减有序表的插入x，使序列仍有序
    void DispList(); // 输出表

private:
    T data[MaxSize]; // 存储元素
    int length;       // 顺序表实际长度
};

template <class T>
void SortList<T>::Insert(T x) { // 插入元素使表仍有序
    if (length >= MaxSize)
        throw "Overflow"; // 超出最大长度，抛出异常
    int i = length - 1;
    while (i >= 0 && data[i] > x) { // 找到合适的位置插入
        data[i + 1] = data[i];
        i--;
    }
    data[i + 1] = x; // 在i+1位置插入元素
    length++; // 长度加1
}

template <class T>
void SortList<T>::DispList() { // 输出表
    cout << "The length:" << length << endl;
    cout << "The elements:" << endl;
    for (int i = 0; i < length; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}

// 构造有序表A：函数定义
template <class T>
void CreateSort(SortList<T> &A) {
    int n;
    T x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        try {
            A.Insert(x);
        } catch (const char *wrong) {
            cout << wrong << endl;
        }
    }
}

int main() {
    SortList<int> A; // 整型数据表A
    // 生成一个有序表A
    CreateSort(A);
    SortList<char> B; // 字符型数据表B
    CreateSort(B);
    A.DispList();
    B.DispList();
    return 0;
}
