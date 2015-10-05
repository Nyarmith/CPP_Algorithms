#include <iostream>
#include <string>

template <class T> struct node
{
    node<T>* next;
    T data;
};

template <class T> class list
{
    public:
        list<T>();
        //POST: Default list object constructed with head initialized to null
        
        void insertAtHead(T value);
        //PRE: value is initialized
        //POST: value will be inserted as head to the list

        void insertAtTail(T value);
        //PRE: value is initialized
        //POST: value will be appended as tail to the list

        bool check(T value);
        //PRE: value is initialized
        //POST:return true if number is in this list starting at head, else false

        void spliceList(list<T>* new_list);
        //PRE: new_list is initialized
        //POST: appends new_list, starting at its head, to the end of this list in order

        void returnList();
        //POST: prints the content of this list starting at the head in order
    private:
        node<T>* head;
};
template <class T>
void list<T>::insertAtHead(T value){
    node<T>* temp;

    temp = new node<T>;
    temp -> data = value;
    temp -> next = head;
    head = temp;
}



template <class T>
list<T>::list()
{
    head = NULL;
}

template <class T>
void list<T>::insertAtTail(T value){
    node<T>* temp;
    node<T>* tail;

    tail = head;
    temp = new node<T>;
    temp -> data = value;
    temp -> next = NULL;

    if (tail == NULL)
        tail = temp;
    else
    {
        while(tail -> next != NULL)
        {
            tail = tail -> next;
        }
        tail->next = temp;
    }
}

template <class T>
bool list<T>::check(T number)
{
    node<T>* current = head;

    while(current != NULL)
    {
        if(current -> data == number)
        {
            return true;
        }
        current = current -> next;
    }

    return false;
}

template <class T>
void list<T>::spliceList(list<T>* new_list)
{
    node<T>* tail = head;
    if (head == NULL)
    {
        head = new_list.head;
    }
    else
    {
        while(tail -> next != NULL)
        {
            tail = tail -> next;
        }
        tail -> next = new_list.head;
    }
}

template <class T>
void list<T>::returnList(){
    node<T>* current = head;
    while(current != NULL)
    {
        if (current -> next != NULL)
        {
            std::cout << current -> data << ", ";
            current = current -> next;
        }
        else
        {
            std::cout << current -> data << std::endl;
            current = current -> next;
        }
    }
}

int main(){
    list<int> int_list_test;
    list<int> new_int_list_test;
    int_list_test.insertAtHead(3);
    int_list_test.insertAtHead(4);
    int_list_test.insertAtHead(5);
    int_list_test.insertAtHead(6);
    int_list_test.insertAtHead(2);

    new_int_list_test.insertAtHead(1);
    new_int_list_test.insertAtHead(2);
    new_int_list_test.insertAtHead(3);
    new_int_list_test.insertAtHead(2);
    new_int_list_test.insertAtHead(1);
    new_int_list_test.insertAtHead(1);

    new_int_list_test.returnList();
}

