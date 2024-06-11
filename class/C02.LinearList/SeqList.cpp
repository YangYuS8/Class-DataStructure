#include<iostream>
using namespace std;

const int MaxSize = 10;

//类模板

template<class T>
class SeqList
{
private:
	T data[MaxSize];
	int length;//顺序表的长度
public:
	SeqList() {length = 0;}//构造函数
	SeqList(T a[], int n);//构造函数
	~SeqList(){}//析构函数

	//按位插入
	void Insert(int locate, T x);

	//按值插入
	
	//按位删除
	
	//带条件删除
	
	//按值查找
	
	//按位查找

	//输出打印
	void PrintList();
};

template<class T>
SeqList<T>::SeqList(T a[], int n)//构造函数
{
	length = n;
	for (int k = 0; k < length; k++)
	{
		data[k] = a[k];
	}
}

template<class T>
void SeqList<T>::PrintList()
{
	cout << "顺序表的元素为："<<endl;
	for (int k = 0; k < length; k++)
	{
		cout<<data[k]<<" ";
	}
	cout<<endl;
}

template<class T>
void SeqList<T>::Insert(int locate, T x)
{
	//从最后一个元素开始，依次后移
	for (int k = length - 1; k >= locate; k--)
	{
		data[k + 1] = data[k];
	}
}

int main()
{
	int a[5] = {1,2,3,4,5};
	SeqList<int> List(a,5);
	List.PrintList();
	return 0;
}