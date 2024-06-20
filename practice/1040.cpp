// 已知Hash表的表长MaxSize为11，Hash函数为HashFunc（k） = k % 11，冲突处理方法为链地址法，部分代码如下，勿改动。请补充完成成员函数HashSearch，该函数的功能是动态查找k，若查找失败，则插入k，并返回查找失败所需的比较次数，若查找成功，返回查找k所需的比较次数。
#include <iostream>
using namespace std;

const int MaxSize = 11; // hash表的表长

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
    void Display();        // display

private:
    Node *ht[MaxSize]; // ht数组用来保留各个链表的头指针
};

// hash function
int LinkHash::HashFunc(int k)
{
    return k % MaxSize; // hash函数，假设为除余法，余数为MaxSize
}

// constructor: initialize an empty hashlist
LinkHash::LinkHash()
{
    for (int i = 0; i < MaxSize; i++)
        ht[i] = nullptr; // empty pointer
}

// display hash table
void LinkHash::Display()
{
    for (int i = 0; i < MaxSize; i++)
    {
        cout << "Hash address:" << i << ",value:";
        Node *p = ht[i];
        while (p != nullptr)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
}

// dynamic search and insert function
int LinkHash::HashSearch(int k)
{
    int addr = HashFunc(k); // 计算哈希地址
    Node *p = ht[addr];     // 指向哈希地址对应链表的头指针
    int count = 0;          // 比较次数

    // 在链表中查找k
    while (p != nullptr)
    {
        count++;
        if (p->data == k)
            return count; // 查找成功，返回比较次数
        p = p->next;
    }

    // 插入新节点到链表头部
    Node *newNode = new Node;
    newNode->data = k;
    newNode->next = ht[addr];
    ht[addr] = newNode;
    return count + 1; // 查找失败插入新元素所需的比较次数
}

// main function
int main()
{
    LinkHash LS;
    int k;
    while (1)
    {
        cin >> k;
        if (!k)
            break;
        try
        {
            LS.HashSearch(k);
        }
        catch (const char *ms)
        {
            cout << ms << endl;
        }
    }
    LS.Display();
    return 0;
}
