#include<iostream>
using namespace std;

template<class T>
struct Node
{
	T data;
	Node<T> *next;
};

template<class T>
class LinkOueue
{
public:
    LinkOueue();
    ~LinkOueue();
    void EnQueue(T x);
    T DeQueue();
    T GetFront();
    void Print();
    bool Empty();
private:
    Node<T> *front, *rear;
};

template<class T>
LinkOueue<T>::LinkOueue()
{
    front = rear = new Node<T>;
    front->next = NULL;
}

template<class T>
LinkOueue<T>::~LinkOueue()
{
    while(front)
    {
        Node<T> *temp = front;
        front = front->next;
        delete temp;
    }
}
