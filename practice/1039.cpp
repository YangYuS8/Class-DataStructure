// 已知Hash表的表长MaxSize为11，Hash函数为HashFunc（k） = k % 11，冲突处理方法为线性探测法，部分代码如下，勿改动。请补充完成成员函数HashSearch，该函数的功能是动态查找k，若查找失败，则插入k，并返回查找失败所需的比较次数，若查找成功，返回查找k所需的比较次数，若表满，则抛出异常“Overflow”
#include <iostream>
#include <iomanip>
using namespace std;

const int MaxSize = 11; // hash表的表长，即教材中的m

class HashList
{
private:
    int ht[MaxSize]; // hashtable

public:
    int HashFunc(int k);   // hash function
    HashList();            // constructor
    void Display();        // display
    int HashSearch(int k); // dynamic search k
    double HashASL();      // search ASL
};

// hash function
int HashList::HashFunc(int k)
{
    return k % MaxSize; // hash函数，假设为除余法，余数为MaxSize
}

// constructor: initialize an empty hashlist
HashList::HashList()
{
    for (int i = 0; i < MaxSize; i++)
        ht[i] = -1; // -1 is empty
}

// display hash table
void HashList::Display()
{
    for (int i = 0; i < MaxSize; i++)
        cout << ht[i] << " ";
    cout << endl;
}

// calculate the average search length (ASL)
double HashList::HashASL()
{
    double ASL = 0;
    int n = 0;
    for (int i = 0; i < MaxSize; i++)
        if (ht[i] != -1)
        {
            ASL += HashSearch(ht[i]);
            cout << ht[i] << " " << HashSearch(ht[i]) << endl;
            n++;
        }
    double average = ASL / n;
    cout << "ASL=" << fixed << setprecision(5) << average << endl;
    return average;
}

// dynamic search and insert function
int HashList::HashSearch(int k)
{
    int initialPos = HashFunc(k); // 计算初始位置
    int pos = initialPos;         // 当前探测位置
    int count = 0;                // 比较次数

    while (ht[pos] != -1 && ht[pos] != k)
    {
        count++;
        pos = (initialPos + count) % MaxSize; // 线性探测法
        if (pos == initialPos)
            throw "Overflow"; // 表满
    }

    if (ht[pos] == k)
        return count + 1; // 查找成功

    ht[pos] = k;      // 插入新元素
    return count + 1; // 查找失败插入新元素所需的比较次数
}

// main function
int main()
{
    HashList HL;
    // HL.Display();
    while (1)
    {
        int k;
        cin >> k;
        if (!k)
            break;
        try
        {
            HL.HashSearch(k);
        }
        catch (const char *ms)
        {
            cout << ms << endl;
        }
    }
    HL.Display();
    HL.HashASL();
    return 0;
}
