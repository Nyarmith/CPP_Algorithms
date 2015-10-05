#include <iostream>
#include <string>

template <class T> 
struct node
{
    T data;
    //children
    node<T>* left;
    node<T>* right;
};

template <class T> class BST
{
    public:
        BST<T>();
        //POST: Default BST object constructed with root NULL

        BST<T>(int array[], int size);
        //PRE: array[[ is initialized and size>=0
        //POST: default BST object constructe with all values in array
        //in binary seach tree format

        void insert(T value);
        //PRE: value is initialized and not already in tree
        //POST: node with value will be insterted into this tree at proper position

        bool searchBST(T value);
        //PRE: value is initialized

        bool printSearchBST(T value);
        //PRE: value is initialized
        //POST:return true if value is in this BST, else false
        //     prints the search operation

        node<T>* getRoot();
        //POST: Returns root of BST object

    private:
        node<T>* root;

        void insert(T value, node<T>*& tempRoot);
        //PRE: value is initialize and tempRoot is the root of a subtree of a BST
        //POST: a node with key v will be inserted into the subtree of a BST with root tempRoot
        
        bool searchBST(T value, node<T>* tempRoot);
        //PRE: value is initialized and tempRoot is the root of a subtree of a BST
        //POST: Returns true if a node with key v exists in the subtree of tempRoot, otherwise false

        bool printSearchBST(T value, node<T>* tempRoot);
        //PRE: value is initialized and tempRoot is the root of a subtree of a BST
        //POST: Returns true if a node with key v exists in the subtree of tempRoot, otherwise false
        //      also prints search process
};

template <class T>
BST<T>::BST()
{
    root = NULL;
}

template <class T>
BST<T>::BST(int array[], int size)
{
    root = NULL;
    
    for (int i = 0; i < size; i++)
    {
        insert(array[i], root);
    }
}

template <class T>
void BST<T>::insert(T value)
{
    insert(value, root);
}

template <class T>
bool BST<T>::searchBST(T value)
{
    searchBST(value, root);
}

template <class T>
bool BST<T>::printSearchBST(T value)
{
    printSearchBST(value, root);
}

template <class T>
void BST<T>::insert(T value, node<T>*& tempRoot)
{
    if (tempRoot == NULL)
    {
        tempRoot = new node<T>;
        tempRoot -> data = value;
        tempRoot -> left = NULL;
        tempRoot -> right = NULL;
    }
    else if (value < tempRoot -> data)
    {
        insert(value, tempRoot -> left);
    }
    else if (value > tempRoot -> data)
    {
        insert(value, tempRoot -> right);
    }

}

template <class T>
bool BST<T>::searchBST(T value, node<T>* tempRoot)
{
    if (tempRoot == NULL)
        return false;

    if (value < tempRoot -> data)
    {
        return searchBST(value, tempRoot -> left);
    }
    else if (value > tempRoot ->  data)
    {
        return searchBST(value, tempRoot -> right);
    }
    else
        return true;
}

template <class T>
bool BST<T>::printSearchBST(T value, node<T>* tempRoot)
{
    if (tempRoot == NULL)
    {
        std::cout << "\nvalue not present\n";
        return false;
    }

    if (value < tempRoot -> data)
    {
        std::cout << "\nleft";
        return searchBST(value, tempRoot -> left);
    }
    else if (value > tempRoot -> data)
    {
        std::cout << "\nright";
        return searchBST(value, tempRoot -> right);
    }
    else
    {
        std::cout << "\nfound value\n";
        return true;
    }
}

template <class T>
node<T>* BST<T>::getRoot()
{
    return root;
}

int main(){
    BST<int> myTree;

    myTree.insert(3);
    myTree.insert(1);
    myTree.insert(2);
    myTree.insert(5);
    myTree.printSearchBST(2);
    myTree.printSearchBST(5);
    myTree.printSearchBST(3);
}

