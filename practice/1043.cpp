// 已知希尔排序的部分代码如下，勿改动，请补充实现希尔排序函数，要求输出每趟排序结果，增量序列取值依次为5, 3, 1。
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
    void Display();   // display
    void ShellSort(); // ShellSort
};

void List::Display()
{
    for (int i = 1; i <= n; i++)
        cout << r[i] << " ";
    cout << "\n";
}

void List::ShellSort()
{
    int gaps[] = {5, 3, 1}; // 增量序列
    int numGaps = sizeof(gaps) / sizeof(gaps[0]);

    for (int g = 0; g < numGaps; g++)
    {
        int gap = gaps[g];
        for (int i = gap + 1; i <= n; i++)
        {
            int temp = r[i];
            int j = i;
            while (j > gap && r[j - gap] > temp)
            {
                r[j] = r[j - gap];
                j -= gap;
            }
            r[j] = temp;
        }
        Display(); // 每趟排序后输出结果
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
    L.ShellSort();
    // L.Display();
    return 0;
}
