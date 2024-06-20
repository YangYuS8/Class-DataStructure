// 已知二叉排序树部分代码如下，勿改动。请实现非递归函数InsertBST和SearchBST。
#include <iostream>
using namespace std;

// BiNode 结构体
template <class T>
struct BiNode
{
    T data;
    BiNode *lchild, *rchild;
};

// BiSortTree 类
template <class T>
class BiSortTree
{
public:
    BiSortTree(T r[], int n);     // 建立关键字序列r[0]~r[n-1]的二叉排序树
    ~BiSortTree();                // 析构函数，释放二叉排序树中所有结点
    void InsertBST(BiNode<T> *s); // 插入结点*s
    BiNode<T> *SearchBST(T k);    // 查找值为k的结点，返回值为k所在结点的地址
    void InOrderBST()             // 中序遍历
    {
        InOrderBST(root); // 调用私有中序递归函数
    }

private:
    BiNode<T> *root;                  // 二叉排序树的根指针
    void Release(BiNode<T> *&root);   // 释放内存
    void InOrderBST(BiNode<T> *root); // 中序遍历的递归实现
};

// 构造函数，将r[0]~r[n-1]各个元素依次插入，生成一棵二叉排序树
template <class T>
BiSortTree<T>::BiSortTree(T r[], int n)
{
    root = NULL; // 初始化空二叉树
    for (int i = 0; i < n; i++)
    {
        BiNode<T> *s = new BiNode<T>;
        s->data = r[i];
        s->lchild = s->rchild = NULL;
        InsertBST(s); // 将结点s插入到二叉排序树中
    }
}

// 中序遍历叉排序树,通过中序遍历是否为递增序列来验证构造的二叉排序树是否正确
template <class T>
void BiSortTree<T>::InOrderBST(BiNode<T> *root)
{
    if (root)
    {
        InOrderBST(root->lchild);
        cout << root->data << " ";
        InOrderBST(root->rchild);
    }
}

// 析构函数，调用Release释放内存
template <class T>
BiSortTree<T>::~BiSortTree()
{
    Release(root);
}

// 释放二叉排序树的存储空间，调用析构函数实现
template <class T>
void BiSortTree<T>::Release(BiNode<T> *&root)
{
    if (root)
    {
        Release(root->lchild); // 释放左子树
        Release(root->rchild); // 释放右子树
        delete root;
    }
}

// 插入结点*s（非递归），如果存在相同的值，不插入
template <class T>
void BiSortTree<T>::InsertBST(BiNode<T> *s)
{
    if (!root)
    {
        root = s; // 如果树为空，直接将结点作为根结点
        return;
    }

    BiNode<T> *current = root;
    BiNode<T> *parent = nullptr;

    while (current)
    {
        parent = current;
        if (s->data < current->data)
            current = current->lchild;
        else if (s->data > current->data)
            current = current->rchild;
        else
            return; // 如果找到相同的值，不插入
    }

    if (s->data < parent->data)
        parent->lchild = s;
    else
        parent->rchild = s;
}

// 查找值为k的结点，返回值为k所在结点的地址（非递归）
template <class T>
BiNode<T> *BiSortTree<T>::SearchBST(T k)
{
    BiNode<T> *current = root;
    while (current)
    {
        if (k == current->data)
            return current; // 找到结点，返回地址
        else if (k < current->data)
            current = current->lchild;
        else
            current = current->rchild;
    }
    return nullptr; // 未找到，返回空指针
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
    cout << "Inorder:";
    bst.InOrderBST(); // 中序遍历二叉排序树（得到递增有序序列）
    cout << endl;
    int x;
    cin >> x;
    BiNode<int> *s;
    s = bst.SearchBST(x);
    if (!s)
        cout << "Failure";
    else
        cout << "Success";
    cout << endl;
    return 0;
}
