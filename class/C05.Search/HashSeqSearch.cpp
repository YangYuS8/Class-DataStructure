// 未完成的代码，不建议参考
#include <iostream>
using namespace std;

class HashSeqSearch
{
public:
    // 构造函数
    HashSeqSearch(int arr[], int n);
    // 析构函数
    ~HashSeqSearch() {}
    // 插入函数
    void HashInsert(int k);
    // 散列查找函数
    int HashSearch(int k, int m);

private:
    // 散列表
    int HK[10];
    int length = 10;
};

// 构造函数
HashSeqSearch::HashSeqSearch(int arr[], int n)
{
    // 初始化散列表
    for (int i = 0; i < 10; i++)
    {
        HK[i] = -1;
    }

    // 构造散列表
    for (int i = 0; i < n; i++)
    {
        int hk = arr[i] % 10;
        HK[hk] = arr[i];
    }
}

int HashSeqSearch::HashSearch(int k, int m)
{
    // 定义散列函数
    int hk = k % m;
    if (HK[hk] == k)
        return hk;
    else // 有冲突
    {
        // 向后继续找k值
        int i = (hk + 1) % length;
        while (i != hk)
        {
            if (HK[i] == k)
                return i;
            else
                (i++) % length;
        }
        return -1;
    }
}

// 插入过程
void HashSeqSearch::HashInsert(int k)
{
    int hk = k % length;
    if (HK[hk] == -1)
        HK[hk] = k;
    else
    {
        int i = (hk + 1) % length;
        while (i != hk && HK[i] != -1)
            (i++) % length;
        if (i == hk)
            cout << "散列表已满，无法插入" << endl;
        else
            HK[i] = k;
    }
}