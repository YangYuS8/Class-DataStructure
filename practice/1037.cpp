/*已知二叉排序树BiSortTree的部分代码如下，勿改动。
请在此基础上补充实现递归查找算法SearchBST和InsertBST。*/
#include <iostream>
using namespace std;

// BiNode 结构体
template <typename DataType>
struct BiNode
{
    DataType data;           // 数据域
    BiNode *lchild, *rchild; // 左孩子和右孩子指针
};

// BiSortTree 类
template <typename DataType>
class BiSortTree
{
public:
    BiSortTree(DataType r[], int n);                                 // 构造函数
    ~BiSortTree();                                                   // 析构函数
    void InsertBST(BiNode<DataType> *&bt, DataType key);             // 插入key
    BiNode<DataType> *SearchBST(BiNode<DataType> *bt, DataType key); // 查找值为key的结点
    void InOrderBST(BiNode<DataType> *bt);                           // 中序遍历二叉树
    BiNode<DataType> *GetRoot();                                     // 获取root指针

private:
    BiNode<DataType> *root;              // 根指针
    void Release(BiNode<DataType> *&bt); // 释放结点
};

// 构造函数，建立二叉排序树
template <typename DataType>
BiSortTree<DataType>::BiSortTree(DataType r[], int n)
{
    root = nullptr; // 初始化空二叉树
    for (int i = 0; i < n; i++)
    {
        InsertBST(root, r[i]); // 插入每个元素
    }
}

// 析构函数，释放所有结点
template <typename DataType>
BiSortTree<DataType>::~BiSortTree()
{
    Release(root); // 调用Release函数释放内存
}

// 释放结点的存储空间
template <typename DataType>
void BiSortTree<DataType>::Release(BiNode<DataType> *&bt)
{
    if (bt)
    {
        Release(bt->lchild); // 释放左子树
        Release(bt->rchild); // 释放右子树
        delete bt;           // 释放当前结点
        bt = nullptr;        // 避免悬空指针
    }
}

// 获取根指针
template <typename DataType>
BiNode<DataType> *BiSortTree<DataType>::GetRoot()
{
    return root;
}

// 中序遍历二叉树
template <typename DataType>
void BiSortTree<DataType>::InOrderBST(BiNode<DataType> *bt)
{
    if (bt != nullptr)
    {
        InOrderBST(bt->lchild);  // 遍历左子树
        cout << bt->data << " "; // 输出当前结点数据
        InOrderBST(bt->rchild);  // 遍历右子树
    }
}

// 插入元素
template <typename DataType>
void BiSortTree<DataType>::InsertBST(BiNode<DataType> *&bt, DataType key)
{
    if (bt == nullptr)
    {
        bt = new BiNode<DataType>;         // 创建新结点
        bt->data = key;                    // 赋值
        bt->lchild = bt->rchild = nullptr; // 初始化子结点
    }
    else if (key < bt->data)
    {
        InsertBST(bt->lchild, key); // 插入左子树
    }
    else if (key > bt->data)
    {
        InsertBST(bt->rchild, key); // 插入右子树
    }
}

// 查找元素
template <typename DataType>
BiNode<DataType> *BiSortTree<DataType>::SearchBST(BiNode<DataType> *bt, DataType key)
{
    if (bt == nullptr || bt->data == key)
    {
        return bt; // 返回查找到的结点或空指针
    }
    else if (key < bt->data)
    {
        return SearchBST(bt->lchild, key); // 递归查找左子树
    }
    else
    {
        return SearchBST(bt->rchild, key); // 递归查找右子树
    }
}

// 二叉排序树的主函数
int main()
{
    int a[10], n;
    n = 0;
    while (1)
    {
        cin >> a[n];
        if (!a[n])
            break; // 输入数据以0结束
        n++;
    }
    BiSortTree<int> bst(a, n); // 构造二叉排序树
    BiNode<int> *root;
    root = bst.GetRoot();
    cout << "Inorder:";
    bst.InOrderBST(root); // 中序遍历二叉排序树（得到递增有序序列）
    cout << endl;
    int x;
    cin >> x;
    BiNode<int> *s;
    s = bst.SearchBST(root, x);
    if (s == nullptr)
        cout << "Find " << x << " failure";
    else
        cout << "Find " << x << " success";
    cout << endl;
    return 0;
}
