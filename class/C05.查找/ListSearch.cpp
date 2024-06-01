#include <iostream>
using namespace std;

class List
{
private:
    int *data;  // 用于存放数组元素
    int length; // 数组长度
public:
    List(int len);                           // 构造函数
    ~List();                                 // 析构函数
    void InitList();                         // 初始化数组
    void PrintList();                        // 输出数组
    int BinSearch(int low, int high, int x); // 递归折半查找
    int BinSearch(int x);                    // 非递归折半查找
};

List::List(int len)
{
    length = len;
    data = new int[length];
}

List::~List()
{
    delete[] data;
}

void List::InitList()
{
    for (int i = 0; i < length; i++)
    {
        data[i] = i + 1;
    }
}

void List::PrintList()
{
    for (int i = 0; i < length; i++)
    {
        cout << data[i] << " ";
    }
    cout << endl;
}

// 折半查找函数
int List::BinSearch(int low, int high, int x)
{
    int mid = (low + high) / 2;
    if (low <= high)
    {
        if (data[mid] == x)
            return mid;
        else if (data[mid] < x)
            return BinSearch(mid + 1, high, x);
        else
            return BinSearch(low, mid - 1, x);
    }
    return -1;
}

int List::BinSearch(int x)
{
    int low = 1, high = length;
    int mid = (low + high) / 2;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (x == data[mid])
            return mid;
        else if (x < data[mid])
            high = mid - 1;
        else if (x > data[mid])
            low = mid + 1;
    }
    return 0;
}

int main()
{
    int a[6];                    // 用于存放随机生成的数组元素
    srand(time(0));              // 生成随机种子
    a[1] = rand() % 20;          // 生成第一个元素
    for (int i = 2; i <= 5; i++) // 生成后续元素
    {
        a[i] = a[i - 1] + rand() % 20;
    }

    List list(6);
    list.InitList();
    list.PrintList();
    list.BinSearch(0, 5, 10);
}