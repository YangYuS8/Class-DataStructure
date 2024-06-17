/*已知折半查找的部分代码如下，勿改动。请补充实现折半查找算法Bin_Search。
要求：实现方式为递归方法。
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
    void Insert(int x);                         // 有序表的插入，使序列仍有序
    void DispList();                            // 输出表
    int Bin_Search(int key);                    // 调用下面的递归算法
    int Bin_Search(int low, int high, int key); // 递归算法，成功返回位置，否则返回0
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
void LinearSearch::DispList() // 输出表
{
    int i;
    cout << "Data:";
    for (i = 1; i <= n; i++)
    {
        cout << r[i] << " ";
    }
    cout << endl;
}
// 在下面补充实现折半查找算法（两个函数Bin_Search，1个形参和3个形参的各一个）
// 递归实现的折半查找
int LinearSearch::Bin_Search(int key)
{
    return Bin_Search(1, n, key); // 调用私有的递归函数
}

int LinearSearch::Bin_Search(int low, int high, int key)
{
    if (low > high)
        return 0; // 查找失败，返回0
    else
    {
        int mid = (low + high) / 2;
        if (r[mid] == key)
            return mid; // 查找成功，返回位置mid
        else if (r[mid] > key)
            return Bin_Search(low, mid - 1, key); // 在左半部分继续查找
        else
            return Bin_Search(mid + 1, high, key); // 在右半部分继续查找
    }
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
        catch (char *wrong)
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