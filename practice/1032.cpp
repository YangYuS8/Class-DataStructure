// 已知邻接表存储的无向图的部分代码如下，请补充完成深度优先、广度优先遍历算法。

// graphmain.cpp
#include <iostream>
#include <string>
using namespace std;

// 循环队列类
const int QueueSize = 100; // 循环队列的最大长度
template <class T>         // 定义模板类CirQueue
class CirQueue
{
public:
    CirQueue();        // 构造函数，置空队
    ~CirQueue();       // 析构函数
    void EnQueue(T x); // 将元素x入队
    T DeQueue();       // 将队头元素出队
    T GetQueue();      // 取队头元素（并不删除）
    bool Empty();      // 判断队列是否为空
    bool Full();

private:
    T data[QueueSize]; // 存放队列元素的数组
    int front, rear;   // 队头和队尾指针，分别指向队头元素的前一个位置和队尾元素的位置
};

// 功    能：初始化空队列
template <class T>
CirQueue<T>::CirQueue()
{
    front = rear = 0;
}

// 功    能：销毁队列
template <class T>
CirQueue<T>::~CirQueue()
{
}

// 功    能：元素x入队
template <class T>
void CirQueue<T>::EnQueue(T x)
{
    if (Full())
        throw "Overflow";
    rear = (rear + 1) % QueueSize; // 队尾指针在循环意义下加1
    data[rear] = x;                // 在队尾处插入元素
}

// 功    能：队头元素出队，返回值为出队元素
template <class T>
T CirQueue<T>::DeQueue()
{
    if (Empty())
        throw "Downflow";
    front = (front + 1) % QueueSize; // 队头指针在循环意义下加1
    return data[front];              // 读取并返回出队前的队头元素，注意队头指针
}
// 指向队头元素的前一个位置
// 功    能：获取队头元素
template <class T>
T CirQueue<T>::GetQueue()
{
    int i;
    if (Empty())
        throw "Downflow";
    i = (front + 1) % QueueSize; // 注意不要给队头指针赋值
    return data[i];
}

// 功    能：判断队列是否为空,若空返回true，否则返回false
template <class T>
bool CirQueue<T>::Empty()
{
    return front == rear;
}
// 功   能：判断队列是否满，若满返回true，否则false
template <class T>
bool CirQueue<T>::Full()
{
    return (rear + 1) % QueueSize == front;
}

const int MaxSize = 20; // 顶点个数的最大值
int visited[MaxSize];   // 访问标志数组（0表示未访问，1表示已访问）

// 定义边表结点
struct ArcNode
{
    int adjvex;    // 邻接点的序号
    ArcNode *next; // 指向下一个边结点的指针
};

// 定义顶点表结点
template <class T>
struct VertexNode
{
    T vertex;           // 顶点的名称
    ArcNode *firstedge; // 指向第一个边表结点的头指针
};

// 邻接表类
template <class T>
class ALGraph
{
public:
    ALGraph(T a[], int n, int e); // 构造函数，初始化一个有n个顶点e条边的图
    ~ALGraph();                   // 析构函数，释放邻接表中各边表结点的存储空间
    void DispALGraph();           // 输出邻接表
    int Count();                  // 计算连通分量个数，返回值为连通分量的个数（请大家自己测试）
    void DFSTraverse(int v);      // 深度优先遍历图
    void BFSTraverse(int v);      // 深度优先遍历图
private:
    VertexNode<T> adjlist[MaxSize]; // 存放顶点表的数组
    int vertexNum, arcNum;          // 图的顶点数和边数
    void DFS(int v);                // 递归实现深度优先遍历
};

/*
 *前置条件：图不存在
 *输    入：无
 *功    能：图的初始化
 *输    出：无
 *后置条件：得到一个无向图
 */
template <class T>
ALGraph<T>::ALGraph(T a[], int n, int e)
{
    arcNum = e;    // 边数
    vertexNum = n; // 顶点数
    int i, j;
    for (i = 0; i < vertexNum; i++)
    {
        adjlist[i].vertex = a[i];
        adjlist[i].firstedge = NULL;
    }

    for (int k = 0; k < arcNum; k++) // 依次输入每一条边，并在相应边表中插入结点
    {
        cin >> i >> j; // 输入边所依附的两个顶点的序号
        ArcNode *s = new ArcNode;
        s->adjvex = j;                  // 生成一个边表结点s
        s->next = adjlist[i].firstedge; // 将结点s插入到i号表的头结点之后
        adjlist[i].firstedge = s;
        s = new ArcNode;
        s->adjvex = i;                  // 生成一个边表结点s
        s->next = adjlist[j].firstedge; // 将结点s插入到j号表的头结点之后
        adjlist[j].firstedge = s;
    }
}
/*   前置条件：图已存在
 *   输    入：无
 *   功    能：销毁图
 *   输    出：无
 *   后置条件：释放图所占用的存储空间
 */
template <class T>
ALGraph<T>::~ALGraph()
{
    for (int i = 0; i < vertexNum; i++)
    {
        ArcNode *p = adjlist[i].firstedge;
        while (p != NULL) // 循环删除
        {
            adjlist[i].firstedge = p->next;
            delete p; // 释放结点空间
            p = adjlist[i].firstedge;
        }
    }
}

/*
 *前置条件：图已存在
 *输    入：无
 *功    能：输出图中所有顶点及边的数据信息
 *输    出：图中所有顶点及边的数据信息
 *后置条件：图保持不变
 */
template <class T>
void ALGraph<T>::DispALGraph()
{
    int i;
    ArcNode *p;
    cout << "图的邻接表:\n";
    for (i = 0; i < vertexNum; i++)
    {
        cout << i << " " << adjlist[i].vertex << " "; // 输出图中顶点的序号i及值
        for (p = adjlist[i].firstedge; p; p = p->next)
            cout << p->adjvex << " "; // 输出i号顶点的邻接点的序号
        cout << endl;
    }
}

template <class T>
int ALGraph<T>::Count()
{
    int i, n = 0;

    for (i = 0; i < vertexNum; i++)
        visited[i] = 0;
    for (i = 0; i < vertexNum; i++)
    {
        if (!visited[i])
        {
            n++;
            BFSTraverse(i); // 利用深度优先或广度优先遍历算法均可
        }
    }
    return n;
}

// 在下面完成深度优先、广度优先遍历算法
// 深度优先遍历算法
template <class T>
void ALGraph<T>::DFS(int v)
{
    cout << adjlist[v].vertex << " ";
    visited[v] = 1;
    for (ArcNode *p = adjlist[v].firstedge; p != nullptr; p = p->next)
    {
        if (!visited[p->adjvex])
        {
            DFS(p->adjvex);
        }
    }
}

template <class T>
void ALGraph<T>::DFSTraverse(int v)
{
    for (int i = 0; i < vertexNum; i++)
        visited[i] = 0; // 初始化访问标志数组
    DFS(v);
}

// 广度优先遍历算法
template <class T>
void ALGraph<T>::BFSTraverse(int v)
{
    CirQueue<int> q;
    for (int i = 0; i < vertexNum; i++)
        visited[i] = 0; // 初始化访问标志数组
    cout << adjlist[v].vertex << " ";
    visited[v] = 1;
    q.EnQueue(v);
    while (!q.Empty())
    {
        int u = q.DeQueue();
        for (ArcNode *p = adjlist[u].firstedge; p != nullptr; p = p->next)
        {
            if (!visited[p->adjvex])
            {
                cout << adjlist[p->adjvex].vertex << " ";
                visited[p->adjvex] = 1;
                q.EnQueue(p->adjvex);
            }
        }
    }
}

int main()
{
    string a[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N"}; // 顶点信息
    int i, n, e;
    cin >> n >> e; // 输入顶点个数和边个数
    ALGraph<string> G(a, n, e);
    G.DispALGraph();
    for (i = 0; i < n; i++)
        visited[i] = 0;
    cout << "DFS:";
    G.DFSTraverse(0);
    cout << endl;
    for (i = 0; i < n; i++)
        visited[i] = 0;
    cout << "BFS:";
    G.BFSTraverse(0);

    //  cout<<"\n连通分量个数:";
    // cout<<G.Count()<<endl;
    return 0;
}