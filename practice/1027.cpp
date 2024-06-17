/*递归算法计算二叉树的叶子个数和高度。请完成如三个算法：

int CountLeaf(BiNode<DataType> *);       //递归算法计算叶子数
int Depth(BiNode<DataType> *);           //递归算法计算高度
BiNode<DataType> *GetRoot();     //获取私有量root的值

部分已知代码如下，请在此基础上补充完善代码：
*/

// 二叉树类，实现计算高度、叶子数
#include <iostream>
#include <string>
using namespace std;

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

    int CountLeaf(BiNode<DataType> *); // 递归方法计算叶子数
    int Depth(BiNode<DataType> *);     // 递归方法计算高度

    BiNode<DataType> *GetRoot(); // 获取私有量root的值

    int CountLeaf(); // 调用上面的递归算法计算叶子

    int Depth(); // 调用上面的递归算法计算高度

private:
    BiNode<DataType> *root;              // 指向根结点的头指针
    void Creat(BiNode<DataType> *&bt);   // 被构造函数调用，递归方式生成二叉树
    void Release(BiNode<DataType> *&bt); // 被析构函数调用
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
int BiTree<DataType>::Depth()
{
    return Depth(root);
}

template <typename DataType>
int BiTree<DataType>::CountLeaf()
{
    return CountLeaf(root);
}

// 请在下面补充相关算法的实现
// 递归算法计算叶子数
template <class DataType>
int BiTree<DataType>::CountLeaf(BiNode<DataType> *bt)
{
    if (bt == nullptr)
        return 0;
    else if (bt->lchild == nullptr && bt->rchild == nullptr)
        return 1;
    return CountLeaf(bt->lchild) + CountLeaf(bt->rchild);
}

// 递归算法计算高度
template <class DataType>
int BiTree<DataType>::Depth(BiNode<DataType> *bt)
{
    if (bt == nullptr)
        return 0;
    else
    {
        int leftDepth = Depth(bt->lchild);
        int rightDepth = Depth(bt->rchild);
        return max(leftDepth, rightDepth) + 1;
    }
}

// 获取私有量root的值
template <class DataType>
BiNode<DataType> *BiTree<DataType>::GetRoot()
{
    return root;
}

int main()
{
    BiTree<string> mybit;
    cout << mybit.CountLeaf() << " " << mybit.Depth() << endl;
    BiNode<string> *broot;
    broot = mybit.GetRoot();
    cout << mybit.CountLeaf(broot) << " " << mybit.Depth(broot) << endl;
    return 0;
}