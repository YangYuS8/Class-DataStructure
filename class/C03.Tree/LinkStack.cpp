#include <iostream>
using namespace std;

template <class T>
struct Node
{
    T data;
    Node<T> *next;
};

template <class T>
class LinkStack
{
public:
    LinkStack() { top = NULL; }
    ~LinkStack();
    void Push(T x);
    T Pop();
    T GetTop();
    void Print();
    bool Empty();

private:
    Node<T> *top;
};
template <class T>
LinkStack<T>::~LinkStack()
{
    while (top)
    {
        Node<T> *temp = top;
        top = top->next;
        delete temp;
    }
}

template <class T>
void LinkStack<T>::Push(T x)
{
    Node<T> *newNode = new Node<T>;
    newNode->data = x;
    newNode->next = top;
    top = newNode;
}

template <class T>
T LinkStack<T>::Pop()
{
    if (Empty())
    {
        cerr << "Stack is empty." << endl;
        exit(1);
    }
    T x = top->data;
    Node<T> *temp = top;
    top = top->next;
    delete temp;
    return x;
}

template <class T>
T LinkStack<T>::GetTop()
{
    if (Empty())
    {
        cerr << "Stack is empty." << endl;
        exit(1);
    }
    return top->data;
}

template <class T>
void LinkStack<T>::Print()
{
    Node<T> *temp = top;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

template <class T>
bool LinkStack<T>::Empty()
{
    return top == NULL;
}