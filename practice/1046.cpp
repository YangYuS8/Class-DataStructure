// 已知快速排序的部分代码如下，勿改动，请利用栈实现快速排序非递归函数：void QuickSort();   //quickSort
#include <iostream>
#include <stack>
using namespace std;

const int MaxSize = 100;

class List
{
private:
    int r[MaxSize + 1];
    int n;

public:
    List() { n = 0; }   // 空表初始化
    void InsertR(int k) // 表尾插入
    {
        r[++n] = k;
    }
    void Display();            // 显示表内容
    void QuickSort();          // 非递归快速排序
    void Swap(int &a, int &b); // 交换元素
};

void List::Display()
{
    for (int i = 1; i <= n; i++)
        cout << r[i] << " ";
    cout << "\n";
}

void List::Swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void List::QuickSort()
{
    stack<int> stk; // 定义一个栈，用于存储划分子序列的起始和结束位置
    stk.push(1);    // 初始将整个数组的起始位置压入栈
    stk.push(n);

    while (!stk.empty())
    {
        int end = stk.top(); // 弹出栈顶的结束位置
        stk.pop();
        int start = stk.top(); // 弹出栈顶的起始位置
        stk.pop();

        if (start >= end)
        {
            continue; // 子序列长度为0或负数时，跳过
        }

        int pivot = r[end]; // 选择最后一个元素作为枢轴
        int i = start - 1;  // i 是小于等于 pivot 的元素的最右边界

        for (int j = start; j < end; j++)
        {
            if (r[j] <= pivot)
            {
                i++;
                Swap(r[i], r[j]); // 将 r[j] 移动到小于等于 pivot 的部分
            }
        }

        Swap(r[i + 1], r[end]); // 将 pivot 放到正确的位置

        // 分别将左右子序列的起始和结束位置压入栈
        stk.push(start);
        stk.push(i);
        stk.push(i + 2);
        stk.push(end);
    }
}

int main()
{
    List L;
    int k;
    while (1)
    {
        cin >> k;
        if (k == 0)
            break;
        L.InsertR(k);
    }

    L.Display();

    L.QuickSort();

    L.Display();

    return 0;
}
