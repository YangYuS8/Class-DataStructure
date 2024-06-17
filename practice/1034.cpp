/*已知有序顺序表类LinearSearch类，实现折半查找。部分代码如下，勿改动，
请补充Bin_Search和DispList函数。
*/

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
    int Bin_Search(int key); // 查找成功，函数返回key所在数组下标（位置），否则查找失败，返回0
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

// 请在下面补充实现相关算法的C++函数实现
// 输出顺序表
void LinearSearch::DispList()
{
    cout << "Data:";
    for (int i = 1; i <= n; i++)
        cout << r[i] << " ";
    cout << endl;
}

// 折半查找
int LinearSearch::Bin_Search(int key)
{
    int low = 1, high = n, mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (r[mid] == key)
            return mid; // 查找成功，返回下标
        else if (r[mid] < key)
            low = mid + 1; // 在右子表继续查找
        else
            high = mid - 1; // 在左子表继续查找
    }
    return 0; // 查找失败
}

int main()
{
    LinearSearch A; // 空表A
    int x, key;
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
        catch (const char *wrong)
        {
            cout << wrong << endl;
        }
    }
    A.DispList();
    int pos;
    cin >> key;
    pos = A.Bin_Search(key);
    if (!pos) // 查找失败
        cout << "Find " << key << " failure\n";
    else
        cout << "Find " << key << " success,position:" << pos << endl;
    return 0;
}