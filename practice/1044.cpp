// 已知起泡排序的部分代码如下，勿改动，请补充实现起泡排序函数，要求输出每趟排序结果。
// 提示：起泡排序时，当某趟排序时，一次交换也未发生，则该趟排序后，即结束。
#include <iostream>
using namespace std;

const int MaxSize = 100;

class List
{
private:
    int r[MaxSize + 1]; // 存放元素的数组
    int n;              // 元素个数

public:
    List() { n = 0; }                   // 构造函数，初始化为空表
    void InsertR(int k) { r[++n] = k; } // 表尾插入元素
    void Display();                     // 显示数组内容
    void BubbleSort();                  // 起泡排序
};

void List::Display()
{
    for (int i = 1; i <= n; i++)
        cout << r[i] << " ";
    cout << "\n";
}

void List::BubbleSort()
{
    // 外层循环控制趟数，每趟将最大的元素移动到最后
    for (int i = 1; i < n; i++)
    {
        bool swapped = false; // 记录本趟是否发生交换

        // 内层循环进行相邻元素的比较与交换
        for (int j = 1; j <= n - i; j++)
        {
            if (r[j] > r[j + 1])
            {
                // 交换 r[j] 和 r[j+1]
                int temp = r[j];
                r[j] = r[j + 1];
                r[j + 1] = temp;
                swapped = true; // 发生了交换
            }
        }

        // 输出本趟排序后的结果
        Display();

        // 如果本趟没有发生交换，则排序提前结束
        if (!swapped)
            break;
    }
}

int main()
{
    List L;

    // 输入待排序的元素，以 0 结束输入
    int k;
    while (cin >> k && k != 0)
    {
        L.InsertR(k);
    }

    // 调用起泡排序函数，并输出每趟排序后的结果
    L.BubbleSort();

    return 0;
}
