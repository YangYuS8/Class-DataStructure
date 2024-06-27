// 已知快速排序的部分代码如下，勿改动，请补充实现快速排序函数：void QuickSort(int first,int end);   //quickSort  要求：输出每趟排序结果
#include <iostream>
using namespace std;

const int MaxSize = 100;

class List
{
private:
    int r[MaxSize + 1];
    int n;

public:
    List() { n = 0; }   // empty list
    void InsertR(int k) // 表尾插入
    {
        r[++n] = k;
    }
    void Display();                     // display
    void QuickSort(int first, int end); // quickSort
    void QuickSort()
    {
        QuickSort(1, n);
    }
};

void List::Display()
{
    for (int i = 1; i <= n; i++)
        cout << r[i] << " ";
    cout << "\n";
}

void List::QuickSort(int first, int end)
{
    if (first < end)
    {
        int i = first, j = end;
        int pivot = r[first]; // 选择第一个元素作为枢轴

        while (i < j)
        {
            // 从右向左找到第一个小于枢轴的元素
            while (i < j && r[j] >= pivot)
                j--;
            if (i < j)
                r[i++] = r[j];

            // 从左向右找到第一个大于枢轴的元素
            while (i < j && r[i] <= pivot)
                i++;
            if (i < j)
                r[j--] = r[i];
        }

        r[i] = pivot; // 将枢轴元素放到正确的位置
        Display();    // 输出每趟排序结果

        QuickSort(first, i - 1); // 对左子序列进行递归排序
        QuickSort(i + 1, end);   // 对右子序列进行递归排序
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
    L.QuickSort();
    // L.Display();
    return 0;
}
