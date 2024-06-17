#include <iostream>
#include <string>
using namespace std;

// 二叉树类，实现二叉树的递归算法：三种遍历
template <typename DataType>
struct BiNode // 二叉树的结点结构
{
    DataType data;
    BiNode<DataType> *lchild, *rchild;
};

template <typename DataType>
class BiTree
{
public:
    BiTree();  // 构造函数，初始化一棵二叉树，其前序序列由键盘输入
    ~BiTree(); // 析构函数，释放二叉链表中各结点的存储空间

    void PreOrder(void); // 调用私有的递归函数PerOrder

    void InOrder(void);

    void PostOrder(void);

private:
    BiNode<DataType> *root;               // 指向根结点的头指针
    void Creat(BiNode<DataType> *&bt);    // 被构造函数调用，递归方式生成二叉树
    void Release(BiNode<DataType> *&bt);  // 被析构函数调用
    void PreOrder(BiNode<DataType> *bt);  // 前序遍历二叉树
    void InOrder(BiNode<DataType> *bt);   // 中序遍历二叉树
    void PostOrder(BiNode<DataType> *bt); // 后序遍历二叉树
};

// 定义类中的成员函数

// 构造函数:Creat利用创建二叉树
template <typename DataType>
BiTree<DataType>::BiTree()
{
    Creat(root);
}

// 功    能：递归方法创建一棵二叉树,由构造函数调用
template <typename DataType>
void BiTree<DataType>::Creat(BiNode<DataType> *&bt)
{
    DataType ch;
    cin >> ch;
    if (ch == "#")
        bt = nullptr; // 创建结点值为字符串的二叉树
    else
    {
        bt = new BiNode<DataType>; // 生成一个结点
        bt->data = ch;
        Creat(bt->lchild); // 递归建立左子树
        Creat(bt->rchild); // 递归建立右子树
    }
}
// 功    能：析构函数，释放二叉链表中各结点的存储空间
template <typename DataType>
BiTree<DataType>::~BiTree() // 析构函数不能带参数
{
    Release(root);
}

// 功    能：释放二叉树的存储空间，析构函数调用
template <typename DataType>
void BiTree<DataType>::Release(BiNode<DataType> *&bt)
{
    if (bt != nullptr)
    {
        Release(bt->lchild); // 释放左子树
        Release(bt->rchild); // 释放右子树
        delete bt;
    }
}

template <typename DataType>
void BiTree<DataType>::PreOrder(void)
{
    PreOrder(root);
}

template <typename DataType>
void BiTree<DataType>::InOrder(void)
{
    InOrder(root);
}
template <typename DataType>
void BiTree<DataType>::PostOrder(void)
{
    PostOrder(root);
}

// 请在下面补充实现二叉树的三种递归遍历算法

// 前序遍历递归算法
template <class DataType>
void BiTree<DataType>::PreOrder(BiNode<DataType> *bt)
{
    if (bt == NULL)
        return;
    else
    {
        cout << bt->data << " ";
        PreOrder(bt->lchild);
        PreOrder(bt->rchild);
    }
}

// 中序遍历递归算法
template <class DataType>
void BiTree<DataType>::InOrder(BiNode<DataType> *bt)
{
    if (bt == NULL)
        return;
    else
    {
        InOrder(bt->lchild);
        cout << bt->data << " ";
        InOrder(bt->rchild);
    }
}

// 后序遍历递归算法
template <class DataType>
void BiTree<DataType>::PostOrder(BiNode<DataType> *bt)
{
    if (bt == NULL)
        return;
    else
    {
        PostOrder(bt->lchild);
        PostOrder(bt->rchild);
        cout << bt->data << " ";
    }
}

int main()
{
    BiTree<string> mybit;
    mybit.PreOrder();
    cout << endl;
    mybit.InOrder();
    cout << endl;
    mybit.PostOrder();
    cout << endl;
    return 0;
}