#include <iostream>
#include <ctime>
using namespace std;

class List
{
private:
    int *data;  // 用于存放数组元素
    int length; // 数组长度
public:
    List(int a[], int n);                    // 构造函数
    ~List();                                 // 析构函数
    void PrintList();                        // 输出数组
    int ListSearch(int x);                   // 原始查找
    int SentinelSearch(int key);             // 哨兵查找
    int BinSearch(int low, int high, int x); // 递归折半查找
    int BinSearch(int x);                    // 非递归折半查找
};

List::List(int a[], int n)
{
    length = n;
    data = new int[length];
    for (int i = 0; i < length; ++i)
    {
        data[i] = a[i];
    }
}

List::~List()
{
    delete[] data;
}

void List::PrintList()
{
    for (int i = 0; i < length; ++i)
    {
        cout << data[i] << " ";
    }
    cout << endl;
}

// 原始查找
int List::ListSearch(int x)
{
    for (int i = 0; i < length; ++i)
    {
        if (data[i] == x)
        {
            return i + 1; // 返回位置（从1开始）
        }
    }
    return 0; // 找不到返回0
}

// 哨兵查找
int List::SentinelSearch(int key)
{
    int last = data[length - 1];
    data[length - 1] = key;
    int i = 0;
    while (data[i] != key)
    {
        ++i;
    }
    data[length - 1] = last;
    if (i < length - 1 || data[length - 1] == key)
    {
        return i + 1; // 返回位置（从1开始）
    }
    else
    {
        return 0; // 找不到返回0
    }
}

// 递归折半查找
int List::BinSearch(int low, int high, int x)
{
    if (low <= high)
    {
        int mid = (low + high) / 2;
        if (data[mid] == x)
        {
            return mid + 1; // 返回位置（从1开始）
        }
        else if (data[mid] < x)
        {
            return BinSearch(mid + 1, high, x);
        }
        else
        {
            return BinSearch(low, mid - 1, x);
        }
    }
    return 0; // 找不到返回0
}

// 非递归折半查找
int List::BinSearch(int x)
{
    int low = 0, high = length - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (data[mid] == x)
        {
            return mid + 1; // 返回位置（从1开始）
        }
        else if (data[mid] < x)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return 0; // 找不到返回0
}

int main()
{
    int a[5]; // 数据1-5
    srand(time(0));
    a[0] = rand() % 20;
    for (int i = 1; i < 5; ++i)
    {
        a[i] = a[i - 1] + rand() % 20;
    }

    List L(a, 5);
    L.PrintList();

    int x;
    cout << "选择查找方式：" << endl;
    cout << "1. 原始查找" << endl;
    cout << "2. 哨兵查找" << endl;
    cout << "3. 递归的折半查找" << endl;
    cout << "4. 非递归的折半查找" << endl;
    cout << "0. 结束" << endl;

    int choose;
    cin >> choose;

    while (choose != 0)
    {
        cout << "请输入查找数据：";
        cin >> x;

        int result = 0;
        switch (choose)
        {
        case 1:
            result = L.ListSearch(x);
            cout << "原始查找: ";
            break;
        case 2:
            result = L.SentinelSearch(x);
            cout << "哨兵查找: ";
            break;
        case 3:
            result = L.BinSearch(0, 4, x); // 因为数组下标从0开始，所以传入的low是0，high是length-1
            cout << "递归的折半查找: ";
            break;
        case 4:
            result = L.BinSearch(x);
            cout << "非递归的折半查找: ";
            break;
        default:
            break;
        }

        if (result == 0)
        {
            cout << "数据不在表内" << endl;
        }
        else
        {
            cout << "数据在第" << result << "个位置" << endl;
        }

        cout << "选择查找方式：" << endl;
        cout << "1. 原始查找" << endl;
        cout << "2. 哨兵查找" << endl;
        cout << "3. 递归的折半查找" << endl;
        cout << "4. 非递归的折半查找" << endl;
        cout << "0. 结束" << endl;
        cin >> choose;
    }

    return 0;
}
