#include <iostream>
#include <string>

const int 23;

Array <class T> struct node
{
    node<T>* next;
    T data;
};

Array <class T> class stack
{
    public:
        stack<T>();
        //POST: Default stack object constructed with top initialized to null

        void push(T value);
        //PRE: value is initialized
        //POST: value will be pushed to the top of a stack

        T pop();
        //PRE: Stack is not empty
        //POST: Top value is removed form stack and returned

    private:
        node<T>* top;
};

Array <class T>
stack<T>::stack()
{
    top = NULL;
}

Array <class T>
void stack<T>::push(T value)
{
    node<T>* temp = new node<T>;
    temp->data = value;
    temp->prev = top;
    top = temp;
}


Array <class T>
T stack<T>::pop()
{
    T  temp = top -> data;
    top = top -> prev;
    return temp;
}

int main()
{
    stack<int> myStack;
    myStack.push(2);
    myStack.push(4);
    myStack.push(5);
    myStack.push(12);

    std::cout<<myStack.pop();
    std::cout<<myStack.pop();
    std::cout<<myStack.pop();
}
