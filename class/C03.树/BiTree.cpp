#include <iostream>
using namespace std;
template <class T>
struct BiNode
{
    T data;
    BiNode<T> *lchild, *rchild;
};

template <class T>
class BiTree
{
public:
    BiTree();                             // 构造函数
    ~BiTree();                            // 析构函数
    void PreOrder(BiNode<T> *bt);         // 前序遍历
    void InOrder(BiNode<T> *bt);          // 中序遍历
    void PostOrder(BiNode<T> *bt);        // 后序遍历
    BiNode<T> *GetRoot() { return root; } // 返回根节点

    // 扩展函数
    int CountLeaf(BiNode<T> *&bt); // 叶子节点个数
    int Count(BiNode<T> *&bt);     // 节点个数
    int Deep(BiNode<T> *&bt);      // 树的深度

private:
    BiNode<T> *root; // 指向根节点
    // BiNode<T> *Create(BiNode<T> *bt)
    // {
    //     T ch;
    //     cin >> ch;
    //     if (ch == '#')
    //         bt = NULL; // 空树
    //     else
    //     {
    //         bt = new BiNode<T>;
    //         bt->data = ch;
    //         bt->lchild = Create(bt->lchild); // 递归构造左子树
    //         bt->rchild = Create(bt->rchild); // 递归构造右子树
    //     }
    //     return bt;
    // }
    void Create(BiNode<T> *&bt) // 递归构造二叉树
    {
        T ch;
        cin >> ch;
        if (ch == '#')
            bt = NULL; // 空树
        else
        {
            bt = new BiNode<T>; // 创建新节点
            bt->data = ch;
            Create(bt->lchild); // 递归构造左子树
            Create(bt->rchild); // 递归构造右子树
        }
    }
    void Destroy(BiNode<T> *bt) // 递归销毁二叉树
    {
        if (bt == NULL)
            return;
        else
        {
            Destroy(bt->lchild); // 递归销毁左子树
            Destroy(bt->rchild); // 递归销毁右子树
            delete bt;           // 销毁根节点
        }
    }
};

template <class T>
BiTree<T>::BiTree()
{
    // root = Create(root);
    Create(root); // 创建二叉树
}

template <class T>
BiTree<T>::~BiTree()
{
    Destroy(root); // 销毁二叉树
}

template <class T>
// 前序遍历以bt为根的二叉树
void BiTree<T>::PreOrder(BiNode<T> *bt)
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

template <class T>
// 中序遍历
void BiTree<T>::InOrder(BiNode<T> *bt)
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

template <class T>
// 后序遍历
void BiTree<T>::PostOrder(BiNode<T> *bt)
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

template <class T>
int BiTree<T>::CountLeaf(BiNode<T> *&bt)
{
    if (bt == NULL)
        return 0;
    else if (bt->lchild == NULL && bt->rchild == NULL)
        return 1;
    else
        return CountLeaf(bt->lchild) + CountLeaf(bt->rchild);
}

template <class T>
int BiTree<T>::Count(BiNode<T> *&bt)
{
    if (bt == NULL)
        return 0;
    else
        return Count(bt->lchild) + Count(bt->rchild) + 1;
}

template <class T>
int BiTree<T>::Deep(BiNode<T> *&bt)
{
    if (bt == NULL)
        return 0;
    else
    {
        int m = Deep(bt->lchild);
        int n = Deep(bt->rchild);
        return (m > n) ? m + 1 : n + 1;
    }
}
int main()
{
    BiTree<char> tree;
    BiNode<char> *root = tree.GetRoot();
    cout << "前序遍历：";
    tree.PreOrder(root);
    cout << endl;
    cout << "中序遍历：";
    tree.InOrder(root);
    cout << endl;
    cout << "后序遍历：";
    tree.PostOrder(root);
    cout << endl;
    return 0;
}