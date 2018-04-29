#include <iostream>
#include <string>

template <class T> struct node
{
    node<T>* next;
    T data;
};

template <class T> class queue
{
    public:
        queue<T>();
        //POST: Default queue object constructed with top initialized to null

        void push(T value);
        //PRE: value is initialized
        //POST: value will be added to tail of queue

        T pop();
        //PRE: Queue is not empty
        //POST: Front of queue will be removed and returned

    private:
        node<T>* head;
        node<T>* tail;
};

template <class T>
queue<T>::queue()
{
    head = NULL;
    tail = NULL;
}

template <class T>
void queue<T>::push(T value)
{
    node<T>* temp = new node<T>;
    temp -> data = value;

    if (head == NULL)
    {
        head = tail = temp;
        head -> data = value;
        head -> next = NULL;
    }
    else
    {
        tail -> next = temp;
        tail = temp;
    }
}


template <class T>
T queue<T>::pop()
{
    T  temp = head -> data;
    head = head -> next;
    return temp;
}

int main()
{
    queue<int> myQueue;
    myQueue.push(2);
    myQueue.push(4);
    myQueue.push(5);
    myQueue.push(12);

    std::cout<<myQueue.pop()<<std::endl;
    std::cout<<myQueue.pop()<<std::endl;
    std::cout<<myQueue.pop()<<std::endl;
}
