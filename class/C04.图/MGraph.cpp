#include <iostream>
#include "SeqQueue.cpp"
using namespace std;
const int MaxSize = 100;
int visited[MaxSize];

// DFS
// 1.访问顶点v（输出：Vv,Vv在vertex数组中的下标值）
// 2.找v顶点的未被访问的邻接顶点w，找到后对w进行DFS(递归)
// 把v的所有的w都找到

template <class T>
class MGraph
{
private:
    // 顶点数组
    T vertex[MaxSize];
    // 关系
    int arc[MaxSize][MaxSize];
    int vernum, arcnum; // 元素个数,边的个数

public:
    MGraph(T a[], int vn, int en);
    ~MGraph();
    void DFS(int v); // 深度优先遍历
    void BFS(int v); // 广度优先遍历
};

template <class T>
MGraph<T>::MGraph(T a[], int vn, int en)
{
    // 私有成员的初始化
    vernum = vn;
    arcnum = en;
    // 元素
    for (int k = 0; k < vernum; k++)
        vertex[k] = a[k];
    // 关系：有边的赋值为1,没有边赋值为0
    for (int i = 0; i < vernum; i++)
        for (int j = 0; j < vernum; j++)
            arc[i][j] = 0; // 初始化arc所有位置为0
    int m, n;
    cout << "请输入有边关系的序号对：";
    for (int p = 0; p < arcnum; p +=)
    {
        cin >> m >> n;
        arc[m][n] = 1; // 输入序号对的位置改为1
        arc[n][m] = 1; // 针对无相图
    }
}

template <class T>
void MGraph<T>::DFS(int v)
{
    // 1.访问顶点v（输出：Vv,Vv在vertex数组中的下标值）
    cout << vertex[v] << " ";
    visited[v] = 1;
    // 2.找v顶点的未被访问的邻接顶点w，找到后对w进行DFS(递归)
    for (int w = 0; w < vernum; w++)
    {
        if (visited[w] == 0 && arc[v][w] == 1)
            DFS(w);
        // 把v的所有的w都找到
    }
}

template <class T>
void MGraph<T>::BFS(int v)
{
    SeqQueue<int> Q;   // 采用顺序队列
    cout << vertex[v]; // 用输出V来表示访问顶点V
    visited[v] = 1;    // 表示顶点V已经被访问过
    Q.EnQueue(v);
    while (!Q.Empty())
    {
        v = Q.DeQueue();
        for (int j = 0; j < vernum; j++)
        {
            if (arc[v][j] == 1 && visited[j] == 0)
            {
                cout << vertex[j];
                visited[j] = 1;
                Q.EnQueue(j);
            }
        }
    }
}

int main()
{
}