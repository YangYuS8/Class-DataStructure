// 已知Hash表的表长MaxSize为11，Hash函数为HashFunc（k） = k % 11，冲突处理方法为线性探测法，部分代码如下，勿改动。请补充完成成员函数HashSearch，和函数HashASL，其中函数HashSearch的功能是动态查找k，若查找失败，返回查找失败所需的比较次数，若查找成功，返回查找k所需的比较次数。HashASL的功能是计算等概论查找成功时的ASL值。
#include <iostream>
using namespace std;

const int MaxSize = 11; // maxsize
struct Node
{
    int data;
    Node *next;
};

class LinkHash
{
public:
    LinkHash();            // initialize an empty list
    int HashFunc(int k);   // hash function
    int HashSearch(int k); // dynamic search k
    void Insert(int k);    // insert k into the hash table
    void Display();
    double HashASL();

private:
    Node *ht[MaxSize]; // ht数组用来保留各个链表的头指针
};

// hash function
int LinkHash::HashFunc(int k)
{
    return k % MaxSize; // hash函数，假设为除余法，余数为11
}

// constructor:initialize an empty hashlist
LinkHash::LinkHash()
{
    for (int i = 0; i < MaxSize; i++)
        ht[i] = NULL; // NULL is empty
}

void LinkHash::Display()
{
    for (int i = 0; i < MaxSize; i++)
    {
        cout << "Hash address:" << i << ",value:";
        Node *p;
        for (p = ht[i]; p; p = p->next)
            cout << p->data << " ";
        cout << endl;
    }
}

// 插入k到哈希表
void LinkHash::Insert(int k)
{
    int index = HashFunc(k); // 计算哈希值
    Node *p = ht[index];

    // 检查元素是否已经存在
    while (p != NULL)
    {
        if (p->data == k)
            return; // 元素已经存在，不插入
        p = p->next;
    }

    // 插入新节点
    Node *newNode = new Node;
    newNode->data = k;
    newNode->next = ht[index];
    ht[index] = newNode;
}

// 动态查找k
int LinkHash::HashSearch(int k)
{
    int index = HashFunc(k); // 计算哈希值
    Node *p = ht[index];
    int comparisons = 0;

    while (p != NULL)
    {
        comparisons++;
        if (p->data == k)
            return comparisons; // 找到k，返回比较次数
        p = p->next;
    }
    return comparisons + 1; // 未找到k，返回比较次数
}

// 计算等概率查找成功时的ASL值
double LinkHash::HashASL()
{
    int totalComparisons = 0;
    int elementCount = 0;

    for (int i = 0; i < MaxSize; i++)
    {
        Node *p = ht[i];
        while (p != NULL)
        {
            totalComparisons += HashSearch(p->data); // 计算每个元素的查找次数
            elementCount++;
            p = p->next;
        }
    }

    if (elementCount == 0)
        return 0.0; // 如果哈希表为空，返回0

    return (double)totalComparisons / elementCount; // 计算平均查找长度
}

int main()
{
    LinkHash LS;
    int k;
    while (1)
    {
        cin >> k;
        if (!k)
            break;
        LS.Insert(k); // 插入元素
    }
    LS.Display();
    cout << "ASL=" << LS.HashASL() << endl;
    return 0;
}
