#include <iostream>
using namespace std;

const int MaxSize = 5; // 顺序表的最大长度

// 顺序表类
template <class T>
class SList {
public:
    SList() {
        length = 0;
    }
    ~SList() {}
    void Insert(int i, T x);    // i位置插入x
    void DispList();            // 输出表
    void DispNum();             // 输出所有不能被3整除的数据
private:
    T data[MaxSize]; // 存储元素
    int length;       // 顺序表实际长度
};

template <class T>
void SList<T>::DispList() { // 输出线性表
    cout << "Data:";
    for (int i = 0; i < length; i++)
        cout << data[i] << " ";
    cout << endl;
}

template <class T>
void SList<T>::Insert(int i, T x) { // 插入元素
    if (length >= MaxSize)
        throw "Overflow";
    if (i < 1 || i > length + 1)
        throw "Invalid position";

    for (int j = length; j >= i; j--)
        data[j] = data[j - 1]; // 从i开始后移元素
    data[i - 1] = x; // 在i位置插入元素
    length++; // 长度加1
}

template <class T>
void SList<T>::DispNum() { // 输出所有不能被3整除的数据
    cout << "Data:";
    for (int i = 0; i < length; i++) {
        if (data[i] % 3 != 0)
            cout << data[i] << " ";
    }
    cout << endl;
}

int main() {
    SList<int> A; // 定义元素值为整型的有序表A
    int n, x;
    // 创建从小到大的有序表
    cin >> n; // 输入数据个数n
    while (n--) {
        cin >> x;
        try {
            A.Insert(1, x); // 插入x
        } catch (const char *wrong) {
            cout << wrong << endl;
        }
    }

    A.DispList(); // 输出所有数据
    A.DispNum(); // 输出所有不能被3整除的数据
    return 0;
}
