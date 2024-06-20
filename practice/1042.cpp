// 已知直接插入排序的部分代码如下，勿改动，请补充实现插入排序函数。要求输出每趟排序结果。
#include <iostream>
using namespace std;

const int MaxSize = 100;

class List
{
private:
    int r[MaxSize + 1]; // 数组下标从1开始
    int n;              // 元素个数

public:
    List() { n = 0; }   // empty list
    void InsertR(int k) // 表尾插入
    {
        r[++n] = k;
    }
    void Display();    // display
    void InsertSort(); // InsertSort
};

// 显示列表内容
void List::Display()
{
    for (int i = 1; i <= n; i++)
        cout << r[i] << " ";
    cout << "\n";
}

// 插入排序算法
void List::InsertSort()
{
    for (int i = 2; i <= n; i++) // 从第二个元素开始，依次向后处理每一个元素
    {
        if (r[i] < r[i - 1]) // 如果当前元素小于前一个元素，则需要插入
        {
            int temp = r[i];              // 保存当前元素
            int j = i - 1;                // 从前一个元素开始比较
            while (j >= 1 && r[j] > temp) // 向前查找插入位置
            {
                r[j + 1] = r[j]; // 将元素向后移动
                j--;
            }
            r[j + 1] = temp; // 插入元素
        }
        Display(); // 输出当前排序结果
    }
}

int main()
{
    List L;
    while (1)
    {
        int k;
        cin >> k;
        if (!k)
            break;
        L.InsertR(k);
    }
    // L.Display();
    L.InsertSort();
    // L.Display();
    return 0;
}
