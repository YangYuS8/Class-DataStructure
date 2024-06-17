/*已知有序顺序表类LinearSearch类，计算折半查找等概论成功查找条件下的ASL值。
部分代码如下，勿改动，请补充Bin_Search。*/

#include <iostream>
using namespace std;
const int MaxSize = 100; // 顺序表的最大长度
// 有序表类
class LinearSearch
{
public:
    LinearSearch() { n = 0; }
    ~LinearSearch() {}
    void Insert(int x);      // 有序表的插入，使序列仍有序
    void DispList();         // 输出表
    int Bin_Search(int key); // 返回值为查找key值所需的比较次数
    double ASL_Bin_Search(); // 计算ASL值
private:
    int r[MaxSize + 1]; // 存储元素(r[1]~r[n]存储元素)
    int n;              // 顺序表实际长度
};

// 在有序表中插入元素x，使序列仍有序
void LinearSearch::Insert(int x)
{
    int i;
    if (n >= MaxSize) // 表满不能插入
        throw "Overflow";
    r[0] = x;
    for (i = n; r[i] > x; i--)
        r[i + 1] = r[i]; // 将i位置元素后移
    r[i + 1] = x;        // 在位置i+1插入元素x
    n++;                 // 线性表长度增1
}

// 补充Bin_Search
// 折半查找，返回查找key值所需的比较次数
int LinearSearch::Bin_Search(int key)
{
    int low = 1, high = n, mid;
    int comparisons = 0;
    while (low <= high)
    {
        comparisons++;
        mid = (low + high) / 2;
        if (r[mid] == key)
            return comparisons; // 查找成功，返回比较次数
        else if (r[mid] < key)
            low = mid + 1; // 在右子表继续查找
        else
            high = mid - 1; // 在左子表继续查找
    }
    return comparisons; // 查找失败时返回比较次数
}

// 计算ASL
double LinearSearch::ASL_Bin_Search()
{
    int i, ASL = 0;
    for (i = 1; i <= n; i++)
        ASL += Bin_Search(r[i]); // 累加各个元素所需的比较次数
    return 1.0 * ASL / n;
}

void LinearSearch::DispList()
{ // 输出线性表
    int i;
    cout << "Data:";
    for (i = 1; i <= n; i++)
        cout << r[i] << " ";
    cout << endl;
}

int main()
{
    LinearSearch A; // 空表A
    int x;
    // 利用插入函数创建有序表，以0结束
    while (1)
    {
        cin >> x;
        if (!x)
            break;
        try
        {
            A.Insert(x);
        }
        catch (char *wrong)
        {
            cout << wrong << endl;
        }
    }
    A.DispList();
    double ASL;
    ASL = A.ASL_Bin_Search();
    cout << "ASL:" << ASL << endl;
    return 0;
}