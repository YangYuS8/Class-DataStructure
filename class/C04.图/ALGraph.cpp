#include <iostream>
#include "CircleQueue.cpp"
using namespace std;
const int Max = 100;
int visited[Max];

struct ArcNode
{
    int adjvertex; // 领接点的下标值
    ArcNode *next;
};

template <class T>
struct VertexNode
{
    T vertex;
    ArcNode *firstedge;
};

template <class T>
class ALGraph
{
private:
    VertexNode<T> adjlist[Max];
    int vertexNum, edgeNum;

public:
    ALGraph(T a[], int vn, int en);
    ~ALGraph() {}
    void DFS(int v);
    void BFS(int v);
};

template <class T>
ALGraph<T>::ALGraph(T a[], int vn, int en)
{
    vertexNum = vn;
    edgeNum = en;
    for (int i = 0; i < vertexNum; i++)
    {
        adjlist[i].vertex = a[i];
        adjlist[i].firstedge = NULL;
    }
    // 邻接表
    int vi, vj;
    cout << "请输入边的两个顶点的序号：";
    for (int p = 0; p < edgeNum; p++)
    {
        cin >> vi >> vj;
        ArcNode *s = new ArcNode;
        s->adjvertex = vj;
        s->next = adjlist[vi].firstedge;
        adjlist[vi].firstedge = s;
        // vi和vj是无向图，所以vj也要指向vi，即vi做成vj的邻接点
        ArcNode *t = new ArcNode;
        t->adjvertex = vi;
        t->next = adjlist[vj].firstedge;
        adjlist[vj].firstedge = t;
    }
}

template <class T>
void ALGraph<T>::DFS(int v)
{
    cout << adjlist[v].vertex << " ";
    visited[v] = 1;
    ArcNode *p = adjlist[v].firstedge;
    while (p != NULL)
    {
        if (visited[p->adjvertex] == 0)
            DFS(p->adjvertex);
        p = p->next;
    }
}

template <class T>
void ALGraph<T>::BFS(int v)
{
    cout << adjlist[v].vertex << " ";
    visited[v] = 1;
    CircleQueue<int> Q;
    ArcNode *p;
    Q.EnQueue(v);
    while (!Q.Empty())
    {
        v = Q.DeQueue();
        p = adjlist[v].firstedge;
        while (p != NULL)
        {
            if (visited[p->adjvertex] == 0)
            {
                cout << adjlist[p->adjvertex].vertex << " ";
                visited[p->adjvertex] = 1;
                Q.EnQueue(p->adjvertex);
            }
            p = p->next;
        }
    }
}

int main()
{
    char a[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    ALGraph<char> G(a, 7, 9);
    cout << "深度优先搜索结果：";
    G.DFS(0);
    cout << endl;
    for (int i = 0; i < 7; i++)
        visited[i] = 0;
    cout << "广度优先搜索结果：";
    G.BFS(0);
    cout << endl;
    return 0;
}