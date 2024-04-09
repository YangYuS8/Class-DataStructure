#include <iostream>
using namespace std;

const int MaxSize = 100;

template <class T>
class SeqList {
public:
    SeqList(); //构造函数，将表置空
    ~SeqList(){} //析构
    int Locate(T x); //查找元素x在表中的位置，成功返回x在表中的位置，否则返回0
    void Insert(int i, T x); //在表的i位置插入元素x
    void Reverse(); //逆序表中数据
    void DispList();

private:
    T data[MaxSize];    //存储元素
    int length;              //顺序表实际长度
};

template<class T>
SeqList<T>::SeqList() {
    length = 0;
}

template<class T>
int SeqList<T>::Locate(T x) {
    for (int i = 0; i < length; i++) {
        if (data[i] == x)
            return i + 1; // 返回位置，从1开始计数
    }
    return 0; // 未找到返回0
}

template<class T>
void SeqList<T>::Insert(int i, T x) {
    if (i < 1 || i > length + 1) {
        cout << "Invalid position." << endl;
        return;
    }
    if (length >= MaxSize) {
        cout << "Overflow." << endl;
        return;
    }
    for (int j = length; j >= i; j--) {
        data[j] = data[j - 1];
    }
    data[i - 1] = x;
    length++;
}

template<class T>
void SeqList<T>::Reverse() {
    for (int i = 0; i < length / 2; i++) {
        T temp = data[i];
        data[i] = data[length - i - 1];
        data[length - i - 1] = temp;
    }
}

template<class T>
void SeqList<T>::DispList() {
    cout << "The length:" << length << endl;
    cout << "The elements:" << endl;
    for (int i = 0; i < length; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}

int main() {
    SeqList<int> list;
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
