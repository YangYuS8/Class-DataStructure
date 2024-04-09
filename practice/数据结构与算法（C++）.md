# 数据结构与算法（C++）

## 1000: 顺序表(1)——插入、查找、逆序

> ### 题目描述
>
> 已知顺序表类的定义如下，实现各个成员函数。主函数中输入数据（以0结束）利用Insert函数依次将数据插入到表的1号位置，利用DispList按照逻辑次序输出表中元素，再输入一个要查找的元素，利用查找函数Locate查找其在表中的位置，最后利用Reverse函数将数据逆序，再利用DispList输出。
>
> ```cpp
> template <class T>
> class SeqList{
> public:
> 	SeqList(); //构造函数，将表置空
> 	~SeqList(){} //析构
>   int Locate(T x); //查找元素x在表中的位置，成功返回x在表中的位置，否则返回0
>   void Insert(int i, T x); //在表的i位置插入元素x
> 	void Reverse(); //逆序表中数据
> 	void DispList();
> private:
>   T data[MaxSize];  //存储元素
> 	int length;       //顺序表实际长度
> };
> ```
>
> ### 输入
>
> 输入样例说明：例如输入数据为：1 2 3 4 5 6 0 3，即将1,2,3,4,5,6插入表中的1号位置，得到逻辑次序为6,5,4,3,2,1的顺序表，3为在表中待查找的数据，3的位置为4。
>
> 输入：1 2 3 4 5 6 0 3
>
> 输出：
>
> ```bash
> The length:6
> The elements:
> 6 5 4 3 2 1 
> Found position:4
> The length:6
> The elements:
> 1 2 3 4 5 6 
> ```
>
> 若查找的数据不存在，则输出：No found，例如下例
>
> 输入：1 2 3 4 5 6 0 9
>
> 输出：
>
> ```bash
> The length:6
> The elements:
> 6 5 4 3 2 1 
> No found
> The length:6
> The elements:
> 1 2 3 4 5 6 
> ```
>
> ### 样例输入
>
> ```bash
> 1 2 3 4 5 6 0 3
> ```
>
> ### 样例输出
>
> ```bash
> The length:6
> The elements:
> 6 5 4 3 2 1 
> Found position:4
> The length:6
> The elements:
> 1 2 3 4 5 6 
> ```

