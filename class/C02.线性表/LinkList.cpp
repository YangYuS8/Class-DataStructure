#include<iostream>
using namespace std;

//链表结构体定义
template<class T>
struct Node
{
	T data;
	Node<T> *next;
};

template<class T>
class LinkList
{
private:
  Node<T> *first;
public:
  LinkList();
  LinkList(T a[], int n);
  ~LinkList();
  void Print();
  void Insert(int locate, T x);
  void Insert(T x);
  T LocalDelete(int locate);
  // int ValueSearch(T x);
  // T LocateSearch(int locate);
  void Exchange();
};

template<class T>
LinkList<T>::LinkList()	//空表构造
{
	first = new Node<T>;
	first->next = NULL;
}

template<class T>
LinkList<T>::LinkList(T a[], int n)	//有参构造
{
	first = new Node<T>;
	first->next = NULL;
	Node<T> *r;
	for (int i = 0; i < n; i++)
	{
		Node<T> *s = new Node<T>;
		s->data = a[i];
		r->next = s;
		r = s;
	}
	r->next = NULL;
}

template<class T>
LinkList<T>::~LinkList()	//析构函数
{
	Node<T> *p = first, *q = first->next;
	while (q != NULL)
	{
		delete p;
		p = q;
		q = q->next;
	}
	delete p;
}

template<class T>
void LinkList<T>::Print()	//输出链表
{
	Node<T> *p = first->next;
	while (p->next != NULL)
	{
		p = p->next;
		cout << p->data << " ";
	}
	cout << endl;
}

template<class T>
void LinkList<T>::Insert(int locate, T x)	//插入数据
{
	if (locate < 1) throw "位置非法";
	Node<T> *p = first;
	int i = 0;
	while (p!=NULL && i <= locate-1)	//循环向后找locate-1位置
	{
		p = p->next;
		i++;
	}
	if (p == NULL) throw "位置非法";
	Node<T> *s = new Node<T>;
	s->data = x;
	s->next = p->next;
	p->next = s;
}

template<class T>
void LinkList<T>::Insert(T x)	//尾插法插入数据
{
	Node<T> *p = first;
	while (p->next != NULL)
	{
		p = p->next;
	}
	Node<T> *s = new Node<T>;
	s->data = x;
	s->next = p->next;
	p->next = s;
}

template<class T>
T LinkList<T>::LocalDelete(int locate)	//删除数据
{
	if (locate < 1) throw "位置非法";
	Node<T> *p = first;
	int i = 0;
	while (p != NULL && i <= locate - 1)	//循环向后找locate-1位置
	{
		p = p->next;
		i++;
	}
	if (p == NULL) throw "删除位置非法";
	Node<T> *s = p->next;
	p->next = s->next;
	T x = s->data;
	delete s;
	return x;
}

template<class T>
Node<T>* Exchange(Node<T>* first)	//逆置链表
{
  if (first == NULL) {
    return NULL;
  }
  Node<T> *p = first->next;
  if (p == NULL) {
    return first;
  }
  Node<T> *q = p->next;
  while (q != NULL)
  {
    p->next = q->next;
    q->next = first->next;
    first->next = q;
    q = p->next;
  }
  return first;
}

int main()
{	
	int locate, x;
	// srand(time(0));
	int a[5] = { 1, 2, 3, 4, 5 };
	try {
		LinkList<int> L(a, 5);
		L.Print();
		cout<<"请输入要插入的位置和数据：";
		cin >> locate >> x;
		L.Insert(locate, x);
		L.Print();
		cout<<"请输入要删除的位置：";
		cin >> locate;
		cout<<"删除的数据为："<<L.LocalDelete(locate)<<endl;
	}
	catch (const char* ms)
	{
		cout << ms << endl;
	}
}