// 利用邻接矩阵存储结构，完成深度优先遍历和广度优先遍历算法。已知部分代码如下（勿改动），只需完成深度遍历DFSTraverse和广度遍历BFSTraverse即可。

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

// Class MGraph
const int MaxSize = 20; // 图中最多顶点个数

int visited[MaxSize]; // 访问标志数组（0表示未访问，1表示已访问）

template <class T>
class MGraph
{
public:
    MGraph(T a[], int n, int e); // 构造函数，初始化具有n个顶点,e条边的图
    void DispMGraph();           // 输出图中顶点值和矩阵值

    void DFSTraverse(int v); //    从v顶点出发深度优先遍历图（一个连通子图）

    void BFSTraverse(int v); //     从v顶点出发广度优先遍历图（一个连通子图）

private:
    T vertex[MaxSize];         // 存放图中顶点信息的数组
    int arc[MaxSize][MaxSize]; // 存放图中顶点关系（边）的数组
    int vertexNum, arcNum;     // 图的顶点数和边数
    void DFS(int v);           // 递归实现深度优先遍历
};

// 构造一个邻接矩阵存储的无向图
template <class T>
MGraph<T>::MGraph(T a[], int n, int e)
{
    vertexNum = n; // 顶点数
    arcNum = e;    // 边数
    int i, j, k;
    for (i = 0; i < vertexNum; i++)
        vertex[i] = a[i];           // 顶点值
    for (i = 0; i < vertexNum; i++) // 初始化邻接矩阵值为0（顶点间无边）
        for (j = 0; j < vertexNum; j++)
            arc[i][j] = 0;
    for (k = 0; k < arcNum; k++) // 依次输入e条边
    {
        cin >> i >> j; // 输入各条边依附的两个顶点的序号
        arc[i][j] = 1; // 置有边标志
        arc[j][i] = 1;
    }
}

// 输出图中所有顶点信息，和边信息
template <class T>
void MGraph<T>::DispMGraph()
{
    int i, j;
    cout << "  ";
    for (i = 0; i < vertexNum; i++)
        cout << vertex[i] << " "; // 输出图中所有的顶点
    cout << endl;
    for (i = 0; i < vertexNum; i++)
    {
        cout << vertex[i] << " ";
        for (j = 0; j < vertexNum; j++)
            cout << arc[i][j] << " "; // 输出边值（0/1）
        cout << endl;
    }
}

// 在此处实现深度优先遍历算法
// 递归实现深度优先遍历
template <class T>
void MGraph<T>::DFS(int v)
{
    cout << vertex[v] << " ";
    visited[v] = 1;
    for (int j = 0; j < vertexNum; j++)
    {
        if (arc[v][j] == 1 && visited[j] == 0)
        {
            DFS(j);
        }
    }
}

// 从v顶点出发深度优先遍历图（一个连通子图）
template <class T>
void MGraph<T>::DFSTraverse(int v)
{
    for (int i = 0; i < vertexNum; i++)
        visited[i] = 0; // 初始化访问标志数组
    DFS(v);
}

// 在此处实现广度优先遍历算法
// 从v顶点出发广度优先遍历图（一个连通子图）
template <class T>
void MGraph<T>::BFSTraverse(int v)
{
    CirQueue<int> q;
    for (int i = 0; i < vertexNum; i++)
        visited[i] = 0; // 初始化访问标志数组
    cout << vertex[v] << " ";
    visited[v] = 1;
    q.EnQueue(v);
    while (!q.Empty())
    {
        int i = q.DeQueue();
        for (int j = 0; j < vertexNum; j++)
        {
            if (arc[i][j] == 1 && visited[j] == 0)
            {
                cout << vertex[j] << " ";
                visited[j] = 1;
                q.EnQueue(j);
            }
        }
    }
}

int main()
{
    string a[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N"}; // 顶点信息
    int i, n, e;
    cin >> n >> e; // 输入顶点个数和边个数
    MGraph<string> G(a, n, e);
    G.DispMGraph();
    for (i = 0; i < n; i++)
        visited[i] = 0;
    cout << "DFS:";
    G.DFSTraverse(0);
    cout << endl;
    for (i = 0; i < n; i++)
        visited[i] = 0;
    cout << "BFS:";
    G.BFSTraverse(0);
    return 0;
}