// 已知有向图采用邻接表存储，部分代码如下，请补充完成计算各个顶点的入度，出度算法。

#include <iostream>
#include <string>
using namespace std;

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
    void CountInD(int ind[]);     // 计算各个顶点的入度,存储在ind中
    void CountOutD(int outd[]);   // 计算各个顶点的出度,存储在outd中
private:
    VertexNode<T> adjlist[MaxSize]; // 存放顶点表的数组
    int vertexNum, arcNum;          // 图的顶点数和边数
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

// 计算各个顶点的入度
template <class T>
void ALGraph<T>::CountInD(int ind[])
{
    // 初始化入度数组
    for (int i = 0; i < vertexNum; i++)
        ind[i] = 0;

    // 遍历邻接表，计算入度
    for (int i = 0; i < vertexNum; i++)
    {
        ArcNode *p = adjlist[i].firstedge;
        while (p != NULL)
        {
            ind[p->adjvex]++;
            p = p->next;
        }
    }
}
// 计算各个顶点的出度
template <class T>
void ALGraph<T>::CountOutD(int outd[])
{
    // 初始化出度数组
    for (int i = 0; i < vertexNum; i++)
        outd[i] = 0;

    // 遍历邻接表，计算出度
    for (int i = 0; i < vertexNum; i++)
    {
        ArcNode *p = adjlist[i].firstedge;
        while (p != NULL)
        {
            outd[i]++;
            p = p->next;
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
    int ind[MaxSize];
    cout << "Indegree:";
    G.CountInD(ind);
    for (i = 0; i < n; i++)
        cout << ind[i] << " "; // 输出各个顶点的入度
    cout << endl;
    int outd[MaxSize];
    cout << "OutDegree:";
    G.CountOutD(outd);
    for (i = 0; i < n; i++)
        cout << outd[i] << " "; // 输出各个顶点的出度
    return 0;
}