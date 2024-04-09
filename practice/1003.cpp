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
    void Insert(T x); // 有序表的插入，使序列仍有序
    void DispList(); // 输出表
    void Merge(SortList<T> &A, SortList<T> &B); // 合并两个有序表，使序列仍有序

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

template <class T>
void SortList<T>::Merge(SortList<T> &A, SortList<T> &B) { // 合并两个有序表
    int i = 0, j = 0, k = 0;
    while (i < A.length && j < B.length) { // 依次比较A和B的元素，将较小的插入当前表中
        if (A.data[i] <= B.data[j]) {
            data[k++] = A.data[i++];
        } else {
            data[k++] = B.data[j++];
        }
    }
    while (i < A.length) // 将A剩余的元素插入当前表中
        data[k++] = A.data[i++];
    while (j < B.length) // 将B剩余的元素插入当前表中
        data[k++] = B.data[j++];
    length = k; // 更新表的长度
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
    SortList<int> A, B, C;
    // 生成一个有序表A
    CreateSort(A);
    // 生成一个有序表B
    CreateSort(B);
    try {
        C.Merge(A, B); // 合并A,B表为C表
    } catch (const char *wrong) {
        cout << wrong; // 如失败提示失败信息
    }
    A.DispList();
    B.DispList();
    C.DispList(); // 显示合并后的结果
    return 0;
}
